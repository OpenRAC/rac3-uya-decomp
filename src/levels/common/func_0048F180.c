#include "common.h"

extern s32 D_001D7C30;
extern s32 D_001D7C34;
extern s32 D_001D7C38;
extern void func_0048F7F8(void *, s32);
extern void func_0048F1E0(void);
extern void func_0048F320(void);
extern void func_0048F468(void);

void func_0048F180(void) {
    if (D_001D7C30 != 0) {
        func_0048F7F8(func_0048F1E0, 0);
    }
    if (D_001D7C34 != 0) {
        func_0048F7F8(func_0048F320, 0);
    }
    if (D_001D7C38 != 0) {
        func_0048F7F8(func_0048F468, 0);
    }
}
