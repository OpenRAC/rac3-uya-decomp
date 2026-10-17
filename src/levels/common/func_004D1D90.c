#include "common.h"

extern s32 func_004D1D90();
extern u8 *D_001E1264[];

extern void func_004D0EE8(void *);
extern u8 *D_001E1264[];

s32 func_004D1D90(void) {
    func_004D0EE8(D_001E1264[0] + 0x48);
    return 1;
}
