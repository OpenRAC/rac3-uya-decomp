#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);
extern void func_00438908(u8 *, s32, s32, s32);
extern void func_00437698(u8 *, s32, u8 *);
extern void func_00441C78(u8 *, s32, s32, s32);
extern void func_00439610(u8 *);

u8 *func_002FFB70(u8 *a0, f32 f) {
    u8 *m = func_00435E70(209, 128);
    if (m != 0) {
        u32 *v = *(u32 **)(m + 104);
        ((f32 *)v)[1] = f;
        v[0] = (u32)a0;
        m[49] = 0;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        func_00438908(m, 128, 128, 128);
        func_00437698(a0, 0, m + 16);
        *(s128 *)(m + 192) = *(s128 *)(a0 + 192);
        *(s128 *)(m + 208) = *(s128 *)(a0 + 208);
        *(s128 *)(m + 224) = *(s128 *)(a0 + 224);
        if (m[67] != 0) {
            func_00441C78(m, 0, 0, 10);
        }
        func_00439610(m);
        m[32] = 0;
        m[49] = 0;
        *(u16 *)(m + 52) |= 5;
    }
    return m;
}
