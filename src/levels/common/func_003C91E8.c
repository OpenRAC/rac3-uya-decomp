#include "common.h"

/* localdecomp:start func_003C91E8 */
extern u8 D_001E2AC0[];
extern s32 func_0044FCD0(u8 *, u8 *, s32, s32, s32);
extern void func_0044CB08(u8 *, u8 *, s32, s32);
extern f32 func_0040C018(u8 *, u8 *);
extern void func_00444188(u8 *);
extern void func_0044B5C8(u8 *, u8 *, s32, f32, f32);
void func_003C91E8(u8 *moby) {
    u8 *vars;
    u8 *other;
    u8 *p;
    if (moby[32]) {
        other = 0;
        vars = *(u8 **)(moby + 104);
        p = *(u8 **)(*(u8 **)(moby + 184) + 184);
        if (p) {
            other = *(u8 **)(p + 104);
        }
        if (other == 0 || other[148] == 0) {
            if (func_0044FCD0(moby, vars + 208, 0, 1, 0)) {
                *(s16 *)(vars + 54) = 90;
            }
        } else {
            moby[168] = 255;
        }
        if (*(u8 **)(vars + 1360)) {
            *(unsigned long *)(*(u8 **)(vars + 1360) + 56) = *(unsigned long *)(moby + 56);
            func_0044CB08(moby, *(u8 **)(vars + 1360), 0, 0);
            if ((*(u8 **)(vars + 1360))[49]) {
                if (func_0040C018(D_001E2AC0, *(u8 **)(vars + 1360) + 16) < 576.0f) {
                    func_00444188(*(u8 **)(vars + 1360));
                    (*(u8 **)(vars + 1360))[111] = 22;
                }
            }
        }
        if (moby[49]) {
            if (func_0040C018(D_001E2AC0, moby + 16) < 576.0f) {
                func_00444188(moby);
                moby[111] = 22;
            }
        }
        func_0044B5C8(moby, vars + 1232, 0, 0.03f, 0.3f);
    }
}
/* localdecomp:end func_003C91E8 */
