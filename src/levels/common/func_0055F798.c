#include "common.h"
extern s32 func_0066B3C0(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_006601C8(s32 a0, void *a1, s32 a2);
void func_0055F798(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_0066B3C0(a0, 0, 0, 250);
    x = a1;
    func_006601C8(r, &x, 4);
}
