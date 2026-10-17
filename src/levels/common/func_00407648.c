#include "common.h"

extern void func_00407648();

typedef int u128_3D3EE0 __attribute__((mode(TI)));
extern void func_004075A8(void *, s32, s32, long);
void func_00407648(u8 *p, s32 a1, s32 a2, f32 *src, u128_3D3EE0 *q, s32 a5) {
    s32 i;
    f32 *fp;
    s32 *ip;
    func_004075A8(p, a1, a5, 0x80);
    ip = (s32 *)(p + 0x40);
    fp = (f32 *)(p + 0x54);
    for (i = 0; i < 4; i++) {
        fp[i * 2 - 1] = src[i * 2];
        fp[i * 2] = src[i * 2 + 1];
        ip[i] = a2;
        ((u128_3D3EE0 *)p)[i] = q[i];
    }
}
