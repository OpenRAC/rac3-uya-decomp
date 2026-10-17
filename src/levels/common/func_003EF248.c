#include "common.h"
extern u8 D_002A4440[];
extern u8 D_001DF800[];
extern void func_0040BBD0(void *, s32);
void func_003EF248(void) {
    s32 size = D_002A4440 - D_001DF800;
    if ((size & 0xF) == 0 && ((u32)D_001DF800 & 0xF) == 0) {
        func_0040BBD0(D_001DF800, size);
    } else {
        s32 i;
        for (i = 0; i < D_002A4440 - D_001DF800; i++) {
            D_001DF800[i] = 0;
        }
    }
}
