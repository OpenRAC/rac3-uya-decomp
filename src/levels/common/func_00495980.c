#include "common.h"

void func_00495980(void *arg0) {
    f32 var_f0;
    f32 var_f1;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1C));
    var_f0 = 0.0048076925f;
    switch (temp_v1) {
    case 1:
        var_f1 = -1.0f;
        break;
    case 3:
        var_f1 = -1.0f;
        var_f0 = 0.01923077f;
        break;
    case 2:
        var_f1 = 1.0f;
        break;
    case 4:
        var_f1 = 1.0f;
        var_f0 = 0.01923077f;
        break;
    default:
        var_f1 = 0.0f;
        break;
    }
    (*(f32 *)((u8 *)(arg0) + 0x58)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x58)) + (var_f1 * var_f0));
}
