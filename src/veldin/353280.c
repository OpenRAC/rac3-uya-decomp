#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00353280);
TEXT_PADDING(2);

LINKER_REMNANT("asm/veldin/remnants", func_00353308);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00353310);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00353358);

/* localdecomp:start func_00355210 */
typedef struct {
    char p0[0x10]; char v10[0x10]; unsigned char b20; char p21[0xf];
    union { unsigned long d30; struct { char c30; unsigned char b31; } c_355210; } u30_355210;
    char p38[0x37]; unsigned char b6f; char p70[0x25]; unsigned char b95; char p96[2]; int w98;
} A_355210;
typedef struct {
    char p0[0x30]; float f30; char p34[0xa]; unsigned char b3e; char p3f[0x1f]; unsigned char b5e; unsigned char b5f;
    char p60[0x100]; char r160[0x180]; int w2e0; float f2e4; int w2e8; float f2ec; char p2f0[0x30]; char r320[0x40]; int w360;
} S_355210;
extern char D_001E2AC0_355210[];
extern int D_001DD65C_355210;
extern int func_003554D8_355210(void);
extern float func_0040C018_355210(void *, void *);
extern void func_00444188_355210(A_355210 *);
extern void func_0044CB08_355210(A_355210 *, int, int, int);
extern void func_0044F5E8_355210(A_355210 *, void *, int);
extern int func_0044FCD0_355210(A_355210 *, void *, int, int, int);
extern void func_00355AE0_355210(A_355210 *);
extern void func_00355A00_355210(A_355210 *);
extern void func_004538E0_355210(A_355210 *, int);
extern void func_004539A8_355210(A_355210 *, int, float, float, void *, int, int, int, float, int, int, int, int);

