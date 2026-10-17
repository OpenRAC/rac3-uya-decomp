#include "common.h"

extern void func_00419970(u8 *, s32, s32);
extern void func_0030F930(u8 *);
extern void func_0030FF70(u8 *);
extern void func_00310030(u8 *);
extern void func_0030FC10(u8 *);

void func_003100F0(u8 *m) {
    u8 *p;

    func_00419970(m, 1, -1);
    m[48] = 255;
    p = *(u8 **)(m + 104);
    if (*(s32 *)p >= 0 && p[51] < 16) {
        *(s32 *)p = -1;
    }
    func_0030F930(p);
    func_0030FF70(p);
    func_00310030(p);
    func_0030FC10(p);
}
