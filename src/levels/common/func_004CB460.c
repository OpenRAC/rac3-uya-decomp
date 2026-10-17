#include "common.h"
extern void func_003FFAC8();
extern void func_004CAE20(void *);
extern void func_004CB458(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_004CB460;
extern S_004CB460 D_001E7600[];

void func_004CB460(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_001E7600->fB0;
        D_001E7600->fB0 = 0.62f;
        func_003FFAC8();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {
        case 0:
            func_004CAE20(arg0);
            break;
        case 2:
            func_004CB458(arg0);
            break;
        }
        D_001E7600->fB0 = temp_f20;
        func_003FFAC8();
    }
}
