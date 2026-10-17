#include "common.h"

typedef struct {
    f32 x, y, z, w;
} V_4B77C8;

extern u8 D_001E28C0[];
extern void func_004528F8(V_4B77C8 *, s32, s32, u8 *);
extern f32 func_0041C8F0(V_4B77C8 *, u8 *);

s32 func_004B77C8(s32 a0, s32 a1, f32 r) {
    V_4B77C8 v;
    func_004528F8(&v, a0, a1, D_001E28C0);
    return r * r < func_0041C8F0(&v, D_001E28C0);
}
