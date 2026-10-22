#include "common.h"

/* localdecomp:start func_00362AE0 */
extern f32 func_0041C8C0(void *, void *);
extern f32 func_0044FCE0(f32, f32);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern s32 func_00462650(void *);
extern void func_004685E8(void *, s32, s32, s32);
extern s32 *D_0021E2C0[];

s32 func_00362AE0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 *path;
    f32 d;
    if (func_00462650(o) != 0) {
        *(f32 *)(o + 0x48) = func_0044FCE0(0.85f, 1.15f);
        if (o[0x43] != 1) {
            func_00451098(o, 1, 0, (s32)func_0044FCE0(4.0f, 12.0f));
        }
    }
    if (o[0x60] & 2) {
        if (*(s32 *)(v + 0x300) != -1) {
            path = D_0021E2C0[*(s32 *)(v + 0x300)];
            func_004513D8(o, 2, -1);
            d = func_0041C8C0(o + 0x10, path + 4);
            if (func_0041C8C0(o + 0x10, (u8 *)path + path[0] * 16) < d) {
                func_004685E8(o, *(s32 *)(v + 0x300), 0, path[0] - 1);
            } else {
                func_004685E8(o, *(s32 *)(v + 0x300), path[0] - 1, 0);
            }
            return 1;
        }
        func_004513D8(o, 4, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00362AE0 */
