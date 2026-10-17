#include "common.h"

extern void func_004CF530(s32 *);

extern void func_0013D0C0(s32 *);
void func_004CF530(s32 *p) {
    func_0013D0C0(p);
    p[0] = 0;
    p[0x30 / 4] = 0;
    p[0x38 / 4] = 0;
    p[0x3C / 4] = 0;
    p[0x44 / 4] = 0;
    p[0x50 / 4] = 0;
    p[0x58 / 4] = 0;
    p[0x5C / 4] = 0;
}
