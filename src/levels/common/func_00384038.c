#include "common.h"

extern s32 D_001DDDCC;
extern void func_00383FC8(s32, void *);
extern void func_004076F8(void *, s32, s32);

void func_00384038(s32 a0) {
    s32 buf[4];
    func_00383FC8(a0, buf);
    func_004076F8(buf, D_001DDDCC, 0);
}
