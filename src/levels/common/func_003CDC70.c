#include "common.h"
extern s32 func_00431400(u8 *, s32, s32);
extern void func_003CE270(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_003CDC70(u8 *a0) {
    if (func_00431400(a0, -1, 0)) {
        func_003CE270(a0, 7, 0, 7825, 1, 1, 1, 0, 0x80C08020, 0.0f, 0.2f);
    }
}
