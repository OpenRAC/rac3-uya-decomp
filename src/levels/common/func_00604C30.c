#include "common.h"

extern s32 D_0024145C[];
extern s32 *D_002412A0[];
extern void func_006037F8(void *, s32);
extern void func_00604CC8(void *, s32);

void func_00604C30(u8 *arg0) {
    s32 i;

    if (D_0024145C[0] != 39) {
        for (i = 0; i < *D_002412A0[0]; i++) {
            func_006037F8(arg0 + 6304 + i * 2896, i);
            func_00604CC8(arg0, i);
        }
    }
}
