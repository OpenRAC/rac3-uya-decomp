#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E7258();
extern s32 func_003E7210(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void *func_003E6E78();
extern s32 func_003E6C20();
extern s32 func_003E6F80();
extern void func_003E6C68(void *);
extern void func_003E6CD0();
extern s32 func_003E7188();
extern void func_003E6D08();
extern void func_003E6D98(void *);
extern void func_003E6E28();
extern void func_003E7268(void *p);
extern s32 func_003E7058();
extern s32 func_003E6F30();
extern void func_003E7268(void *);
extern s32 func_003E7210(s32 *, s32, s32, s32, s32, s32);
extern s32 func_003E7388();
extern void func_003E7378();
extern s32 func_003E7110();
extern s32 func_003E6990();
extern void *func_003E6910();
extern s32 *func_003E70F0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E6910 */
typedef struct { u32 key; void *val; } HE_400;
typedef struct { s32 f0; s32 n; HE_400 e[0x400]; } HT_400;
extern u8 D_001DAA88_003E6910[];
void *func_003E6910(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != D_001DAA88_003E6910) return v;
    }
    return 0;
}
/* localdecomp:end func_003E6910 */

/* localdecomp:start func_003E6990 */
extern void *func_003E6910();
typedef struct { u32 key; void *val; } HE_3E11D0;
typedef struct { s32 f0; s32 n; HE_3E11D0 e[0x400]; } HT_3E11D0;
extern u8 D_001DAA88_003E6990[];
s32 func_003E6990(HT_3E11D0 *t, u32 key, void *val) {
    s32 i;
    s32 h;
    if (t->n >= 0x400) return 0;
    if (((void *(*)(void))func_003E6910)()) return 0;
    for (i = 0; i < 0x400; i++) {
        h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        if (t->e[h].val == 0 || t->e[h].val == D_001DAA88_003E6990) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6990 */

/* localdecomp:start func_003E6A68 */
extern u8 D_001DAA88;
void *func_003E6A68(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (v != &D_001DAA88 && t->e[h].key == key) {
            t->e[h].val = &D_001DAA88;
            t->n--;
            return v;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6A68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E6AF8);

/* localdecomp:start func_003E6B30 */
typedef struct O { struct VT *vt; u8 pad[0x18]; } O;
struct VT { u8 pad[0x10]; void (*fn)(O *, s32); };
extern u8 D_001DA978;
extern u8 D_001DA9B0[];
void func_003E6B30(void) {
    O *first = (O *)&D_001DA978;
    O *p;
    if (first != 0) {
        p = (O *)D_001DA9B0;
        if (p != first) {
            do {
                p--;
                p->vt->fn(p, 0);
            } while (p != first);
        }
    }
}
/* localdecomp:end func_003E6B30 */

/* localdecomp:start func_003E6B90 */
extern s32 D_001DA978_003E6B90;
extern s32 D_001DA9B0_003E6B90;
typedef struct { u8 p[0x1C]; } E_3E13D0;
extern void **func_003F2400(void **);
extern void func_116FD0();
extern void func_003E6AF8();
s32 func_003E6B90(s32 idx) {
    s32 i;
    E_3E13D0 *p;
    if (D_001DA9B0_003E6B90 == 0) {
        p = (E_3E13D0 *)&D_001DA978_003E6B90;
        i = 1;
        do {
            func_003F2400((void **)p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA9B0_003E6B90 = 1;
        func_116FD0((u8 *)func_003E6AF8 + 0x38);
    }
    return (s32)&((E_3E13D0 *)&D_001DA978_003E6B90)[idx];
}
/* localdecomp:end func_003E6B90 */

/* localdecomp:start func_003E6C20 */
typedef struct { u8 pad0[0x20]; s32 *slots[12]; } S_003E1460_inner;
typedef struct { u8 pad0[4]; S_003E1460_inner *f4; } S_003E1460_outer;

s32 func_003E6C20(S_003E1460_outer *arg0, u32 arg1, s32 *arg2) {
    s32 **slot;

    if (arg1 < 12) {
        { s32 **b = arg0->f4->slots; slot = &b[arg1]; }
        if (*slot == 0 || (**slot ^ 4) != 0) {
            *slot = arg2;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6C20 */

/* localdecomp:start func_003E6C68 */
typedef struct CallbackVtable_003E14A8 {
    unsigned char padding[0x10];
    void (*callback)(void *);
} CallbackVtable_003E14A8;

typedef struct Entry_003E14A8 {
    unsigned char padding[4];
    CallbackVtable_003E14A8 *vtable;
} Entry_003E14A8;

typedef struct Container_003E14A8 {
    unsigned char padding[0x20];
    Entry_003E14A8 *slots[12];
} Container_003E14A8;

typedef struct Root_003E14A8 {
    unsigned char padding[4];
    Container_003E14A8 *container;
} Root_003E14A8;

void func_003E6C68(void *argument) {
    int index;
    Root_003E14A8 *root = argument;
    Entry_003E14A8 *entry;
    register CallbackVtable_003E14A8 *vtable __asm__("$3");
    register void (*callback)(void *) __asm__("$2");

    for (index = 0; index < 12; index++) {
        entry = root->container->slots[index];
        if (entry != 0) {
            vtable = entry->vtable;
            callback = vtable->callback;
            callback(entry);
        }
    }
}
/* localdecomp:end func_003E6C68 */

/* localdecomp:start func_003E6CD0 */
extern void func_003E6198(void *);
 
typedef struct { void *arr[5]; s32 idx; } S_3E1510;
 
void func_003E6CD0(void *p) {
    S_3E1510 *q = *(S_3E1510 **)((u8 *)p + 0x4);
    void *x = q->arr[q->idx];
    if (x != 0) {
        func_003E6198(x);
    }
}
/* localdecomp:end func_003E6CD0 */

/* localdecomp:start func_003E6D08 */
typedef struct { u8 pad[0x64]; void (*fn[4])(void); s32 count; } Q_3E1548;
typedef struct { s32 pad; Q_3E1548 *q; } S_3E1548;
void func_003E6D08(S_3E1548 *p) {
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
/* localdecomp:end func_003E6D08 */

/* localdecomp:start func_003E6D98 */
typedef struct { u8 pad[0x50]; void (*fn[4])(void); s32 count; } Q_3E15D8;
typedef struct { s32 pad; Q_3E15D8 *q; } S_3E15D8;
void func_003E6D98(void *arg0) {
    S_3E15D8 *p = (S_3E15D8 *)arg0;
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
/* localdecomp:end func_003E6D98 */

/* localdecomp:start func_003E6E28 */
extern void func_003E73F8();
extern void func_003E6338(s32);
extern void func_003E7450(void);
typedef struct { s32 a[5]; s32 idx; } Q_3E1668;
typedef struct { s32 pad; Q_3E1668 *q; } S_3E1668;
void func_003E6E28(S_3E1668 *p) {
    s32 v; func_003E73F8(p); v = p->q->a[p->q->idx]; if (v) func_003E6338(v); func_003E7450();
}
/* localdecomp:end func_003E6E28 */

/* localdecomp:start func_003E6E78 */
void func_0038CEA0(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001DA9B8[];
extern u8 D_0031B7D0[];

void *func_003E6E78() {
    D_001DA9B8->f4 = D_0031B7D0;
    func_0038CEA0(D_0031B7D0 + 0x18, 0, 8);
    func_0038CEA0(D_001DA9B8->f4, 0, 0x14);
    func_0038CEA0(D_001DA9B8->f4 + 0x20, 0, 0x30);
    func_0038CEA0(D_001DA9B8->f4 + 0x50, 0, 0x10);
    func_0038CEA0(D_001DA9B8->f4 + 0x64, 0, 0x10);
    (*(s32 *)((u8 *)(D_001DA9B8->f4) + 0x60)) = 0;
    (*(s32 *)((u8 *)(D_001DA9B8->f4) + 0x74)) = 0;
    (*(s32 *)((u8 *)(D_001DA9B8->f4) + 0x14)) = 0;
    return D_001DA9B8;
}
/* localdecomp:end func_003E6E78 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E6F20);

/* localdecomp:start func_003E6F30 */
typedef struct { u8 pad[0x18]; s32 arr[1]; } S_3E1770;
 
s32 func_003E6F30(void *p, s32 i) {
    return (*(S_3E1770 **)((u8 *)p + 0x4))->arr[i];
}
/* localdecomp:end func_003E6F30 */

/* localdecomp:start func_003E6F48 */
s32 func_003E6F48(void *p, u32 i, s32 v) {
    if (i < 8) {
        s32 *q = *(s32 **)((u8 *)p + 0x4) + i;
        if (*q == 0) {
            *q = v;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6F48 */

/* localdecomp:start func_003E6F80 */
extern s32 func_003E6B90(s32);
s32 func_003E6F80(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_17;

    if ((arg3 != 0) && (arg4 < 0x190)) {
        if (arg2 <= 0x31FFF) {
            temp_17 = arg1 * 4;
            if ((*(s32 *)((u8 *)((*(s32 *)((u8 *)arg0 + 4)) + temp_17) + 0x18)) == 0) {
                (*(s32 *)((u8 *)((*(s32 *)((u8 *)arg0 + 4)) + temp_17) + 0x18)) = func_003E6B90(arg1);
                func_003F23E0(func_003E6B90(arg1), arg4, arg3, arg2);
                return 1;
            }
            goto block_5;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return 0;
    }
block_5:
    return 0;
}
/* localdecomp:end func_003E6F80 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7050);

/* localdecomp:start func_003E7058 */
typedef struct 
{
  u8 pad[0x14];
  int index;
} SubStruct;
typedef struct 
{
  u8 pad;
  SubStruct *sub;
} MainStruct;
s32 func_003E7058(MainStruct *p)
{
  SubStruct *sub = p->sub;
  int *new_var;
  if (sub != 0)
  {
    int *base_ptr = (int *) sub;
    int element_offset = sub->index;
    new_var = &base_ptr[element_offset];
    return *new_var;
  }
  return 0;
}
/* localdecomp:end func_003E7058 */

/* localdecomp:start func_003E7080 */
extern s32 func_003F25A0(s32 *);
s32 func_003E7080(s32 *a0, s32 a1) {
    u8 *t;
    if (func_003F25A0(a0) != 0) {
        return 0;
    }
    t = (u8 *)a0[1];
    if (t != 0 && (u32)a1 < 8 && *(s32 *)(t + (a1 << 2)) != 0) {
        *(s32 *)(t + 0x14) = a1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7080 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E70E8);

/* localdecomp:start func_003E70F0 */
s32 *func_003E70F0(s32 *p, s32 a, s32 b, s32 c, s32 d) {
    p[2] = a;
    p[1] = b;
    p[4] = d;
    p[3] = c;
    p[0] = 0;
    return p;
}
/* localdecomp:end func_003E70F0 */

/* localdecomp:start func_003E7110 */
typedef struct { s32 x0; u32 x4; u32 x8; s32 xC; s32 (*x10)(s32, u32); } S_3E1950;
s32 func_003E7110(S_3E1950 *p) {
    u32 i;
    s32 r = 0;
    for (i = p->x8; i <= p->x4; i++) {
        r |= p->x10(p->xC, i) != 0;
    }
    return r;
}
/* localdecomp:end func_003E7110 */

/* localdecomp:start func_003E7188 */
typedef struct { u32 i, max, wrap; s32 c; s32 (*fn)(s32, u32); } S_E19C8;
s32 func_003E7188(S_E19C8 *s, s32 n) {
    s32 r = 0;
    u32 x, v;
    while (n > 0) {
        n--;
        r |= (s->fn(s->c, s->i) != 0);
        x = s->i + 1;
        s->i = x;
        v = s->max < x ? s->wrap : x;
        s->i = v;
    }
    return r;
}
/* localdecomp:end func_003E7188 */

/* localdecomp:start func_003E7210 */
extern void func_003E7250(void *);
s32 func_003E7210(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e) {
    p[1] = a;
    p[2] = b;
    p[3] = c;
    p[4] = d;
    p[5] = e;
    func_003E7250(p);
    return (s32)p;
}
/* localdecomp:end func_003E7210 */

/* localdecomp:start func_003E7250 */
void func_003E7250(void *p) {
    *(s32 *)p = 0;
}
/* localdecomp:end func_003E7250 */

/* localdecomp:start func_003E7258 */
s32 func_003E7258(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_003E7258 */

/* localdecomp:start func_003E7260 */
void func_003E7260(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x0) = value;
}
/* localdecomp:end func_003E7260 */

/* localdecomp:start func_003E7268 */
extern void func_003E7260(void *, s32);
 
void func_003E7268(void *p) {
    func_003E7260(p, 0);
}
/* localdecomp:end func_003E7268 */

/* localdecomp:start func_003E7288 */
void func_003E7288(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x4);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7288 */

/* localdecomp:start func_003E72B0 */
void func_003E72B0(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x8);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E72B0 */

/* localdecomp:start func_003E72D8 */
void func_003E72D8(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0xC);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E72D8 */

/* localdecomp:start func_003E7300 */
void func_003E7300(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x10);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7300 */

/* localdecomp:start func_003E7328 */
void func_003E7328(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x14);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7328 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7350);

typedef struct {
    s32 field_0;        /* Offset 0x00 - Targeted by sw $zero, 0($a0) */
    s32 field_4;        /* Offset 0x04 - Padding */
    void* field_8;      /* Offset 0x08 - Targeted by sw $v0, 8($a0) */
} TargetStruct;

extern char D_001D96B0[];

/* localdecomp:start func_003E7358 */
extern char D_001D96B0[];
void **func_003E7358(void **p) { p[0] = 0; p[2] = D_001D96B0; return p; }
/* localdecomp:end func_003E7358 */

/* localdecomp:start func_003E7370 */
s32 func_003E7370(s32 arg0, s32 arg1) {
    return arg1 == 0;
}
/* localdecomp:end func_003E7370 */

/* localdecomp:start func_003E7378 */
void func_003E7378(s32 *p) {
    *p += 1;
}
/* localdecomp:end func_003E7378 */

/* localdecomp:start func_003E7388 */
// Define the context structure passing through $a0
typedef struct {
    s32 counter; /* Offset 0x00 - Targeted by lw/sw operations */
} CounterContext;

// Signature must take the context pointer ($a0) and return an s32 ($v0)
s32 func_003E7388(CounterContext* ctx) {
    // 0: lw $v0, 0($a0)
    s32 current_val = ctx->counter;

    // 4: beqz $v0
    if (current_val != 0) {
        // 8: addiu $v0, $v0, -1
        // c: sw $v0, 0($a0)
        ctx->counter = current_val - 1;
    }

    // 14: lw $v0, 0($a0) (Scheduled cleanly into the jr $ra delay slot)
    return ctx->counter;
}
/* localdecomp:end func_003E7388 */

/* localdecomp:start func_003E73A0 */
extern u8 D_001D96B0_g;
extern s32 func_003F2578();
void func_003E73A0(u8 *p, s32 f) {
    *(u8 **)(p + 8) = &D_001D96B0_g;
    if (f & 1) func_003F2578(p);
}
/* localdecomp:end func_003E73A0 */

/* localdecomp:start func_003E73D0 */
extern void func_003A96B0(s32, unsigned long);
void func_003E73D0(void) {
    func_003A96B0(0x47, 0x33001);
}
/* localdecomp:end func_003E73D0 */
