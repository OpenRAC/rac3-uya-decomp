#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_0034BD48(u128_t *a0, u8 *a1, s32 a2, s32 a3, s32 t0, f32 f12);
extern void func_00409BD8(u8 *a0, s32 a1, u128_t *a2);
extern s32 func_003CF910(u128_t *a0, s32 a1, u8 *a2, s32 a3, f32 f12);
extern void func_004E31A8(u8 *a0, u128_t *a1, u8 *a2, s32 a3);
void func_0034BC88(u8 *a0, s32 a1, s32 a2, s32 a3, u128_t *t0, s32 t1, f32 f12, f32 f13) {
    u128_t m[3];
    u128_t pos;
    s32 r;
    func_0034BD48(m, a0, a1, a2, t1, f12);
    if (a3 < 0) {
        if (t0 != 0) {
            pos = *t0;
        } else {
            pos = *(u128_t *)(a0 + 16);
        }
    } else {
        func_00409BD8(a0, a3, &pos);
    }
    r = func_003CF910(&pos, 0, a0, 0, f13);
    if (r != 0) {
        func_004E31A8(a0, m, a0 + 16, r);
    }
}
