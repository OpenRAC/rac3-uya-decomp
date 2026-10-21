#include "common.h"

/* localdecomp:start func_003644F0 */
extern s32 func_00360D18(void *, void *);
extern f32 func_0041C8C0(void *, void *);
extern s32 func_0044FC98(s32, s32);
extern f32 func_0044FCE0(f32, f32);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern s32 func_0045A4A8(void *, f32);
extern s32 func_00462650(void *);
extern s32 D_001D545C;
extern u8 *D_001DFACC[];

s32 func_003644F0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 n, k;
    s32 off;

    if (func_00462650(o) != 0) {
        if (o[0x43] != 0x13) {
            func_00451098(o, 0x13, 0, func_0044FC98(6, 10));
        }
        *(f32 *)(o + 0x48) = func_0044FCE0(0.9f, 1.5f);
    }
    if (func_0045A4A8(o, 50.0f) != 0) {
        n = *(s32 *)(v + 0x304);
        if (n != -1 || func_00360D18(o, v) != 0) {
            func_004513D8(o, 10, -1);
            if (func_0041C8C0(o + 0x10, v + 0x320) != 0.0f) {
                if (o[0x43] != 4) {
                    func_00451098(o, 4, 0, 15);
                }
                func_004513D8(o, 13, -1);
            }
        } else {
            k = *(s32 *)(v + 0x38C);
            if (k != n && (off = k * 0x30, *(s16 *)(D_001DFACC[0] + off + 0x32) != 0)) {
                func_004513D8(o, 10, -1);
            } else {
                func_004513D8(o, 11, -1);
                if (func_0041C8C0(o + 0x10, v + 0x220) < 17.0f) {
                    if (o[0x43] != 4) {
                        func_00451098(o, 4, 0, 10);
                    }
                    func_004513D8(o, 13, -1);
                }
            }
        }
        if (o[0x95] == 4) {
            func_004513D8(o, 10, -1);
        }
        if (*(s32 *)(v + 0x4E8) != 0 || (D_001D545C == 16 && *(s32 *)(v + 0x4E4) != 0)) {
            func_004513D8(o, 13, -1);
            return 2;
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_003644F0 */
