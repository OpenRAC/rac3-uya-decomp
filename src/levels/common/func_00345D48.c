#include "common.h"

extern s32 D_001D5520[];
extern s32 D_001D4BC4[];
extern s32 D_001D4BC0;
extern s32 D_001DD300;
extern s32 D_001DD304;
extern s32 D_001DD308;
extern s32 D_001DD30C;
extern s32 D_001DD310;
extern s32 D_001DD314;
extern s32 D_001DD318;
extern s32 D_001DD31C;
extern s32 D_001DD320;
extern s32 D_001DD324;
extern s32 D_001DD328;
extern s32 D_001DD32C;
extern s32 D_001DD330;
extern s32 D_001DD334;
extern s32 D_001DD338;
extern s32 D_001DD33C;
extern s32 D_001DD340;
extern s32 D_001DD344;

extern void func_004C2280(void);
extern void func_004C1FE8(s32, unsigned long);
extern unsigned long func_00401CD0(s32);
extern void func_00403CA8(s32, s32, s32, s32, s32, s32, s32, s32, unsigned long, unsigned long);

void func_00345D48(void) {
    s32 w;
    s32 h;
    s32 hw;
    s32 hh;

    func_004C2280();
    w = D_001D4BC0;
    h = D_001D4BC4[0];
    if (D_001D5520[0] != 0) {
        D_001DD344 = -1;
        D_001DD334 = 236;
        D_001DD338 = 240;
        w = D_001DD33C;
        h = D_001DD340;
    }
    func_004C1FE8(71, 0x513F1);
    {
        unsigned long c = func_00401CD0(70);
        hw = (f32)w * 0.5f;
        hh = (f32)h * 0.5f;
        func_00403CA8(0, 0, hw, hh, 0, 0, 127, 127, 0x50101010, c);
    }
    func_00403CA8(w, 0, -hw, hh, 0, 0, 127, 127, 0x50101010, func_00401CD0(70));
    func_00403CA8(0, h, hw, -hh, 0, 0, 127, 127, 0x50101010, func_00401CD0(70));
    func_00403CA8(w, h, -hw, -hh, 0, 0, 127, 127, 0x50101010, func_00401CD0(70));
    func_004C1FE8(66, (unsigned long)D_001DD30C | ((unsigned long)D_001DD310 << 2) | ((unsigned long)D_001DD314 << 4) | ((unsigned long)D_001DD318 << 6) | 0x8000000000UL);
    {
        unsigned long t = func_00401CD0(D_001DD300);
        func_00403CA8(0, 0, hw, hh, 0, 0, 255, 255, D_001DD304, t);
        func_00403CA8(w, 0, -hw, hh, 0, 0, 255, 255, D_001DD304, t);
        func_00403CA8(0, h, hw, -hh, 0, 0, 255, 255, D_001DD304, t);
        func_00403CA8(w, h, -hw, -hh, 0, 0, 255, 255, D_001DD304, t);
    }
    func_004C1FE8(66, (unsigned long)D_001DD31C | ((unsigned long)D_001DD320 << 2) | ((unsigned long)D_001DD324 << 4) | ((unsigned long)D_001DD328 << 6) | 0x8000000000UL);
    func_00403CA8(0, 0, w, h, D_001DD32C, D_001DD330, D_001DD334, D_001DD338, D_001DD308, func_00401CD0(D_001DD344));
}
