#include "common.h"
extern void func_0040BBA8(void *, s32, s32);
extern void func_00437350(s32, s32, void *);
void func_003660C0(s32 a, s32 *b, s32 *c, void *buf, s32 e) {
    *b = 0;
    *c = 0;
    func_0040BBA8(buf, 0, 64);
    func_00437350(a, e, buf);
}
