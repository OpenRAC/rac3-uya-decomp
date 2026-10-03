#include "common.h"

void func_00495A48(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_2_2;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 temp_5;
    s32 var_3;
    temp_f1 = *((f32 *) (((u8 *) arg0) + 0x58));
    temp_f0 = *((f32 *) (((u8 *) arg0) + 0x54));
    if ((temp_f0 < temp_f1) || (temp_f1 < (-temp_f0))) {
        temp_3 = *((s32 *) (((u8 *) arg0) + 0x1C));
        switch (temp_3) {
        case 3:
        case 1:
            temp_2 = (*((s32 *) (((u8 *) arg0) + 4))) + 1;
            *((s32 *) (((u8 *) arg0) + 4)) = temp_2;
            var_3 = temp_2;
            break;
        default:
            temp_2_2 = (*((s32 *) (((u8 *) arg0) + 4))) - 1;
            *((s32 *) (((u8 *) arg0) + 4)) = temp_2_2;
            var_3 = temp_2_2;
            break;
        }
        temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
        temp_5 = (var_3 > (-1)) ? (var_3) : (0);
        *((f32 *) (((u8 *) arg0) + 0x58)) = 0.0f;
        *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
        *((s32 *) (((u8 *) arg0) + 4)) = (s32) ((temp_5 < temp_4) ? (temp_5) : (temp_4 - 1));
    }
}
