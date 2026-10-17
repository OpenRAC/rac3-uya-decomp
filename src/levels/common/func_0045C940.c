#include "common.h"

extern s32 func_0045C8A8(s32, s32, s32);
extern s32 func_0045C940();

extern s32 func_0045C8A8(s32, s32, s32);
extern s32 D_001CCFD0_0039D5A8[];
s32 func_0045C940(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 r = func_0045C8A8(a0, a1, a2);
    if (r != 0) {
    D_001CCFD0_0039D5A8[6] = a3;
    D_001CCFD0_0039D5A8[7] = a4;
    }
    return r;
}
