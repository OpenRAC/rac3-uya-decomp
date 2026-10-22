#include "common.h"

/* localdecomp:start func_00362198 */
extern s32 func_00360D18(void *, void *);
extern s32 func_0041C398(void *);
extern f32 func_0041C8C0(void *, void *);
extern s16 func_0044FC98(s32, s32);
extern void func_004513D8(void *, s32, s32);
extern s32 func_00462678(void *);
extern s32 D_001D545C;
extern u8 *D_001DFACC;

s32 func_00362198(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 n, m, k;
    s32 off;

    if (func_00462678(o) != 0 && *(s32 *)(v + 0x374) == 0 && *(s16 *)(v + 0x2F6) == 0) {
        if (D_001D545C == 0x1D) {
            *(s32 *)(v + 0x30C) = -1;
        }
        *(s16 *)(v + 0x2F6) = func_0044FC98(0, 40);
    }
    if (*(s16 *)(v + 0x234) == 1) {
        if (func_0041C398(v + 0x2F6) != 0) {
            if (D_001D545C != 0x1D || *(s32 *)(v + 0x4D8) == 0) {
                func_004513D8(o, 11, 3);
                n = *(s32 *)(v + 0x30C);
                if (n != -1) {
                    func_004513D8(o, 9, -1);
                } else if ((m = *(s32 *)(v + 0x304)) != n) {
                    func_004513D8(o, 10, -1);
                } else if ((k = *(s32 *)(v + 0x38C)) != m && (off = k * 0x30, *(s16 *)(D_001DFACC + off + 0x32) != 0)) {
                    func_004513D8(o, 10, -1);
                } else if (*(s32 *)(v + 0x308) != 0 && v[0x5F] == 0) {
                    if (func_0041C8C0(o + 0x10, v + 0x320) > 0.5f) {
                        func_004513D8(o, 10, -1);
                    } else if (func_00360D18(o, v) != 0) {
                        func_004513D8(o, 18, -1);
                    } else {
                        func_004513D8(o, 13, -1);
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_00362198 */
