#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2E80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2F98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A3088);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A39F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A3A00);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C560);

/* localdecomp:start func_003A3E30 */
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_003A3A00(S_39E8E0 *);
void func_003A3E30(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_003A3A00(&D_001CD0C0[i]);
}
/* localdecomp:end func_003A3E30 */

/* localdecomp:start func_003A3E78 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_003A3E78(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_003A3E78 */

/* localdecomp:start func_003A3EF0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39E9A0;
extern V4_39E9A0 D_00222480_003A3EF0[];
extern V4_39E9A0 D_002276E0[];
extern s32 D_001A30F4[];
extern void func_00382980(s32, f32, f32);
extern s32 func_003D3F00();
extern void func_0038D148_003A3EF0(void *, void *, f32);
void func_003A3EF0(V4_39E9A0 *a, V4_39E9A0 *p) {
    u128_t va, vb;
    if (p == 0) p = D_00222480_003A3EF0;
    func_00382980((s32)a, 0.5f, 6.0f);
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
    if (func_003D3F00(p, a, 0x82, D_001A30F4[0], 0)) {
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_002276E0[0]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
        func_0038D148_003A3EF0(a, a, 0.75f);
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(*a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
    }
}
/* localdecomp:end func_003A3EF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A3FA8);

/* localdecomp:start func_003A3FB0 */
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
s32 func_003A3FB0(f32 *op, void *c, f32 x, f32 lo, f32 hi) {
    S_39EA60 *o = (S_39EA60 *)op;
    s32 a = o->f8;
    f32 t;
    if ((o->f19 & 1) || c != 0) {
        if (x <= lo) return o->fC;
        if (hi <= x) return a;
        t = hi - x;
        return a + (s32)((t * t * (f32)(o->fC - a)) / ((hi - lo) * (hi - lo)));
    }
    if (x <= lo) return o->fC;
    if (!(hi <= x)) return a + (s32)(((hi - x) * (f32)(o->fC - a)) / (hi - lo));
    return a;
}
/* localdecomp:end func_003A3FB0 */

/* localdecomp:start func_003A4088 */
extern s32 D_00222480[];
extern f32 func_0038D228(void *, void *);
extern s32 func_003A3FB0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_003A4088(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_00222480;
    f = func_0038D228(a, b);
    func_003A3FB0(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_003A4088 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A40E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A42A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4390);

/* localdecomp:start func_003A4520 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_003A4520(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_003A4520 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4548);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A51D8);

/* localdecomp:start func_003A51E8 */
extern u8 D_1A30B0[];
void func_003A51E8(u32 i) {
    if (i < 52) {
        u8 *e = D_1A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
/* localdecomp:end func_003A51E8 */

/* localdecomp:start func_003A5240 */
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
s32 func_003A5240(s32 id) {
    s32 n = 0x34;
    s32 i;
    if (id == 0 || (D_001A4BE0[0].x25C0 != id && D_001A4BE0[0].x1200 != id)) n = 0x2A;
    for (i = 0; i < n; i++) {
        if (D_001A30B0[i + 1].b50 == 0) break;
    }
    if (i == n) return -1;
    return i;
}
/* localdecomp:end func_003A5240 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A52B8);

/* localdecomp:start func_003A5560 */
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_003A52B8();
s32 func_003A5560(s32 a, s32 b, P_39FE80 *p) {
    O_39FE80 *o;
    s32 r;
    u8 *e;
    if (p == 0) return -1;
    o = p->o;
    if (o == 0) return -1;
    if (o->f28 == 0) return -1;
    if (a >= o->bD) return -1;
    r = func_003A52B8(o->f28 + a * 32, b, p, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = (s32)p;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_003A5560 */

/* localdecomp:start func_003A5608 */
extern s32 D_001D9DAC;
extern s32 D_001D5B9C;
extern u8 D_1A30B0[];
extern s32 func_003A52B8();
s32 func_003A5608(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001D9DAC == 0) return -1;
    if (a >= D_001D5B9C) return -1;
    r = func_003A52B8(D_001D9DAC + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_003A5608 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5698);
