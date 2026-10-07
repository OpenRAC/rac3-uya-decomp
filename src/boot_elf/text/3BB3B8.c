#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BBA90(s32);
extern s32 func_12C908(s32);
extern void func_003A0A20(u8 *, u32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_13B620(void);
void func_003A0A20(u8 *, u32);
extern s32 func_003BD798();
extern void func_003BB8B0();
extern void func_003BB870(s32);
extern void func_003A0A20();
extern void func_003BB3B8(void);
extern void func_003BB3C8(s32);
extern void func_003BB4D0(s32);
extern s32 func_003BB688(s32);
extern void func_003BB460(void);
extern s32 func_003BB3F8(u32);
extern s32 func_003BB3E0(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003BB3B8 */
extern s32 D_0037FAD4[];
 
void func_003BB3B8(void) {
    D_0037FAD4[0] = 7;
}
/* localdecomp:end func_003BB3B8 */

/* localdecomp:start func_003BB3C8 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037FA60;

void func_003BB3C8(s32 arg_a0) {
    D_0037FA60.field_74 = 1;
    D_0037FA60.field_78 = arg_a0;
}
/* localdecomp:end func_003BB3C8 */

/* localdecomp:start func_003BB3E0 */
extern s32 D_0037FAD4[];
s32 func_003BB3E0(s32 a0) {
    return D_0037FAD4[0] == a0;
}
/* localdecomp:end func_003BB3E0 */

/* localdecomp:start func_003BB3F8 */
s32 func_003BB3F8(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037FA60)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003BB3F8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB420);

/* localdecomp:start func_003BB428 */
extern s8 D_001D8C20[1];
s32 func_003BB428(s32 i) {
    if (i >= 60) return -1;
    return D_001D8C20[i];
}
/* localdecomp:end func_003BB428 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB450);

/* localdecomp:start func_003BB460 */
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037FA60_003BB460[];
extern u8 D_002D0040[];
extern void func_0038CEA0();
void func_003BB460(void) {
    s32 i;
    u8 *p = D_002D0040;
    for (i = 0; i < 4; i++) { u8 *q = p + i * 0x800; D_0037FA60_003BB460[0].buf[i] = q; func_0038CEA0(q, 0, 0x800); }
}
/* localdecomp:end func_003BB460 */

/* localdecomp:start func_003BB4D0 */
typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA230_003BB4D0[1];
extern u8 D_001D5BDC;
extern u8 D_00281040[];
void func_003BB4D0(s32 arg) {
    s32 A, B, C, D, i, e;
    u32 p = (u32)D_00281040;
    u32 q = 0;
    if (D_001D5BDC != 0) {
        A = 0; B = 0; C = 1; D = 0;
    } else if (arg == 0) {
        A = 1; B = 1; C = 0; D = 0;
    } else {
        A = 3; B = 1; C = 2; D = 1;
    }
    i = 0;
    e = A;
    for (; i < e; i++) {
        D_001DA230_003BB4D0[i].a = p;
        D_001DA230_003BB4D0[i].b = 0;
        p += 0x12C00;
    }
    e += B;
    for (; i < e; i++) {
        D_001DA230_003BB4D0[i].a = q;
        D_001DA230_003BB4D0[i].b = 0;
        q += 0x12C00;
    }
    e += C;
    for (; i < e; i++) {
        D_001DA230_003BB4D0[i].a = p;
        D_001DA230_003BB4D0[i].b = 1;
        p += 0x4F000;
    }
    e += D;
    for (; i < e; i++) {
        D_001DA230_003BB4D0[i].a = q;
        D_001DA230_003BB4D0[i].b = 1;
        q += 0x4F000;
    }
    for (; i < 7; i++) {
        D_001DA230_003BB4D0[i].b = 0;
        D_001DA230_003BB4D0[i].a = 0;
    }
}
/* localdecomp:end func_003BB4D0 */

/* localdecomp:start func_003BB688 */
extern void *D_001DA230[];
extern u32 D_001DA234[];
extern s32 func_003BB810(s32);
extern void func_0038CEA0();

s32 func_003BB688(s32 mode) {
    register u32 *flags_base __asm__("$8") = D_001DA234;
    register s32 index __asm__("$6") = 0;
    register void **pointer __asm__("$16") = D_001DA230;
    register u32 *flags __asm__("$7") = flags_base;

    do {
        register u32 check_state __asm__("$2");
        register u32 entry_state __asm__("$3");
        register u32 updated_state __asm__("$2");
        register u32 *selected_flags __asm__("$5");
        register s32 offset __asm__("$3") = index << 3;

        if (mode != 0) {
            check_state = *(u8 *)flags ^ 1;
        } else {
            check_state = *flags;
        }
        if ((check_state & 1) == 0 && *pointer != 0) {
            selected_flags = (u32 *)((u8 *)offset + (s32)flags_base);
            entry_state = *selected_flags;
            if ((entry_state & 2) == 0) {
                updated_state = entry_state | 2;
                *selected_flags = updated_state;
                func_0038CEA0(*pointer, 0xDEADBEEF, func_003BB810((s32)*pointer));
                return (s32)*pointer;
            }
        }
        index++;
        pointer = (void **)((u8 *)pointer + 8);
        flags += 2;
    } while (index < 7);
    return 0;
}
/* localdecomp:end func_003BB688 */

/* localdecomp:start func_003BB748 */
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
/* 8-byte (small) aliases: Ps2EeAs builds each address with one adjacent lui/addiu, as retail. */
extern E_3B5F88 D_001DA230_003BB748[1];
extern s32 D_001DA234_003BB748[2];
extern s32 D_001DA234_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB748[];
extern void func_003A2818();
s32 func_003BB748(s32 id) {
    s32 i;
    s32 fb = (s32)D_001DA234_003BB748;
    for (i = 0; i < 7; i++) {
        if (D_001DA230_003BB748[i].id == id) {
            s32 *t = D_001DA234_003B5F88b;
            s32 f = *(s32 *)(fb + i * 8);
            if (f & 2) {
                if (f & 4) {
                    *(s32 *)(fb + i * 8) = f ^ 4;
                    if (D_1CCFD0_003BB748->f4 != 0) func_003A2818();
                }
                t[i * 2] &= ~2;
                return 0;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BB748 */

/* localdecomp:start func_003BB810 */
extern s32 D_001DA230_003BB810[];
extern s32 D_001DA234_003BB810[];
s32 func_003BB810(s32 arg0) {
    s32 i = 0;
    s32 c1 = 0x4F000;
    s32 *q = D_001DA234_003BB810;
    s32 *p = D_001DA230_003BB810;
    do {
        i++;
        if (p[0] == arg0) return (q[0] & 1) ? c1 : 0x12C00;
        q += 2;
        p += 2;
    } while (i < 7);
    return -1;
}
/* localdecomp:end func_003BB810 */

/* localdecomp:start func_003BB870 */
extern f32 D_001D8C5C;
extern s32 func_0038DF00(f32, s32, s32);
extern s32 func_003E7FC8(s32, s32);
void func_003BB870(s32 a) {
    func_003E7FC8(a, ((s32 (*)(s32, s32, f32))func_0038DF00)(0x20000000, 0x402299DE, D_001D8C5C));
}
/* localdecomp:end func_003BB870 */

/* localdecomp:start func_003BB8B0 */
__asm__(".extern D_001D8C60, 4");
__asm__(".extern D_001D8C5C, 4");
extern f32 D_001D8C60;
extern f32 D_001D8C5C;
void func_003BB8B0(void) {
    f32 x, a;
    D_001D8C5C += D_001D8C60 * 0.05f; a = D_001D8C60;
    if (D_001D8C5C > 1.0f || D_001D8C5C < 0.0f) a = -a;
    D_001D8C60 = a;
    x = (D_001D8C5C > 1.0f) ? 1.0f : D_001D8C5C;
    D_001D8C5C = x;
    { f32 z = 0.0f; if (!(x < z)) z = x; D_001D8C5C = z; }
}
/* localdecomp:end func_003BB8B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB950);

/* localdecomp:start func_003BB958 */
s32 func_003BB958(void) {
    return 0;
}
/* localdecomp:end func_003BB958 */

/* localdecomp:start func_003BB960 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FAE8[];
extern s32 D_0037FAF4[];
extern char D_001D8C70[];
extern char D_001D8C78[];
extern s32 func_003823F0();
extern void func_11B2E8();
char *func_003BB960(char *buf, s32 n) {
    s32 r;
    s32 x;
    s32 y;
    char *fmt2;
    char *fmt;
    switch (n) {
    case 2:
    case 5:
    case 10:
    case 23:
    case 24:
    case 25:
    case 26:
        r = 0;
        break;
    default:
        r = 1;
        break;
    }
    if (r != 0) {
        fmt = D_001D8C70;
        x = func_003823F0(0xE2);
        y = func_003823F0(n > 0 ? D_0037FAE8[n % 60].f4 : D_0037FAF4[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C78;
        y = func_003823F0(n > 0 ? D_0037FAE8[n % 60].f4 : D_0037FAF4[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003BB960 */

/* localdecomp:start func_003BBA90 */
extern u8 D_001D8CE0;
void func_003BBA90(s32 a) {
    D_001D8CE0 = a;
}
/* localdecomp:end func_003BBA90 */

/* localdecomp:start func_003BBA98 */
extern s32 D_001D8D1C;
s32 func_003BBA98(void) {
    return D_001D8D1C;
}
/* localdecomp:end func_003BBA98 */

/* localdecomp:start func_003BBAA0 */
extern s32 D_001D8D18;
s32 func_003BBAA0(void) {
    return D_001D8D18;
}
/* localdecomp:end func_003BBAA0 */

/* localdecomp:start func_003BBAA8 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A57B0();
extern void func_11F0A0();
void func_003BBAA8(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A57B0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003BBAA8 */

/* localdecomp:start func_003BBB18 */
void func_003BBB18(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003BBB18 */

/* localdecomp:start func_003BBB28 */
__asm__(".extern D_001D8D10_003BBB28, 4");
extern s32 D_001D8D10_003BBB28;
extern s32 D_001DA270_003BBB28[1];
extern s32 D_001DA298_003BBB28[1];
extern s32 D_001DA2C0_003BBB28[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBB28();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_003BBB18();

void func_003BBB28(s32 a) {
    s32 i;
    s32 *p;
    if (a >= 0 && a < D_001D8D10_003BBB28) {
        i = D_001DA298_003BBB28[a] * 4;
        p = (s32 *)((u8 *)D_001DA2C0_003BBB28 + i);
        *p = -1;
        func_13CA20();
        func_13C0B8(*(s32 *)((u8 *)D_001DA270_003BBB28 + i), 0, 0x400, 0, 0, 0, func_003BBB18, (long)p);
        func_13CA28();
        func_13B620_003BBB28();
    }
}
/* localdecomp:end func_003BBB28 */

/* localdecomp:start func_003BBBD0 */
extern int D_001D8D10_003BBBD0;
extern int D_001DA298[];
extern int D_001DA2C0[];
extern void func_13C230(int, int, int);

void func_003BBBD0(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8D10_003BBBD0) {
        offset = index * 4;
        __asm__ volatile("" : "+r"(offset));
        indices = D_001DA298;
        offset += (int)indices;
        __asm__ volatile("" : "+r"(offset));
        sounds = D_001DA2C0;
        __asm__ volatile("" : "+r"(sounds));
        sound = sounds[*(int *)offset];
        invalid = -1;
        if (sound != invalid) {
            func_13C230(sound, (int)(volume * 1024.0f), 0);
        }
    }
}
/* localdecomp:end func_003BBBD0 */

/* localdecomp:start func_003BBC48 */
extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8D10;
extern s32 D_001DA274[];
extern s32 D_001D4B4C[];
void func_003BBC48(void) {
    u32 i;
    s32 r;
    func_0013CA20();
    for (i = 1; i < D_001D8D10; i++) {
        func_0013BF00(D_001DA274[i - 1]);
    }
    func_0013CA28();
    do { r = func_0013B620(); __asm__ volatile("nop
	nop
	nop"); } while (r);
    func_0013BED0();
    D_001D4B4C[0] = 0;
}
/* localdecomp:end func_003BBC48 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BBCE8);

/* localdecomp:start func_003BC6E8 */
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_00227618_003BC6E8[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001DA298_003BC6E8[2];
extern s32 D_001DA2C0_003BC6E8[2];
extern s32 D_001DA270_003BC6E8[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_003BBAA8();
extern void func_11F0A0();
extern void func_13BED0();
void func_003BC6E8(s32 n, s32 *list) {
    s32 local[12];
    B_3B6F28 *base;
    u8 *e;
    s32 i;
    s32 *pa, *pb;
    s32 *idx;
    s32 *lp;
    s32 m;
    m = -1;
    base = D_00227618_003BC6E8[0];
    e = (u8 *)base + base->f8;
    idx = D_001DA298_003BC6E8;
    pb = D_001DA2C0_003BC6E8;
    pa = idx;
    for (i = 9; i >= 0; i--) {
        *pa++ = m;
        *pb++ = m;
    }
    if (list == 0) {
        for (i = 0; i < n; i++) local[i] = i;
        list = local;
    }
    D_001A30B0.fA4 = 0xFFFFFFFFU;
    if (n > 0) {
        u8 *e18 = e + 0x18;
        A_3B6F28 *t = (A_3B6F28 *)base->tbl;
        s32 c = 0xC000;
        lp = list;
        i = n;
        do {
            u8 *q = e18 + t->a[*lp++];
            *(s32 *)(q + 0x2C) = c;
            *(s32 *)(q + 0x28) = c;
        } while (--i);
    }
    func_11F0A0(0);
    for (i = 0; i < n; i++) {
        s32 k = list[i];
        idx[k] = i;
        func_003BBAA8(e + base->tbl[k], &D_001DA270_003BC6E8[i]);
    }
    func_13BED0();
}
/* localdecomp:end func_003BC6E8 */

/* localdecomp:start func_003BC868 */
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_00227618[];
extern s32 D_00380078[];
extern void func_11F0A0();
void func_003BC868(s32 a, s32 *out, s32 c) {
    u8 *base;
    s32 n;
    s32 *tbl;
    s32 idx;
    base = (u8 *)D_00227618[0] + D_00227618[0]->fC;
    n = *(s32 *)base;
    tbl = (s32 *)(base + 0x10);
    if (a < 0x1E && (idx = D_00380078[a]) != -1 && idx < n && tbl[idx] != 0) {
    } else {
        a = 0;
    }
    func_11F0A0(0);
    *out = ((s32 (*)(u8 *, u32))func_003A0A20)(base + tbl[D_00380078[a]], c);
    func_11F0A0(0);
}
/* localdecomp:end func_003BC868 */

/* localdecomp:start func_003BC950 */
extern unsigned long func_0039AF70(s32);
void func_003BC950(s32 a, unsigned long *out) {
    *out = func_0039AF70(a);
}
/* localdecomp:end func_003BC950 */

/* localdecomp:start func_003BC978 */
typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00225780_003BC978;
extern S_227600_3B71B8 D_00227600;
extern s32 D_001DA0D8;
extern void func_0038CEA0();
void func_003BC978(s32 a) {
    H_3B71B8 *h;
    u8 *e;
    E_3B71B8 *p;
    s32 i;
    s32 b;
    S_227600_3B71B8 *s;
    func_0038CEA0(&D_00225780_003BC978, 0, 0x1E0);
    s = &D_00227600;
    D_00225780_003BC978.f68 = s->fC + D_001DA0D8;
    D_00225780_003BC978.f6C = s->f10 + D_001DA0D8;
    h = s->f18;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_3B71B8 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00225780_003BC978.f90[i] = b + p->off;
    }
}
/* localdecomp:end func_003BC978 */

/* localdecomp:start func_003BCA48 */
extern void func_003C2B20(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_00225780;
void func_003BCA48(void) {
    s32 i;
    for (i = 0; i < D_00225780.n; i++) {
        O_B7288 *o = D_00225780.slot[i];
        if (o != 0) {
            o->in->c--;
            *(s32 *)((u8 *)o->in + (o->in->c << 2) + 0x48) = 0;
            func_003C2B20((s32)o);
            D_00225780.slot[i] = 0;
        }
    }
}
/* localdecomp:end func_003BCA48 */

/* localdecomp:start func_003BCAE0 */
extern void func_003865A8(void);
extern void func_003C3060(void);
extern void func_00388320(void);
extern void func_003BCB38(void);
extern void func_00392A08(void);
extern s32 D_001D9D9C;
extern void (*D_001D8CF0)(void);
void func_003BCAE0(void) {
    void (*fn)(void);
    func_003865A8();
    func_003C3060();
    func_00388320();
    fn = D_001D8CF0;
    D_001D9D9C = -1;
    if (fn != 0) fn();
    func_003BCB38();
    func_00392A08();
}
/* localdecomp:end func_003BCAE0 */

/* localdecomp:start func_003BCB38 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
__asm__(".extern D_001D8D20, 4");
extern S_142430_3B7378 D_142430_003BCB38;
extern s32 D_001D9A24;
extern s32 D_001D4BC4;
extern s32 D_001D9C48;
extern f32 D_001D8D20;
extern void func_003895C8(s32);
extern void func_003A96B0(s32, unsigned long);
extern long func_00389920(s32);
extern void func_0038B7F8(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397930(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_003896F8(void);
extern void func_0038B148(s32, s32, s32, s32);
void func_003BCB38(void) {
    f32 c, b, a;
    if ((u32)(D_142430_003BCB38.f15C - 15) < 2 || D_142430_003BCB38.f164 == 15 || D_001D9A24 != 0) {
        c = 272.0f;
        func_003895C8(1);
        func_003A96B0(0x42, 0x8000000044UL);
        func_003A96B0(0x47, (unsigned long)0x3004B);
        func_0038B7F8(0x2C, D_001D4BC4 - 0x60, 0x40, 0x40, 0, 0, 0x40, 0x40, 0x80808080UL, func_00389920(3));
        b = (f32)((D_001D4BC4 - 0x40) << 4);
        a = (f32)(D_001D9C48 % 55) * -6.2831855f / 55.0f;
        func_00397930(1216.0f, b, c, c, a, 0x40, 0x40, func_00389920(4));
        func_003896F8();
        if ((u32)(D_142430_003BCB38.f15C - 15) < 2 || D_142430_003BCB38.f164 == 15) D_001D9A24 = 30;
        else D_001D9A24 = D_001D9A24 - 1;
    }
    func_003A96B0(0x42, 0x8000000044UL);
    func_0038B148(0, 0, 0, (s32)(D_001D8D20 * 128.0f));
}
/* localdecomp:end func_003BCB38 */

/* localdecomp:start func_003BCD28 */
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCD28;
__asm__(".extern D_001D8CE8, 4");
__asm__(".extern D_001D8D04, 4");
__asm__(".extern D_001D8CEC, 4");
extern s32 (*D_001D8CE8)();
extern s32 D_001D8D04;
extern void (*D_001D8CEC)(s32);
extern s32 D_001D5B94;
extern s32 D_001D9D80;
extern void func_003CD2A8();
extern void func_003CD5A0();
s32 func_003BCD28(s32 a) {
    s32 r;
    D_001D5B94 = 6;
    D_16C580_003BCD28.f22++;
    r = D_001D8CE8(a);
    if (D_001D8D04 & 4) { func_003CD2A8(); }
    if (D_001D8D04 & 0x10) { func_003CD5A0(); }
    if (D_001D8CEC != 0) { D_001D8CEC(a); }
    D_001D9D80++;
    return r;
}
/* localdecomp:end func_003BCD28 */

/* localdecomp:start func_003BCDD8 */
__asm__(".extern D_001D8D04, 4");
extern s32 D_001D9388;
extern s32 D_001D93A4;
extern s32 D_001D9C90;
extern s32 D_001D9C88;
extern s32 D_001D9C8C;
extern s32 D_001A1ED0_3BCDD8[];
extern u8 D_00100AE0[];
extern u8 D_002FDC80[];
extern void func_003A96B0(s32, unsigned long);
extern void func_003BD030();
extern void func_00387778();
extern void func_003865A8();
extern void func_003CF340();
extern void func_003A9EE0(s32);
extern void func_003A9948();
extern void func_003895C8(s32);
extern void func_0038A1B0();
extern void func_003896F8();
extern void func_003A98E8();
extern void func_003C3B00();
extern void func_0038A138();
extern void func_11F0A0(s32);
extern void func_003CD628();
extern void func_003A9200();
extern void func_003A9560(s32);
extern void func_003D03D0();
extern void func_003CF2A0();
extern void func_003C3450();
extern void func_0038A2F0();
extern void func_00386878(s32);
extern void func_003D8810_003BCDD8(s32);
extern void func_003D8890();
extern void func_003D94B0_003BCDD8(s32);
void func_003BCDD8(void) {
    D_001D9388 = 0;
    func_00387778();
    func_003865A8();
    if (D_001D8D04 & 1) func_003BD030();
    if (D_001D8D04 & 2) {
        func_003CF340();
        func_003A9EE0(0x2010000);
    }
    if (D_001D9C90) {
        func_003A9948();
        func_003895C8(1);
        func_0038A1B0();
        func_003896F8();
        func_003A98E8();
    }
    if (D_001D8D04 & 0xC) {
        func_003C3B00();
        func_003A9EE0(0x2080000);
    }
    func_003895C8(1);
    if (D_001D9C88) func_0038A138();
    func_003A9948();
    func_003A96B0(8, 5);
    func_003A96B0(0x47, 0x53001);
    func_11F0A0(0);
    func_003CD628();
    *(volatile s32 *)&D_001D9D9C = 9;
    func_003A96B0(0x47, 0x5360B);
    func_003A9200(D_00100AE0);
    func_11F0A0(0);
    if (D_001D8D04 & 2) {
        func_003A9560(2);
        func_003D03D0(D_002FDC80);
        func_003CF2A0();
    }
    if (D_001D8D04 & 0xC) {
        func_003A9560(0x10);
        func_003C3450();
    }
    func_003896F8();
    if (D_001D9C8C) {
        func_003895C8(1);
        func_003A96B0(0x4E, (D_001A1ED0_3BCDD8[2] >> 13) | 0x31000000 | 0x100000000UL);
        func_003A9948();
        func_0038A2F0();
        func_003A96B0(0x4E, 0x31000000 | (D_001A1ED0_3BCDD8[2] >> 13));
        func_003896F8();
    }
    func_00386878(0);
    if (D_001D9388) {
        func_003D8810_003BCDD8(0);
        func_003D8890();
    }
    if (D_001D93A4) {
        func_003D94B0_003BCDD8(0);
        D_001D93A4 = 0;
    }
}
/* localdecomp:end func_003BCDD8 */

/* localdecomp:start func_003BD030 */
extern void func_003CE4A0(void);
extern void func_003CE400(void);
extern void func_003CE510(void);
extern void func_003A96B0(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_003BD030(void) {
    func_003CE4A0();
    func_003CE400();
    func_003CE510();
    func_003A96B0(0x47, 0x5360B);
    func_003A96B0(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003BD030 */

/* localdecomp:start func_003BD088 */
typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D5B94;
extern s32 D_001D9DAC;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001D9D84;
extern u8 D_00227500[];
extern S_2276C0_3B78C8 D_002276C0;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_0038CEA0();
extern void func_003C3028();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_003A56F0(void);
extern void func_003A1EE8(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_0039C6D8(void);
extern void func_0039B0A8(void);
extern s32 func_13CF40(s32);
extern void func_003A2A10(s32);
extern void func_0038A5C0(s32);
extern void func_0039A418(void);
extern void func_13CDF0(s32);
extern void func_003A9D40(void);
void func_003BD088(void) {
    s32 i;
    func_0038CEA0(D_00227500, -1, 0x80);
    D_002276C0.f10 |= 0x80000000;
    D_001D5B94 = 6;
    func_003C3028();
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620();
    func_003A56F0();
    func_003A1EE8();
    D_1CCFD0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0.f90[i] != 0) {
            func_13BF00(D_1A30B0.f90[i]);
            func_13BED0();
            D_001D9DAC = 0;
            D_1A30B0.f90[i] = 0;
        }
    }
    while (D_142430.f15C >= 3 || D_142430.f164 >= 0) {
        func_0039C6D8();
        func_0039B0A8();
    }
    if (D_142430.f17C != 0) D_142430.f17C = 0;
    if (D_142430.f18 >= 0) D_142430.f18 = -1;
    D_001D4CEC &= ~0x200;
    func_13CF40(0);
    D_1CCFD0.f7 = 0;
    func_003A2A10(1);
    do {} while (((s32 (*)(void))func_13B620)());
    D_1CCFD0.f7 = 1;
    func_0038A5C0(6);
    D_001D545C = D_001D9D84;
    func_0039A418();
    func_13CDF0(0);
    D_1CCFD0.f7 = 0;
    func_003A9D40();
}
/* localdecomp:end func_003BD088 */

/* localdecomp:start func_003BD260 */
extern u8 D_001D5571;
s32 func_003A78A0_003BD260(s32);                         /* extern */
extern s32 D_001D9D84;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];

void func_003BD260(void) {
    if (D_001D9D84 == 1) {
        if (D_001D5571 == 0) {
            D_001CCFD0->f7 = 0;
            if ((func_003A78A0_003BD260(1) == 0) && (func_003A78A0_003BD260(2) == 0) && (func_003A78A0_003BD260(3) == 0) && (func_003A78A0_003BD260(4) == 0) && (func_003A78A0_003BD260(5) == 0)) {
                func_003A78A0_003BD260(6);
            }
            D_001CCFD0->f7 = 1;
        }
    }
}
/* localdecomp:end func_003BD260 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BD310);

/* localdecomp:start func_003BD670 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7EB0;
typedef struct { u8 p0[7]; u8 f7; } S_1CCFD0_3B7EB0;
__asm__(".extern D_001D8D01, 1");
__asm__(".extern D_001DA270, 4");
__asm__(".extern D_001D8CF4, 4");
extern u8 D_001D8D01;
extern s32 D_001DA270;
extern void (*D_001D8CF4)(void);
extern S_142430_3B7EB0 D_142430_003BD670;
extern S_1CCFD0_3B7EB0 D_1CCFD0_003BD670;
extern void func_11F0A0();
extern void func_0039C6D8(void);
extern void func_0039B0A8(void);
extern s32 func_0039A4A8(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003A9D40(void);
extern void func_003882A8(void);
void func_003BD670(void) {
    s32 r;
    *(s32 *)0x1D4B4C = 0;
    if (D_001D8D01 == 0) {
        do {
            func_11F0A0(0);
            func_12C908(0);
            func_0039C6D8();
            func_0039B0A8();
            r = D_001D8D01 = func_0039A4A8() != 0;
        } while (r == 0);
    }
    while (D_142430_003BD670.f15C != 2 || D_142430_003BD670.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C6D8();
        func_0039B0A8();
    }
    if (D_001DA270 != 0) func_13BF00(D_001DA270);
    do {} while (func_13B620());
    func_13BED0();
    func_13CF40(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    { S_1CCFD0_3B7EB0 *c = &D_1CCFD0_003BD670; c->f7 = 0; }
    func_003A9D40();
    if (D_001D8CF4 != 0) D_001D8CF4();
    func_003882A8();
}
/* localdecomp:end func_003BD670 */

/* localdecomp:start func_003BD798 */
__asm__(".extern D_001D8D00, 1");
__asm__(".extern D_001D8D01, 1");
__asm__(".extern D_001D9DD4, 4");
__asm__(".extern D_001D8D24, 1");
__asm__(".extern D_001D8D20, 4");
extern u8 D_001D5BDC;
extern s32 D_001D9D84;
extern u8 D_001D8D00;
extern u8 D_001D8D01;
extern s32 D_001D9DD4;
extern s32 D_001D9C48;
extern s32 D_001D6E90;
extern s32 D_001D4B48;
extern u8 D_001D8D24;
extern f32 D_001D8D20;
extern void func_0039EEF0(s32, s32);
extern void func_003BD088(void);
extern void func_003BD310(void);
extern void func_003882A8(void);
extern void func_003A3E30(void);
extern s32 func_003BCD28(s32);
extern void func_003875D0(void);
extern void func_003BCAE0(void);
extern void func_0039C6D8(void);
extern void func_0039B0A8(void);
extern void func_003A9560(s32);
extern s32 func_0039A4A8(void);
extern void func_003A9440(void);
extern void func_003A93C0(void);
extern void func_003926F0(void);
extern void func_003BE4C8(void);
extern void func_00392A68(s32);
extern void func_003925D8(void);
extern void func_00392670(s32);
extern void func_0038A5C0(s32);
extern void func_003BD670(void);
s32 func_003BD798(void) {
    s32 r;
    if (D_001D5BDC == 0) func_0039EEF0(0, D_001D9D84);
    if (D_001D9D84 < 0) {
        func_003BD088();
        return 1;
    }
    r = 0;
    func_003BD310();
    D_001D8D00 = 0;
    D_001D8D01 = 0;
    for (;;) {
        func_003A9440();
        func_003A93C0();
        func_003926F0();
        if (D_001D8D24 != 0) func_003BE4C8();
        else func_00392A68(1);
        func_003925D8();
        func_00392670(0);
        if (r != 0) break;
        func_003882A8();
        func_003A3E30();
        r = func_003BCD28(D_001D8D00);
        D_001D9DD4 = 0;
        func_003875D0();
        func_003BCAE0();
        func_0039C6D8();
        func_0039B0A8();
        func_003A9560(1);
        func_12C908(0);
        D_001D9C48++;
        if (D_001D6E90 == 0) D_001D8D01 = func_0039A4A8() != 0;
        D_001D8D00 = D_001D4B48 >= 2;
    }
    func_003A9560(1);
    func_12C908(0);
    if (D_001D8D20 > 0.0f) func_0038A5C0(2);
    func_003BD670();
    return 1;
}
/* localdecomp:end func_003BD798 */

/* localdecomp:start func_003BD928 */
typedef int u128_3B8168 __attribute__((mode(TI)));
typedef struct { u8 p0[0x38]; s32 idx; u8 p1[0x28]; u8 *tab; } S_3B8168;
extern S_3B8168 D_00225780_003BD928;
extern f32 D_00225A30[];
typedef struct { u8 p0[0x140]; u128_3B8168 q; u8 p1[0x10]; f32 m[3][4]; } D_3BD928;
extern u8 D_00222340[];
extern void func_00387778();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
s32 func_003BD928(void) {
    f32 m[16];
    D_3BD928 *d;
    S_3B8168 *s = &D_00225780_003BD928;
    u8 *p = s->tab + s->idx * 32;
    f32 *q = (f32 *)(p + 0x10);
    s32 flag = p[0xC] != 0;
    D_00225A30[0] = q[3];
    func_00387778();
    *(u128_3B8168 *)(D_00222340 + 0x140) = *(u128_3B8168 *)p;
    func_12FF40(m);
    func_130088(m, m, *(f32 *)(p + 0x10));
    func_130130(m, m, q[1]);
    func_12FFE0(m, m, q[2]);
    d = (D_3BD928 *)D_00222340;
    d->m[0][0] = -m[8];
    d->m[1][0] = -m[0];
    d->m[2][0] = m[4];
    d->m[0][1] = -m[9];
    d->m[1][1] = -m[1];
    d->m[2][1] = m[5];
    d->m[0][2] = -m[10];
    d->m[1][2] = -m[2];
    d->m[2][2] = m[6];
    return flag;
}
/* localdecomp:end func_003BD928 */

/* localdecomp:start func_003BDA40 */
extern u8 D_001DA320[];
extern s32 D_001DA330[];
extern f32 D_001DA334[];
extern f32 D_001DA338[];
extern void func_003C56B0(void *, s32, f32, f32);
void func_003BDA40(void) {
    func_003C56B0(D_001DA320, D_001DA330[0], D_001DA334[0], D_001DA338[0]);
}
/* localdecomp:end func_003BDA40 */

/* localdecomp:start func_003BDA80 */
extern f32 func_0038D3D8(f32);
void func_003BDA80(u8 *ctx, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 n) {
    s32 r = D_001D9D80 % n;
    f32 s = func_0038D3D8(((f32)r / (f32)n + (f32)r / (f32)n) * 3.1415927f + -3.1415927f);
    s32 x = (s32)(s * a7) + a7 / 2;
    s32 y = (s32)(s * a6) + a6 / 2;
    s32 z = (s32)(s * a5) + a5 / 2;
    a3 += x;
    a2 += y;
    a1 += z;
    *(s32 *)(ctx + 0x78) = func_0038DF00(0.05f, *(s32 *)(ctx + 0x78),
        (a4 << 24) | (a3 << 16) | (a2 << 8) | a1);
}
/* localdecomp:end func_003BDA80 */

/* localdecomp:start func_003BDC00 */
/* MATCH */
typedef int u128_3B8440 __attribute__((mode(TI)));
__asm__(".extern D_001DA33C, 4");
__asm__(".extern D_001DA330_003BDC00, 4");
extern s32 D_001DA320_003BDC00[2];
extern f32 D_001DA33C;
extern s32 D_001DA330_003BDC00;
extern f32 D_001DA334_003BDC00;
extern f32 D_001DA338_003BDC00;
extern void func_003BDA80(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C31F8_003BDC00(void *, s32, void *);
extern void func_0038DDE0(f32, f32);
extern f32 func_0038D3D8(f32);
extern void func_0038A0E8(void (*)(), s32);
extern void func_003BDA40(void);
void func_003BDC00(u8 *p) {
    u128_3B8440 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_003BDA80(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_003C31F8_003BDC00(p, m, &v);
    f = ((f32 (*)(f32, f32))func_0038DDE0)(D_001DA33C, 0.06690429151058197f);
    D_001DA33C = f;
    f = (func_0038D3D8(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3B8440 *)D_001DA320_003BDC00 = v;
    D_001DA334_003BDC00 = 0.04f;
    D_001DA338_003BDC00 = 0.07f;
    D_001DA330_003BDC00 = (((s32)f + 0x17) << 24) | 0xC0;
    func_0038A0E8(func_003BDA40, (s32)p);
}
/* localdecomp:end func_003BDC00 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BDD20);

/* localdecomp:start func_003BDEC0 */
extern void func_0039A958(s32);
extern void func_003BBB28(s32);
extern s32 func_003BD928(void);
extern void func_003BDD20(void);
extern s32 D_001D8D0C;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_00225780_003BDEC0[];
s32 func_003BDEC0(void) {
    S_003B8700 *p = D_00225780_003BDEC0;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_003BBB28(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x60) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_0039A958(temp_4);
        }
        func_003BD928();
        func_003BDD20();
    } else {
        var_17 = 1;
        D_001D8D0C = D_001D8D0C + 1;
    }
    return var_17;
}
/* localdecomp:end func_003BDEC0 */

/* localdecomp:start func_003BDF78 */
extern s32 D_001D8D2C;
extern s32 D_001D8D28;
extern s32 D_001DA2E8[];
extern s8 D_001DA310[];
void func_003BDF78(s32 n, s32 *p, s32 v) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (i < n) D_001DA2E8[i] = p[i];
        else D_001DA2E8[i] = -1;
        D_001DA310[i] = 0;
        }
    D_001D8D2C = v;
    D_001D8D28 = n;
}
/* localdecomp:end func_003BDF78 */

/* localdecomp:start func_003BDFD0 */
extern s8 D_001DA319[];

void func_003BDFD0(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 9;
    var_v0 = D_001DA319;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_003BDFD0 */

/* localdecomp:start func_003BE000 */
__asm__(".extern D_001D8D28, 4");
__asm__(".extern D_001D8D2C, 4");
typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BE000;
extern u8 D_001DA310_003BE000[1];
extern s32 D_001DA2E8_003BE000[2];
extern s32 func_00382868(s32);
extern void func_003BDFD0(void);
s32 func_003BE000(void) {
    s32 i;
    s32 r;
    s32 cur;
    u8 *used;
    used = D_001DA310_003BE000;
    for (i = 0; i < D_001D8D28; i++) {
        if (i != D_001D8D2C && *(u8 *)(i + (s32)used) == 0) break;
    }
    if (i == D_001D8D28) func_003BDFD0();
    cur = D_16C580_003BE000.f64;
    do {
        r = func_00382868(D_001D8D28);
    } while (r == cur || *(u8 *)(r + (s32)used) != 0);
    do {
        *(u8 *)(r + (s32)used) = 1;
        return D_001DA2E8_003BE000[r];
    } while (0);
}
/* localdecomp:end func_003BE000 */

/* localdecomp:start func_003BE0E8 */
typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_16C580;
extern void func_003BC978(s32);
extern void func_0039A958(s32);
void func_003BE0E8(s32 a) {
    func_003BC978(a);
    D_16C580.f64 = a;
    D_16C580.f68 = 0;
    func_0039A958(0);
}
/* localdecomp:end func_003BE0E8 */

/* localdecomp:start func_003BE128 */
extern void func_003BC978(s32);
extern void func_0039A958(s32);
extern void func_003BDD20(void);
extern void func_003C2C50();
void func_003BE128(s32 a) {
    s32 i;
    func_003BC978(a);
    D_16C580.f64 = a;
    func_0039A958(0);
    func_003BDD20();
    for (i = 0; i < D_00225780.n; i++) {
        if (D_00225780.slot[i] != 0) {
            func_003C2C50(D_00225780.slot[i]);
        }
    }
}
/* localdecomp:end func_003BE128 */

/* localdecomp:start func_003BE1B8 */
extern s32 D_0016C5E4[];
 
s32 func_003BE1B8(void) {
    return D_0016C5E4[0];
}
/* localdecomp:end func_003BE1B8 */

/* localdecomp:start func_003BE1C8 */
extern s32 D_002257B4[];
s32 func_003BE1C8(void) {
    return D_002257B4[0];
}
/* localdecomp:end func_003BE1C8 */

/* localdecomp:start func_003BE1D8 */
extern s32 D_001D8D0C;
s32 func_003BE1D8(void) { return D_001D8D0C; }
/* localdecomp:end func_003BE1D8 */

/* localdecomp:start func_003BE1E0 */
extern s32 D_001D4B4C[];
extern s32 D_001D4B48;
s32 func_003BE1E0(void) {
    if (D_001D4B4C[0] != 0 && D_001D4B48 >= 2) return 1;
    return 0;
}
/* localdecomp:end func_003BE1E0 */

/* localdecomp:start func_003BE208 */
extern s32 D_001DA644[];
extern s32 D_001DA648[];
extern s32 D_001DA64C;
void func_003BE208(void) {
    D_001DA644[0] = 0;
    D_001DA648[0] = -1;
    D_001DA64C = 0;
}
/* localdecomp:end func_003BE208 */

/* localdecomp:start func_003BE228 */
extern f32 D_001D8D20;
void func_003BE228(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  arg1 = arg1 - 1;
  if (arg0 <= 0 || arg0 >= arg1) {
    D_001D8D20 = 0.0f;
  } else if (arg2 >= arg0) {
    D_001D8D20 = (f32)arg0 / (f32)arg2;
  } else if (arg1 - arg3 < arg0) {
    D_001D8D20 = (f32)(arg1 - arg0) / (f32)arg3;
  } else {
    D_001D8D20 = 1.0f;
  }
  D_001D8D20 = 1.0f - D_001D8D20;
}
/* localdecomp:end func_003BE228 */

/* localdecomp:start func_003BE2D0 */
extern f32 D_001D8D20;
void func_003BE2D0(f32 a) {
    D_001D8D20 = a;
}
/* localdecomp:end func_003BE2D0 */

/* localdecomp:start func_003BE2D8 */
extern u32 D_00142BA0[];
extern s32 D_001D6E90;
extern s32 func_003BBAA0();
extern s32 func_003BBA98();
s32 func_003BE2D8(s32 a, s32 b, u32 c) {
    u32 w;
    if (a == -1 || func_003BBAA0() == a) {
        if (b == -1 || func_003BBA98() == b) {
            w = c >> 2;
            if (!(D_00142BA0[w] & (1 << (c & 0x1F)))) {
                D_001D6E90 = c;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BE2D8 */

/* localdecomp:start func_003BE388 */
extern s32 func_003BE2D8(s32, s32, s32);
extern u8 D_001D558C[];
void func_003BE388(void) {
    if (func_003BE2D8(0x1C, 8, 0)) return;
    if (func_003BE2D8(8, 8, 0)) return;
    if (func_003BE2D8(8, 0x1B, 0)) return;
    if (func_003BE2D8(8, 0x1C, 0)) return;
    if (func_003BE2D8(-1, 8, 0x11)) return;
    if (D_001D558C[0] != 0) func_003BE2D8(8, -1, 0x12);
}
/* localdecomp:end func_003BE388 */

/* localdecomp:start func_003BE430 */
void func_003A7708(s32);
void func_003A78A0(s32);
extern s32 D_001D5B94;
extern s32 D_001D6E90;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003BE430[];

void func_003BE430(void) {
    if (D_001D6E90 != 0) {
        D_001CCFD0_003BE430->f7 = 0;
        switch (D_001D6E90) {                       /* irregular */
        case 17:
            func_003A7708(0x11);
            break;
        case 18:
            func_003A78A0(0x12);
            break;
        }
        D_001CCFD0_003BE430->f7 = 1;
        D_001D5B94 = 6;
        D_001D6E90 = 0;
    }
}
/* localdecomp:end func_003BE430 */

/* localdecomp:start func_003BE4C0 */
extern u8 D_001D8D24;
void func_003BE4C0(s32 a) {
    D_001D8D24 = a;
}
/* localdecomp:end func_003BE4C0 */

/* localdecomp:start func_003BE4C8 */
__asm__(".extern D_001D8D30, 4");
extern u32 *D_001DA0D0;
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
extern s32 D_001D8D30;
void func_003BE4C8(void) {
    D_001DA0D0[0] = 0x30000002;
    D_001DA0D0[1] = (u32)&D_001D8D30;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000002;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000029;
    D_001DA0D0[1] = (u32)D_001D02D0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000029;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000003;
    D_001DA0D0[1] = (u32)D_001D7300;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000003;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003BE4C8 */

/* localdecomp:start func_003BE5C8 */
extern u8 D_001D8D01;
u8 func_003BE5C8(void) {
    return D_001D8D01;
}
/* localdecomp:end func_003BE5C8 */

/* localdecomp:start func_003BE5D0 */
extern u32 D_001DA51C;
extern u32 D_001DA520;
void func_003BE5D0(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_001DA51C; p != D_001DA520; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_00225780.n; i++) {
        if (D_00225780.slot[i] != 0) {
            ((void (*)(void *))cb)(D_00225780.slot[i]);
        }
    }
}
/* localdecomp:end func_003BE5D0 */

/* localdecomp:start func_003BE680 */
extern void func_003BBCE8(s32, s32);
extern void func_0038A5C0(s32);
extern s32 D_001DA340[];
s32 func_003BE680(void) {
    func_003BBCE8(0, 0);
    func_0038A5C0(6);
    D_001DA340[0] = 300;
    return 1;
}
/* localdecomp:end func_003BE680 */

/* localdecomp:start func_003BE6B8 */
extern s16 D_0016C5A2[];
extern s32 func_0038CDF8(s32 *);
void func_003BE228(s16, s32, s32, s32);
extern u8 D_001DA340_003BE6B8;

s32 func_003BE6B8(void) {
    s32 temp_s0;

    temp_s0 = func_0038CDF8(&D_001DA340_003BE6B8) != 0;
    func_003BE228(D_0016C5A2[0], 0x12C, 0xF, 0xF);
    return temp_s0;
}
/* localdecomp:end func_003BE6B8 */

/* localdecomp:start func_003BE708 */
s32 func_003BE708(void) {
}
/* localdecomp:end func_003BE708 */
