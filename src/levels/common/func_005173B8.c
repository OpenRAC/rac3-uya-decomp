#include "common.h"

extern s32 func_005173B8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);

typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001DC250_003E6F50;
extern V16_003E6F50 D_001DC150_003E6F50;
s32 func_005173B8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001DC250_003E6F50) != 0) {
        v = D_001DC150_003E6F50;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
