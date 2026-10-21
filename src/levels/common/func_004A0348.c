#include "common.h"

/* localdecomp:start func_004A0348 */
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001E0DF0[8];
extern f32 D_001E0E00;
extern f32 D_001E0E04;
extern volatile f32 D_001E0E08;
extern u8 D_001E0E10[];
extern void func_0040BE48(void *, void *);
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(s32, s32, f32);
void func_004A0348(void *a, f32 t) {
    f32 v[4];
    f32 x, y, z;
    *(u128_3CB958 *)D_001E0DF0 = *(u128_3CB958 *)a;
    func_0040BE48(v, a);
    func_0040BE90((f32 *)D_001E0E10, D_001E0DF0, t);
    x = v[0]; y = v[1]; z = v[2];
    if (x < y) {
        if (x < z) {
            D_001E0E00 = x;
            D_001E0E04 = z;
            D_001E0E08 = y;
        } else {
            goto A;
        }
    } else if (y < z) {
        D_001E0E00 = z;
        D_001E0E04 = y;
        D_001E0E08 = x;
    } else {
A:
        D_001E0E00 = y;
        D_001E0E04 = x;
        D_001E0E08 = z;
    }
    func_0040BF20(&D_001E0E00, &D_001E0E00, D_001E0DF0);
    func_0040C0F0((s32)&D_001E0E00, (s32)&D_001E0E00, 1.0f);
}
/* localdecomp:end func_004A0348 */
