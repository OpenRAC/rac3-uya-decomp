#include "common.h"

/* localdecomp:start func_00558F08 */
extern f32 D_001DFC0C;
extern f32 D_001DFC10;
extern s32 func_005B2498(s32);
extern void func_005B26D8(u8 *, f32, f32);
extern s32 func_00558E60(u8 *, s32);
extern f32 func_0058F400(u8 *);
extern void func_0058F5B0(u8 *, u8 *, f32);
void func_00558F08(u8 *o) {
    s32 i = 4;
    u8 *b = *(u8 **)(o + 0x68);
    s32 *k = (s32 *)(b + 0x10);
    u8 *v = b + 0xE0;
    do {
        if (func_005B2498(10) == 0) {
            func_005B26D8(v, D_001DFC0C, D_001DFC10);
        }
        if (func_00558E60(o, *k) != 0) {
            func_0058F5B0(v, v, func_0058F400(v) * 0.5f);
        }
v += 0x10; i--; k++;
    } while (i >= 0);
}
/* localdecomp:end func_00558F08 */
