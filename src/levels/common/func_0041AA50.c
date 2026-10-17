#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; } M_41AA50;
extern void func_004898B8(M_41AA50 *, s32);
extern void func_00481400(M_41AA50 *, s32, s32);

void func_0041AA50(M_41AA50 *m) {
    if (m->b20 == 0) {
        func_004898B8(m, -1);
        func_00481400(m, 1, -1);
    }
}
