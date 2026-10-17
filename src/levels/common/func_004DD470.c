#include "common.h"

extern u8 D_001A605F[];
extern void func_004DD4B0(s32, s32, s32, s32);
extern void func_004F11B8(s32, s32, s32);

void func_004DD470(void) {
    func_004DD4B0(D_001A605F[0], 0, 1, 50);
    func_004F11B8(27, 7, 0);
}
