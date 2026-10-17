#include "common.h"

extern void func_004948D8();

extern s32 D_001D92F4;
extern s32 D_001D92F8;
void func_004948D8(s32 a0, s32 a1) {
    D_001D92F4 = 0x40;
    D_001D92F8 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D92F4 = a0;
    }
    D_001D92F8 = a1;
}
