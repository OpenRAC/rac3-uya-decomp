#include "common.h"

extern void func_004C8C60();
extern void *func_004C9B50();
extern void *func_0051DC40(s32, void *);

void func_004C9410(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    func_004C8C60();
    if (arg2 != 0) {
        temp_v0 = func_0051DC40(0x10, func_004C9B50((*(s32 *)((u8 *)(arg0) + 0x20))));
        (*(void **)((u8 *)(arg0) + 0x28)) = temp_v0;
        (*(s32 *)((u8 *)(temp_v0) + 4)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 8)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0xC)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0)) = 0;
    }
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 0)) = 0;
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 4)) = 0;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 0)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 4)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 0)) = 64.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 4)) = 64.0f;
    (*(s8 *)((u8 *)(arg0) + 0x2C)) = 0;
}
