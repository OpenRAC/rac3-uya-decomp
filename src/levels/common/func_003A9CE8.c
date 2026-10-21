#include "common.h"

/* localdecomp:start func_003A9CE8 */
extern u8 D_001A4C60[];
extern u8 *D_001E009C;
extern s32 func_00440760(void *, s32, s32);
extern s32 func_00453210(void *, s32);
extern s32 func_00442998(s32, s32, s32);
extern f32 *func_00440728(u8 *);

s32 func_003A9CE8(s32 a0, u8 *p) {
    u8 *o;
    f32 *v;

    if (*(s32 *)(p + 0xC20) != -1 && func_00440760(D_001A4C60, *(s32 *)(p + 0xC20), 0) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC24) != -1 && func_00453210(D_001A4C60, *(s32 *)(p + 0xC24)) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xD28) != -1 && func_00442998(*(s32 *)(p + 0xD28), -1, 0) <= *(s16 *)(p + 0xD2C)) {
        return 1;
    }
    if (*(s32 *)(p + 0xD24) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC28) != -1) {
        o = D_001E009C + (*(s32 *)(p + 0xC28) << 8);
        if (o == 0 || o[0x20] == 254) {
            return 1;
        }
        if (o[0x20] == 253) {
            return 1;
        }
        v = func_00440728(o);
        if (v != 0 && *v <= 0.0f) {
            return 1;
        }
    }
    if (*(s32 *)(p + 0xC2C) != -1 && func_00442998(*(s32 *)(p + 0xC2C), -1, 1) == 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003A9CE8 */
