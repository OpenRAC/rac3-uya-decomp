#!/usr/bin/env python3
"""gen_asm_func.py: draft an inline-asm C function from its retail assembly.

For a leaf function that was assembly in the original (VU0 vector math, EE
128-bit MMI code), the matching C is one __asm__ block holding retail's own
instructions. This transcribes them, decoding the raw `.word` lines that
tools/fix_quadword_ops.py wrote back into real lqc2/sqc2/lq/sq instructions,
and reuses the function's existing `extern` prototype from the sources when
there is one.

    python tools/gen_asm_func.py scratch func_003886B0 func_00388B40 ...
    NOREORDER=1 python tools/gen_asm_func.py scratch func_X   # see below

Then test each file with tools/try_func.py, and also with `--as ps2as`:
gcc ends the function with its own `j $31`, and the default assembler moves
the block's last instruction into that delay slot while Ps2EeAs does not, so
which one matches depends on what retail has there.

NOREORDER=1 wraps the whole block in `.set noreorder` and appends a nop. It is
rarely what retail has; try the default first.

It prints `skip <name>` for anything it will not touch: a function that
references a symbol (those need real C), or one whose `jr $ra` is not the
normal one at the end.
"""
# Generate inline-asm C for leaf asm functions. usage: gen.py OUTDIR func...
import re,sys,os
import os.path
S=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))+'/'
import sys as _sys, os as _os
_sys.path.insert(0, _os.path.join(S, 'tools'))
import srcfiles
text=srcfiles.read_all(S.rstrip('/'))
RN=['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
def dec(w):
    op=w>>26; rs=(w>>21)&31; rt=(w>>16)&31; imm=w&0xFFFF
    if imm&0x8000: imm-=0x10000
    if op==0x36: return 'lqc2 $vf%d, %d($%d)'%(rt,imm,rs)
    if op==0x3E: return 'sqc2 $vf%d, %d($%d)'%(rt,imm,rs)
    if op==0x1E: return 'lq $%d, %d($%d)'%(rt,imm,rs)
    if op==0x1F: return 'sq $%d, %d($%d)'%(rt,imm,rs)
    return None
def gen(n):
    s=open(S+'asm/nonmatchings/text/%s.s'%n).read()
    body=s.split('glabel %s'%n)[1].split('endlabel')[0]
    lines=[]
    for l in body.splitlines():
        st=l.strip()
        if not st or st.startswith('.align'): continue
        m=re.match(r'\.L([0-9A-F]+):',st)
        if m: lines.append(('lab','.L%s_%s:'%(m.group(1),n[5:]))); continue
        m=re.match(r'\.word\s+(0x[0-9A-Fa-f]+|func_0)',st)
        if m:
            w=0 if m.group(1)=='func_0' else int(m.group(1),16)
            d=dec(w)
            lines.append(('i',d if d else '.word 0x%08X'%w)); continue
        m=re.search(r'\*/\s+(.*)',l)
        if m:
            ins=re.sub(r'\s+',' ',m.group(1).split('/*')[0].split('#')[0].strip())
            ins=re.sub(r'\.L([0-9A-F]+)',lambda x:'.L%s_%s'%(x.group(1),n[5:]),ins)
            ins=re.sub(r'\((0x[0-9A-F]+) >> 16\)',lambda x:hex(int(x.group(1),16)>>16),ins)
            ins=re.sub(r'\((0x[0-9A-F]+) & 0xFFFF\)',lambda x:hex(int(x.group(1),16)&0xFFFF),ins)
            if '%hi(' in ins or '%lo(' in ins or 'func_' in ins or 'D_' in ins: return None
            lines.append(('i',ins)); continue
        return None
    # find final jr $31
    idx=[i for i,(k,v) in enumerate(lines) if v in('jr $31','jr $ra')]
    if not idx or idx[-1] not in (len(lines)-2,len(lines)-3): return None
    j=idx[-1]
    rest=lines[j+1:]
    slot=rest[0][1] if rest else 'nop'
    pre=lines[:j]
    seq=[v for k,v in pre]+([slot] if slot!='nop' else [])
    if os.environ.get('NOREORDER'):
        # ee-as in reorder mode moves the last instruction into gcc's `j $31`
        # delay slot. Retail sometimes has `jr $ra; nop` instead, so this
        # variant keeps the whole block in order.
        seq=['.set noreorder']+seq+['nop','.set reorder']
    else:
        labs=[i for i,x in enumerate(seq) if x.endswith(':')]
        if labs:
            L=labs[-1]
            seq=['.set noreorder']+seq[:L+1]+['.set reorder']+seq[L+1:]
    # trailing nops after delay slot are alignment
    return seq
def proto(n):
    m=re.search(r'^extern\s+([^;()]*?)\b%s\s*\(([^)]*)\)\s*;'%n,text,re.M)
    if m: return m.group(1).strip(), m.group(2).strip()
    return 'void','void'
out=sys.argv[1]; os.makedirs(out,exist_ok=True)
for n in sys.argv[2:]:
    seq=gen(n)
    if not seq: print('skip',n); continue
    ret,args=proto(n)
    params=[]
    if args and args!='void':
        for i,a in enumerate(args.split(',')):
            a=a.strip()
            params.append(a if re.search(r'\w\s*$',a) and len(a.split())>1 and not a.endswith('*') and a.split()[-1] not in('s32','u32','f32','void','u8','s16','u16','s8') else a+' p%d'%i)
    sig='%s %s(%s)'%(ret,n,', '.join(params) if params else 'void')
    asm='\n'.join('        "%s\\n"'%x for x in seq)
    open(os.path.join(out,n+'.c'),'w').write('%s {\n    __asm__ __volatile__(\n%s\n    );\n}\n'%(sig,asm))
