#include "common.h"

extern void func_004D2370(s32, s32);

typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_00251370[];
extern void func_004D2370(s32, s32);
extern s32 func_004181A0(s32); extern s32 func_0011BB58(void *, s32, s32);
extern void func_004D4958(f32);
s32 func_004D73A0(void) {
    func_004D2370(0, 0);
    func_0011BB58(D_00251370, func_004181A0(0x14D7), 0x40);
    D_00251370[0].w40 = 0xB4;
    D_00251370[0].w44 = 0;
    func_004D4958(1.0f);
    return 1;
}
