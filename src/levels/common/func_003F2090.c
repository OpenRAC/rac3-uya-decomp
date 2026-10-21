#include "common.h"

/* localdecomp:start func_003F2090 */
extern void func_0040C0F0(s32 a, s32 b, f32 x);
extern void func_003F1D30();
typedef int u128_t __attribute__((mode(TI)));

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_001E2AC0_0037F588[];
extern void func_00447580();
extern void func_003F1F28(s32);
extern void func_003F2000(s32);
extern void func_003F2058(s32);
void func_003F2090(u8 *o) {
    s32 idx = *(s32 *)(o + 0x94);
    u8 *p = D_001E2AC0_0037F588 + idx * 0x460;
    E_37F588 *e = (E_37F588 *)(p + 0x2A0);
    u128_t v[3];
    if (e->f0 == 1) {
        if (e->b3 == 0) {
            *(u128_t *)(p + 0x2F0) = *(u128_t *)(o + 0x30);
            func_00447580(p + 0x300, o);
        } else if (e->b3 == 2) {
            *(u128_t *)(p + 0x360) = *(u128_t *)(o + 0x30);
            func_00447580(p + 0x370, o);
            func_003F1F28(idx);
        } else {
            func_0040C0F0((s32)&v[0], *(s32 *)(p + 0x240) + 0xC0, 1.0f);
            func_0040C0F0((s32)&v[1], *(s32 *)(p + 0x240) + 0xD0, 1.0f);
            func_0040C0F0((s32)&v[2], *(s32 *)(p + 0x240) + 0xE0, 1.0f);
            func_003F1D30(p + 0x310, o + 0x30, *(s32 *)(p + 0x50) + 0x30, &v[0], &v[1], &v[2]);
            func_00447580(p + 0x350, o);
            *(u128_t *)(p + 0x370) = *(u128_t *)(p + 0x350);
        }
    } else if (e->b3 == 2) {
        func_003F2000(idx);
        func_003F1F28(idx);
    } else if (e->b3 == 1) {
        func_003F2000(idx);
        *(u128_t *)(p + 0x350) = *(u128_t *)(p + 0x370);
    } else if (e->b3 == 0) {
        func_003F2058(idx);
    }
    e->f0 = 3;
    e->b2 = e->b3;
    if (e->b2 == 0) {
        A_37F588 *q = &e->a;
        q->f10 = q->f1C;
        q->f14 = q->f18;
        q->f1C = 0;
        e->q40 = e->q50;
        e->a.f0 = q->fC;
        q->fC = 0;
        q->f4 = q->f8;
        e->q30 = e->q60;
    } else {
        R_37F588 *r = &e->r;
        s32 n = r->f14 + 1;
        r->f14 = n;
        r->fC = n;
        r->f10 = 1.0f / (f32)n;
    }
}
/* localdecomp:end func_003F2090 */
