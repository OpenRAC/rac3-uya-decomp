#include "common.h"

/* localdecomp:start func_0050E500 */
typedef struct S_50E500o {
    u8 pad0[0x78];
    s32 x78;
} S_50E500o;
typedef struct S_50E500g {
    u8 pad0[0x1340];
    S_50E500o *x1340;
    S_50E500o *x1344;
    S_50E500o *x1348;
    u8 pad134c[0x44];
    S_50E500o *x1390;
    u8 pad1394[0x14FC];
    f32 x2890;
    f32 x2894;
    f32 x2898;
    f32 x289C;
} S_50E500g;
extern S_50E500g D_001A4BE0;
extern s32 D_001D6694;
extern f32 func_0040CEC8(f32 a, f32 b);
extern f32 func_0040C3E0(f32 a);
extern s32 func_0040D020(s32 a, s32 b, f32 c);
extern void func_0044EB38(S_50E500o *o, f32 *a, s32 b, s32 c, f32 d);
void func_0050E500(void) {
    S_50E500o *o;
    s32 c;

    o = D_001A4BE0.x1340;
    if (o != 0) {
        if (D_001D6694 == 2) {
            D_001A4BE0.x2890 = func_0040CEC8(D_001A4BE0.x2890, 0.020362176f);
        } else {
            D_001A4BE0.x2890 = func_0040CEC8(D_001A4BE0.x2890, 0.0349065885f);
        }
        o->x78 = func_0040D020(0xD2D2D2, 0x285050, func_0040C3E0(D_001A4BE0.x2890) * 0.5f + 0.5f);
    }
    o = D_001A4BE0.x1344;
    if (o != 0) {
        if (D_001D6694 != 2) {
            D_001A4BE0.x2894 = func_0040CEC8(D_001A4BE0.x2894, 0.0494509973f);
            c = 0x1EE628;
            if (0.0f < D_001A4BE0.x2894 && D_001A4BE0.x2894 < 1.91986215f) {
                c = 0x1E1ED2;
            }
            o->x78 = func_0040D020(o->x78, c, 0.07f);
        } else {
            D_001A4BE0.x2894 = func_0040CEC8(D_001A4BE0.x2894, 0.0261799414f);
            o->x78 = func_0040D020(0x1E1ED2, 0x1E1E50, func_0040C3E0(D_001A4BE0.x2894) * 0.5f + 0.5f);
        }
    }
    if (D_001A4BE0.x1348 != 0) {
        if (D_001D6694 == 2) {
            func_0044EB38(D_001A4BE0.x1348, &D_001A4BE0.x2898, 0xDCDCDC, 0x323232, 0.0261799414f);
        } else {
            func_0044EB38(D_001A4BE0.x1348, &D_001A4BE0.x2898, 0xDCDCDC, 0x323232, 0.040724352f);
        }
    }
    o = D_001A4BE0.x1390;
    if (o != 0) {
        D_001A4BE0.x289C = func_0040CEC8(D_001A4BE0.x289C, 0.0494509973f);
        c = 0x5A5A5A;
        if (0.0f < D_001A4BE0.x289C && D_001A4BE0.x289C < 1.22173047f) {
            c = 0xAAC8AA;
        }
        o->x78 = func_0040D020(o->x78, c, 0.15f);
    }
}
/* localdecomp:end func_0050E500 */