int func_00355210(A_355210 *a) {
    S_355210 *s = *(S_355210 **)((char *)a + 0x68);
    if (a->b20 == 0 && func_003554D8_355210()) return 1;
    if (s->b3e == 2) goto end1;
    if (a->u30_355210.c_355210.b31) {
        if (func_0040C018_355210(D_001E2AC0_355210, a->v10) < 576.0f) {
            func_00444188_355210(a);
            a->b6f = 0x16;
        }
    }
    if (s->w360) func_0044CB08_355210(a, s->w360, 1, D_001DD65C_355210);
    func_0044F5E8_355210(a, &s->f30, 0);
    if (func_0044FCD0_355210(a, s->r160, 0, 0, 0)) func_00355AE0_355210(a);
    if (s->b5e) {
end1:
        func_00355A00_355210(a);
        return 1;
    }
    if (s->b5f) {
        if ((a->u30_355210.d30 & 0x104100000000UL) != 0x4100000000UL || a->w98 != 0) {
            if (0.0f < s->f30) func_004538E0_355210(a, 5);
        }
        if (a->b95 == 1) func_004539A8_355210(a, s->w2e0, s->f2e4, 10.0f, s->r320, 0, 0, 0, 1.0f, 3, 0, 0, 0);
        else func_004539A8_355210(a, s->w2e8, s->f2ec, 10.0f, s->r320, 0, 0, 0, 1.0f, 3, 0, 0, 0);
    } else {
        if ((a->u30_355210.d30 & 0x104100000000UL) != 0x4100000000UL || a->w98 != 0) {
            if (0.0f < s->f30) func_004538E0_355210(a, 3);
        }
        if (a->b95 == 1 || a->b95 == 4) func_004539A8_355210(a, s->w2e0, s->f2e4, 10.0f, s->r320, 0, 0, 0, 1.0f, 1, 0, 0, 0);
        else func_004539A8_355210(a, s->w2e8, s->f2ec, 10.0f, s->r320, 0, 0, 0, 1.0f, 1, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_00355210 */

/* localdecomp:start func_003554D8 */
typedef struct { f32 x, y, z, w; } V4_3554D8 __attribute__((aligned(16)));
typedef struct { s32 (*fn)(u8 *); } Vt_3554D8;

extern u8 *D_001E009C_3554D8;
extern s32 D_001D545C_3554D8;

extern s32 func_00440848_3554D8(s32 a);
extern f32 func_00440918_3554D8(f32 a, f32 b);
extern void func_00455F28_3554D8(u8 *m, u8 *a, s32 b, u8 *c);
extern void func_00458A70_3554D8(u8 *m, f32 a, f32 b, f32 c, f32 d);
extern Vt_3554D8 *func_00438468_3554D8(s32 a, s32 b);
extern void func_00441C78_3554D8(u8 *m, s32 a, s32 b, s32 c);
extern void func_00441FB8_3554D8(u8 *m, s32 a, s32 b);
extern void func_004A6DF8_3554D8(u8 *m, s32 a);
extern s32 func_00440878_3554D8(s32 a, s32 b);
extern u8 *func_00435E70_3554D8(s32 a, s32 b);
extern void func_00452E70_3554D8(u8 *a, u8 *m);

s32 func_003554D8(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    s32 ok;
    u8 *o;

    if (func_00440848_3554D8(2) != 0) {
        *(u16 *)(m + 0x34) |= 0x8000;
    }
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    *(V4_3554D8 *)(v + 0x300) = *(V4_3554D8 *)(m + 0x10);
    *(V4_3554D8 *)(v + 0x320) = *(V4_3554D8 *)(m + 0x10);
    *(f32 *)(v + 0x318) = func_00440918_3554D8(0.0f, 20.0f) * 0.0174532924f;
    func_00455F28_3554D8(m, v + 0x3F0, 12, v + 0x36C);
    v[0x1D7] = 1;
    v[0x170] = 0x1B;
    v[0x1A8] = 7;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    if (func_00440848_3554D8(2) != 0) {
        v[0x1D3] = 0x11;
        v[0x1D2] = 0xB;
        v[0x176] = 0;
    } else {
        v[0x176] = 1;
        v[0x1D3] = 0x13;
        v[0x1D2] = 0xA;
    }
    *(f32 *)(v + 0x180) = 0.0166666675f;
    *(f32 *)(v + 0x184) = 0.0069444445f;
    *(f32 *)(v + 0x188) = 0.00972222257f;
    *(f32 *)(v + 0x18C) = 0.000555555569f;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x17C) = 0.25f;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(f32 *)(v + 0x1A0) = *(f32 *)(m + 0x18) - 10.0f;
    *(f32 *)(v + 0x70) = 0.449999988f;
    *(f32 *)(v + 0x74) = 0.25f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 1.30899692f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00138888892f;
    *(f32 *)(v + 0x210) = 1.0f;
    func_00458A70_3554D8(m, 0.00222222228f, 0.0833333358f, 0.00349065871f, 0.104719765f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(f32 *)(v + 0x30) = 1.0f;
        *(s16 *)(v + 0x34) = 1;
    }
    *(f32 *)(v + 0x40) = 0.5f;
    ok = 0;
    v[0x38] = 0;
    v[0x39] = 1;
    v[0x3E] = 1;
    v[0x5E] = 0;
    v[0x5F] = 0;
    *(s32 *)(v + 0x2F0) = 0;
    *(s16 *)(v + 0x2F4) = 0;
    *(s32 *)(v + 0x2F8) = 0;
    *(s32 *)(v + 0x340) = 0;
    *(s32 *)(v + 0x35C) = 0;
    if (*(s32 *)(v + 0x250) > 0) {
        Vt_3554D8 *vt = func_00438468_3554D8(0x19E1, 0x6C);
        *(s32 *)(v + 0x250) = -1;
        ok = 1;
        if (m[0x43] != 5) {
            func_00441C78_3554D8(m, 5, 0, 0);
        }
        v[0x25E] = 0x1A;
        v[0x25F] = 6;
        vt->fn(m);
    } else if (*(s32 *)(v + 0x350) != 0) {
        func_00441FB8_3554D8(m, 0x18, 5);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_004A6DF8_3554D8(m, 1);
        if (*(u8 **)(v + 0x360) != 0) {
            *(u16 *)(*(u8 **)(v + 0x360) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x360) + 0x34) &= ~0x1000;
            *(s32 *)(*(u8 **)(v + 0x360) + 0x98) = 0;
            func_004A6DF8_3554D8(*(u8 **)(v + 0x360), 1);
        }
    } else if (*(s32 *)(v + 0x344) != -1) {
        o = D_001E009C_3554D8 + (*(s32 *)(v + 0x344) << 8);
        if (*(s16 *)(o + 0xAA) == 0x19B1 || *(s16 *)(o + 0xAA) == 0x1AB4) {
            ok = 1;
        }
        func_00441FB8_3554D8(m, 3, 0);
        if (m[0x43] != 5) {
            func_00441C78_3554D8(m, 5, func_00440878_3554D8(0, 5), 0);
        }
    } else {
        func_00441FB8_3554D8(m, 7, 1);
        if (m[0x43] != 0x12) {
            func_00441C78_3554D8(m, 0x12, func_00440878_3554D8(0, 10), 0);
        }
    }
    if ((D_001D545C_3554D8 == 1 || D_001D545C_3554D8 == 0x60) && ok == 0) {
        o = func_00435E70_3554D8(0x1AA2, 0x80);
        *(u8 **)(v + 0x360) = o;
        func_00452E70_3554D8(o, m);
        *(u8 **)(v + 0x240) = *(u8 **)(v + 0x360);
    }
    return 0;
}
/* localdecomp:end func_003554D8 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355948);

