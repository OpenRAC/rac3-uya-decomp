#include "common.h"

/* localdecomp:start func_00558228 */
typedef struct {
    s32 count;
    u8 pad4[0xC];
    s32 ids[8];
} L_558228;

extern f32 D_001DFB88;
extern s32 D_002638C0[];
extern s32 func_00582000(u8 *, s32, u8 *, s32, f32);
extern s32 func_005579C0(s32, u8 *, s32);

void func_00558228(u8 *pos, L_558228 *out, s32 who) {
    s32 n;
    s32 i;

    i = 0;
    n = func_00582000(pos + 0x10, 0, pos, 0, D_001DFB88);
    out->count = 0;
    for (; i < n; i++) {
        if (func_005579C0(who, pos, D_002638C0[i]) != 0) {
            out->ids[out->count] = D_002638C0[i];
            out->count++;
            if (out->count >= 8) {
                break;
            }
        }
    }
}
/* localdecomp:end func_00558228 */
