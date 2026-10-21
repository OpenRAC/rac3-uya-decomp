#include "common.h"

/* localdecomp:start func_003624D0 */
extern s32 func_0044FC98(s32, s32);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern void func_00451EC8(s32, s32);
extern s32 func_00462678(void *);
extern s32 D_001D545C;
extern u8 *D_001DFACC[];

s32 func_003624D0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 one = 1;
    s32 k;
    s32 off;

    if (*(s16 *)(v + 0x234) != one && func_00462678(o) == 0) {
        if (o[0x21] != 0xFF) {
            func_00451EC8(o[0x21], 0);
        }
        if (*(s32 *)(v + 0x30C) == -1) {
            if (o[0x43] != 2) {
                func_00451098(o, 2, 0, 10);
            }
            func_004513D8(o, 4, 2);
            if (*(s32 *)(v + 0x318) != 0) {
                func_004513D8(o, 7, -1);
            }
            if (*(s32 *)(v + 0x4E4) != 0) {
                if (o[0x43] != one) {
                    func_00451098(o, 1, 0, 10);
                }
                func_004513D8(o, 4, 2);
            }
        } else {
            if (o[0x43] != 0) {
                func_00451098(o, 0, 0, 10);
            }
            func_004513D8(o, 6, 2);
        }
        *(s32 *)(v + 0x2F0) = func_0044FC98(0x244, 0x258);
        return 1;
    }
    if (D_001D545C == 0x1D && *(s32 *)(v + 0x4D8) != 0) {
        k = *(s32 *)(v + 0x4D4);
        if (k != -1) {
            off = k * 0x30;
            if (*(s16 *)(D_001DFACC[0] + off + 0x32) != 0) {
                if (o[0x43] != 3) {
                    func_00451098(o, 3, 0, 10);
                }
                func_004513D8(o, 10, 4);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003624D0 */
