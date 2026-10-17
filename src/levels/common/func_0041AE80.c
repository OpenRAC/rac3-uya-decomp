#include "common.h"

extern void *func_0053ED70(void *a, s32 b, s32 c);
extern void func_00532320(void *a, void *b, s32 n);

void func_0041AE80(void *moby, s32 type, s32 val, f32 f) {
    u8 c[16];
    struct {
        f32 f;
        s32 i;
        s32 p;
    } buf;
    void *pvars = *(void **)((u8 *)moby + 104);
    void *msg = func_0053ED70(moby, 0, 0);
    buf.f = f;
    func_00532320(msg, &buf.f, 4);
    buf.i = val;
    func_00532320(msg, &buf.i, 4);
    buf.p = *(s32 *)((u8 *)pvars + 80);
    func_00532320(msg, &buf.p, 4);
    c[0] = type;
    func_00532320(msg, c, 1);
}
