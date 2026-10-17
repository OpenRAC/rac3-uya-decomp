#include "common.h"
extern s16 D_001E1B90;
extern void func_003633F8();
extern void func_00402498(void *, void *);
void func_00365450(void *a0) {
    s32 i;
    if (D_001E1B90 > 0) {
        for (i = 0; i < 10; i++) {
            if ((&D_001E1B90)[i] > 64) {
                (&D_001E1B90)[i] = 64;
            }
            (&D_001E1B90)[i] -= 8;
        }
        func_00402498(func_003633F8, a0);
    }
}
