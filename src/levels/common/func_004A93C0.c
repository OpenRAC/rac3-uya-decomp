#include "common.h"

/* localdecomp:start func_004A93C0 */
typedef int s128 __attribute__((mode(TI)));

extern u8 D_001A4BE0[];
extern u8 D_0016C580[];
extern u8 D_001439F4[];
extern s32 D_001D673C;
extern void func_0045BFD0(void);
extern void func_0050CAF8(void);
extern void func_00500F10(s32);
extern void func_0050ED60(void);
extern void func_003F32F0(s32, f32);
extern void func_0045D318(s32);
extern f32 func_0040CEC8(f32, f32);
extern void func_004F12C0(u8 *, void *, s32, s32);

void func_004A93C0(void) {
    u8 *g;
    u8 *o;
    s128 v;

    func_0045BFD0();
    g = D_001A4BE0;
    g[9701] = 0;
    func_0050CAF8();
    o = D_0016C580;
    if (*(s16 *)(o + 42) != 0) {
        func_00500F10(1);
        g[9701] = 0;
        func_0050CAF8();
        if (D_001D673C == 0) {
            func_0050ED60();
        }
        func_003F32F0(0, 8.0f);
        func_0045D318(0);
        return;
    }
    if (D_001D673C == 0) {
        v = *(s128 *)(o + 128);
        if (D_001439F4[0] == 0) {
            ((f32 *)&v)[2] = func_0040CEC8(*(f32 *)(o + 136), -1.08f);
            func_004F12C0(o + 112, &v, 0, 1);
            ((f32 *)&v)[2] = func_0040CEC8(*(f32 *)(o + 136), 1.22f);
            func_004F12C0(o + 112, &v, 0, 0);
        } else {
            if (D_001439F4[0] == 2) {
                ((f32 *)&v)[2] = func_0040CEC8(*(f32 *)(o + 136), -0.15f);
                func_004F12C0(o + 112, &v, 0, 1);
            } else {
                ((f32 *)&v)[2] = func_0040CEC8(*(f32 *)(o + 136), -0.95f);
                func_004F12C0(o + 112, &v, 0, 1);
            }
        }
    } else {
        func_004F12C0(o + 112, o + 128, 0, 1);
    }
    func_003F32F0(0, 8.0f);
    func_0045D318(0);
}
/* localdecomp:end func_004A93C0 */
