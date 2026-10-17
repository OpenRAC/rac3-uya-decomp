#include "common.h"

extern s32 D_001D83C0;

extern void func_0047D630(void);
extern void func_0047D658(void);
extern void func_0047D688(void);
extern s32 D_001D8398;
extern s8 D_001DFF98;
extern s32 D_001D83C0;
extern s32 D_001D4CE8[];
void func_0047E8C8(void) {
    s32 t5 = D_001D8398;
    s32 t4 = D_001D4CE8[0];
    D_001DFF98 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_0047D630();
    } else if ((u32)(t4 - 6) < 2U) {
        func_0047D658();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_0047D688();
    }
    D_001D83C0 = 2;
}
