#include "common.h"

/* localdecomp:start func_00362920 */
extern u8 *D_001DFE1C[];
extern f32 *func_0044FB48(u8 *, s32);
extern s32 func_00451DB8(s32, s32, s32);
extern void func_004513D8(void *, s32, s32);

s32 func_00362920(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 ok = 1;
    s32 id = *(s32 *)(v + 0x310);
    s32 none;
    s32 id2;
    if (id != -1) {
        u8 *m = D_001DFE1C[0] + (id << 8);
        if (m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD) {
            f32 *f = func_0044FB48(m, id);
            if (f == 0 || *f > 0.0f) {
                ok = 0;
            }
        }
    }
    none = -1;
    id2 = *(s32 *)(v + 0x314);
    if (id2 != none) {
        if (func_00451DB8(id2, -1, 1) != 0) {
            ok = 0;
        }
    }
    if (ok != 0 || *(s16 *)(v + 0x234) == 1) {
        *(s32 *)(v + 0x310) = none;
        *(s32 *)(v + 0x314) = none;
        *(s32 *)(v + 0x2E0) = *(s32 *)(v + 0x2E8);
        func_004513D8(o, 1, 1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_00362920 */
