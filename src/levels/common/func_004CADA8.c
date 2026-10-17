#include "common.h"

extern s32 func_004CAB30(void *);

void func_004CADA8(void *arg0) {
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_004CAB30(arg0);
            break;
        case 2:
            func_004CADA0(arg0);
            break;
        }
        func_004CAB28(arg0);
    }
}
