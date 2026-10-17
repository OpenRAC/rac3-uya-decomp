#include "common.h"

extern u32 func_004B4A68(s32, u32);
extern s32 D_001DAB50;
extern s32 D_001DAB58;

extern u32 D_001DAB60_003A32E0;
extern u32 D_001DAB54_003A32E0;
extern s32 D_001DAB50;
extern s32 D_001DAB58;
u32 func_004B4A68(s32 arg0, u32 arg1) {
    s32 temp_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_6;
    u32 var_2;
    u32 var_3;
    temp_2 = D_001DAB60_003A32E0;
    temp_6 = D_001DAB54_003A32E0;
    temp_4 = (arg0 + 0x3F) & 0xFFFFFFC0;
    if (temp_2 < temp_6) {
        if (temp_6 < (u32) (temp_2 + temp_4)) {
            D_001DAB60_003A32E0 = temp_6;
        }
        temp_2_2 = D_001DAB60_003A32E0;
        if (temp_2_2 < temp_6) {
            goto A;
        }
    }
    var_2 = (D_001DAB60_003A32E0 - D_001DAB54_003A32E0) + D_001DAB58;
    goto done;
A:
    var_2 = temp_2_2 + D_001DAB50;
done:
    var_3 = var_2 % arg1;
    if (var_3 != 0) {
        var_3 = arg1 - var_3;
        var_2 += var_3;
    }
    D_001DAB60_003A32E0 = (u32) (D_001DAB60_003A32E0 + (temp_4 + var_3));
    return var_2;
}
