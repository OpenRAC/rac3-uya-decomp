#include "common.h"

typedef void (*Fn_003B52B0)(u8 *, s32);

extern u8 *func_00326510(s32);
extern void func_003B5048(u8 *, u8 *, s32);

u8 *func_003B52B0(u8 *a0, s32 *a1, s32 a2, s32 a3, Fn_003B52B0 *cb) {
    u8 *r;

    r = func_00326510(a3);
    if (r == 0) {
        return 0;
    }
    func_003B5048(a0, r, a2);
    (*cb)(r, a2);
    if (a3 == a1[0]) {
        a1[48]++;
        if (a1[71] == 0) {
            *(u8 **)&a1[71] = r;
        }
    }
    return r;
}
