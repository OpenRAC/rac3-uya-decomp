#include "test_common.h"

/* These 6 are accessed via absolute (non-gp-relative) addressing in the real
 * binary -- plain externs already reproduce this correctly under -G0. */
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D4CEC;
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430;

/* These 4 ARE gp-relative in the real binary. GAS docs (MIPS Small Data):
 * ".extern sym,size" tells the assembler the object's size so it can be
 * classified as small-data (gp-relative) even though it's defined elsewhere.
 * Emitting this directive lets GCC's own emitted .lw/.sw for these symbols
 * get assembled as gp-relative without needing -G high enough to also catch
 * the 6 symbols above (which must stay absolute since that's what the real
 * binary does for them). */
__asm__(".extern D_001D6DA4, 4");
__asm__(".extern D_001D6D9C, 4");
__asm__(".extern D_001D6DA0, 4");
__asm__(".extern D_001D6DA8, 4");

extern s32 D_001D6DA4;
extern s32 D_001D6D9C;
extern s32 D_001D6DA0;
extern s32 D_001D6DA8;

s32 func_0039BEC0(s32 screenId, s32 mode, s32 arg2, s32 arg3, u8 *outPtr) {
    s32 result;
    s32 idx;
    u8 flag;

    if (outPtr != 0) {
        *outPtr = 0;
    }

    result = ((D_001D5B90 ^ -2) == 0) ? 0 : -1;

    if (mode == 1) {
        result = (D_001D6DA4 < 8) ? screenId : result;
    }

    flag = 0;
    if (screenId >= 0) {
        flag = D_001D5B78[screenId];
    }
    if (flag != 0) {
        result = -3;
    }

    if (D_001A7430 == 0) {
        if (D_001D5B94 != 0) {
            result = -1;
        } else if ((D_001D4CEC & 1) == 0) {
            result = -1;
        }
    }

    if (result == 0) {
        D_001D5B90 = screenId;
        D_001D6D9C = arg2;
        D_001D6DA0 = arg3;
        D_001D6DA8 = (s32)outPtr;
        if (mode == 1) {
            idx = D_001D6DA4;
            D_001DA050[idx] = D_001D5B94;
            D_001D6DA4 = idx + 1;
        }
    }
    return result;
}
