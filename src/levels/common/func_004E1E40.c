#include "common.h"

/* localdecomp:start func_004E1E40 */
typedef int s128 __attribute__((mode(TI)));

typedef union {
    s128 q;
    f32 f[4];
} V_004E1E40;

extern u8 D_001A4BE0[];
extern f32 func_004408C0(f32, f32);
extern void func_00437698(s32, s32, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_00464068(void *, void *, f32);
extern void func_00465020(void *, void *, f32, f32, s32);

void func_004E1E40(s32 count, s32 mode, s32 flag) {
    s32 i;
    u8 *g;
    V_004E1E40 a;
    V_004E1E40 b;
    s128 *v;

    for (i = 0; i < count; i++) {
        g = D_001A4BE0;
        v = (s128 *)(g + 272);
        if (mode == 0) {
            a.f[0] = *(f32 *)(g + 128) + func_004408C0(-0.1f, 0.1f);
            a.f[1] = *(f32 *)(g + 132) + func_004408C0(-0.1f, 0.1f);
            a.f[2] = *(f32 *)(g + 136) + func_004408C0(-0.5f, 0.1f);
        } else if (mode == 1) {
            if (!(i & 1)) {
                func_00437698(*(s32 *)(g + 9664), 0, &a);
            } else {
                func_00437698(*(s32 *)(g + 9664), 14, &a);
            }
        } else if (mode == 2) {
            if (!(i & 1)) {
                func_00437698(*(s32 *)(g + 9664), 23, &a);
            } else {
                func_00437698(*(s32 *)(g + 9664), 22, &a);
            }
        }
        b.q = *v;
        if (*(s32 *)(g + 9668) == 51) {
            func_0040BE90(&b, &b, 1.15f);
        } else {
            func_0040BE90(&b, &b, 0.7f);
        }
        b.f[0] += func_004408C0(-0.0066666673f, 0.0066666673f);
        b.f[1] += func_004408C0(-0.0066666673f, 0.0066666673f);
        b.f[2] += func_004408C0(-0.0166666675f, 0.0f);
        if (flag) {
            func_00464068(&a, (u8 *)*(s32 *)(g + 9664) + 192, *(f32 *)(g + 368) * func_004408C0(0.7f, 1.1f));
        } else {
            func_00465020(&a, &b, func_004408C0(4200.0f, 7350.0f), -1.0f, 0x88A0A0A0);
        }
    }
}
/* localdecomp:end func_004E1E40 */
