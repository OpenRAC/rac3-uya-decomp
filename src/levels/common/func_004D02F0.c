#include "common.h"

extern void func_004D02F0(s32);

extern s32 func_0012C908(s32);
extern s32 D_001D5520;
extern volatile s32 D_001E1280_003AB9E8[];
extern volatile s32 D_001E1284[];
void func_004D02F0(s32 a) {
    while (func_0012C908(0) == a && D_001D5520 == 0) {
    }
    D_001E1280_003AB9E8[0] = 1;
    D_001E1284[0] = 0;
}
