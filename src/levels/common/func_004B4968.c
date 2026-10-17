#include "common.h"

typedef struct {
    u8 pad0[1856];
    s32 w740;
    s32 w744;
    u8 pad748[0x25C0 - 0x748];
    s32 w25C0;
    s32 w25C4;
} S_4B4968;

extern S_4B4968 D_001A4BE0;
extern void func_00422FA0(s32, s32 *, s32 *, f32, f32, f32);

void func_004B4968(void) {
    S_4B4968 *s = &D_001A4BE0;
    s32 v = s->w25C4;
    if (v == 129 || v == 80) {
        func_00422FA0(s->w25C0, &s->w740, &s->w744, 0.17453292f, 0.026179941f, 0.034906588f);
    }
}
