#include "common.h"
extern void func_0058F1B0(void *, void *, s32);
extern void func_0066E190(void *);
s32 func_006751A0(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 buf[12];
    func_0058F1B0(buf, a3, 12);
    func_0066E190(buf);
    return 12;
}
