#include "common.h"

extern s32 func_00511FE0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 func_00511FE0(s32 *, s32, s32, s32, s32, s32);

extern void func_00512020(void *);
s32 func_00511FE0(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e) {
    p[1] = a;
    p[2] = b;
    p[3] = c;
    p[4] = d;
    p[5] = e;
    func_00512020(p);
    return (s32)p;
}
