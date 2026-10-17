#include "common.h"

extern s32 D_001D6A08;
extern s32 D_001D6A0C;
extern f32 D_001D6A10;
extern s32 D_001D6A14;
extern s32 D_001D6A18;
extern void func_0041FC08(void);
extern void func_0041F300(void);
extern void func_00433038(void *, void *, s32);
extern void func_00445110(s32 *, s32, s32);

void func_0041F258(s32 mode, s32 a1, s32 a2, f32 f) {
    if (D_001D6A08 == 0 || (D_001D6A0C != 2 && mode == 2)) {
        D_001D6A0C = mode;
        func_00433038(func_0041FC08, func_0041F300, 1);
    }
    if (mode == D_001D6A0C) {
        D_001D6A14 = a1;
        D_001D6A18 = a2;
        D_001D6A10 = f;
        func_00445110(&D_001D6A08, 10, 2);
    }
}
