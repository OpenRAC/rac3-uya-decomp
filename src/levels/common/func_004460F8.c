#include "common.h"
extern s32 D_0021D940[];
extern void func_00446148(s32 a0, s32 a1, s16 a2, s16 a3);
void func_004460F8(s32 a0, s32 a1, s16 a2, s16 a3) {
    if (a1 != -1) {
        s32 x = D_0021D940[a1];
        if (x) {
            func_00446148(a0, x, a2, a3);
        }
    }
}
