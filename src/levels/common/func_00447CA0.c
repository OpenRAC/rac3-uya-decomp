#include "common.h"

extern s32 func_00447C90_003BF5E0(s16);
extern u32 D_001E009C[];
extern u32 D_001E00A4[];
s32 func_00447CA0(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001E009C[0]) return 0;
    if (D_001E00A4[0] >= arg0) {
        return func_00447C90_003BF5E0(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
