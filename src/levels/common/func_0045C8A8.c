#include "common.h"

extern s32 func_0045C8A8(s32, s32, s32);

s32 func_0013CD28(s32, s32, s32, void *);             /* extern */
typedef struct { u8 pad0[0x4]; s16 f4; u8 pad6[0x2]; s32 f8; u8 padC[0x4]; s32 f10; s32 f14; s32 f18; s32 f1C; } S_001CCFD0_0039D510_0039D510;
extern S_001CCFD0_0039D510_0039D510 D_001CCFD0_0039D510[];

s32 func_0045C8A8(s32 arg0, s32 arg1, s32 arg2) {
    if ((D_001CCFD0_0039D510->f4 == 0) && (arg2 != 0)) {
        D_001CCFD0_0039D510->f18 = 0;
        D_001CCFD0_0039D510->f1C = 0;
        if (func_0013CD28(arg1, arg2, arg0, (u8 *)D_001CCFD0_0039D510 + 0x40) != 0) {
            D_001CCFD0_0039D510->f14 = arg0;
            D_001CCFD0_0039D510->f4 = 1;
            D_001CCFD0_0039D510->f8 = arg1;
            D_001CCFD0_0039D510->f10 = arg2;
            return arg2 << 0xB;
        }
    }
    return 0;
}
