#include "common.h"
typedef struct { s32 p0; s32 p4; s32 w8; } S_1A5E50;
extern S_1A5E50 D_001A5E50;
extern s32 func_0066AF80(u8 *, u8, u8);
extern void func_0061BA40(u8 *, s32);
void func_0066B030(u8 *a0, u8 a1, u8 a2) {
    if (func_0066AF80(a0, a1, a2)) {
        a0[80] = a1;
        if (*(s32 *)(a0 + 52) != D_001A5E50.w8) {
            *(s32 *)(a0 + 52) = D_001A5E50.w8;
            *(s32 *)(a0 + 4) = D_001A5E50.w8;
            func_0061BA40(a0, 0);
        }
    }
}
