#include "common.h"

/* localdecomp:start func_00362688 */
extern void func_003192D8(void *, s32, void *);
extern s32 func_00360D18(void *, void *);
extern void func_00361540(void);
extern void func_00361560(void *);
extern f32 func_0041C8C0(void *, void *);
extern s32 func_0044FC98(s32, s32);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern s32 func_0045A4A8(void *, f32);
extern s32 func_00460800(void *, void *);
extern u8 *D_001DFACC;

s32 func_00362688(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 fl;
    s32 k;
    s32 off;

    if (*(f32 *)(v + 0x30) <= 0.0f) {
        *(f32 *)(v + 0x194) = *(f32 *)(v + 0x190) = 1.25f;
    }
    *(f32 *)(v + 0x80) = 0.78539819f;
    fl = func_00460800(o, v + 0x160);
    *(f32 *)(v + 0x80) = 1.4835298f;
    if ((fl & 1) || (o[0x42] == 0x15 && func_0045A4A8(o, 23.0f) != 0) ||
        (*(f32 *)(v + 0x30) <= 0.0f && *(u16 *)(o + 0x96) >= 0x79)) {
        func_00361560(o);
        func_003192D8(o, 0, func_00361540);
        return 5;
    }
    if (fl & 2) {
        if (*(s16 *)(v + 0x234) == 1) {
            if (*(s32 *)(v + 0x304) != -1) {
                func_004513D8(o, 10, 3);
            } else if (*(s32 *)(v + 0x308) != 0 && v[0x5F] == 0) {
                if (func_0041C8C0(o + 0x10, v + 0x320) > 0.5f) {
                    func_004513D8(o, 10, 3);
                } else if (func_00360D18(o, v) != 0) {
                    func_004513D8(o, 18, 3);
                } else {
                    func_004513D8(o, 13, 3);
                }
            } else {
                k = *(s32 *)(v + 0x38C);
                if (k != -1 && (off = k * 0x30, *(s16 *)(D_001DFACC + off + 0x32) != 0)) {
                    func_004513D8(o, 10, 3);
                } else {
                    func_004513D8(o, 11, 3);
                }
            }
        } else {
        func_004513D8(o, 6, 2);
        *(s32 *)(v + 0x2F0) = func_0044FC98(0x244, 0x258);
        if (o[0x43] != 0) {
            func_00451098(o, 0, 0, 0);
        }
        if (*(long *)(v + 0x310) != -1) {
            func_004513D8(o, 5, 6);
        }
        if (*(s32 *)(v + 0x300) != -1) {
            func_004513D8(o, 2, -1);
        } else if (*(s32 *)(v + 0x318) == 0) {
            func_004513D8(o, 4, -1);
        } else if (*(s32 *)(v + 0x4E4) != 0) {
            func_004513D8(o, 3, -1);
        }
        }
        v[0x61] = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00362688 */
