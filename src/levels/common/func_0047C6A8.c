#include "common.h"

extern s32 D_001D4CEC[];
extern u8 D_001D8340;
extern void func_0047A298(void);
extern s32 func_0047C878(void);
extern void func_005120B8(s32);
extern s32 func_0047B380(void);
extern void func_00513758(s32);
extern s32 func_004181A0(s32);
extern s32 func_00494900(s32, s32, s32, s32, s32);
extern void func_004949A0(s32, s32);
extern void func_004948D8(s32, s32);
extern s32 func_004949B0(void);
extern s32 func_004948D0(void);
extern void func_0047C668(void);
extern void func_0047C648(void);

s32 func_0047C6A8(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;

    if (D_001D4CEC[0] & 1) {
        func_0047A298();
        func_005120B8(func_0047C878());
        func_00513758(func_0047B380());
        return 1;
    }
    switch (D_001D8340) {
    case 0:
        D_001D8340 = 1;
        return 0;
    case 1:
        a = func_004181A0(1410);
        b = func_004181A0(2863);
        c = func_004181A0(3848);
        func_00494900(0, a, b, c, 1);
        func_004949A0(64, 448);
        func_004948D8(32, 128);
        D_001D8340++;
        return 1;
    case 2:
        if (func_004949B0() != 0) {
            return 1;
        }
        r = func_004948D0();
        if (r == 1) {
            D_001D8340 = 0;
            func_0047C668();
            return 1;
        }
        if (r == 2) {
            D_001D8340 = 0;
            func_0047C648();
        }
        return 1;
    }
    return 0;
}
