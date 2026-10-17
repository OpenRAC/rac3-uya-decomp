#include "common.h"

extern u32 *D_001E10E8;
extern u32 *D_001E0F3C;
extern s32 D_001E0F44;
extern s32 D_001D4BB0;
extern void func_004AE8A0(void);
extern s32 func_004AEA08(s32);
extern void func_004C21C0(void);
void func_004ADA10(void) {
    u32 *save = D_001E10E8;
    s32 r;
    D_001E10E8 += 4;
    D_001E0F3C[0] = 0x20000000;
    D_001E0F3C[1] = (u32)D_001E10E8;
    D_001E0F3C[2] = 0;
    D_001E0F3C[3] = 0;
    func_004AE8A0();
    r = func_004AEA08(D_001D4BB0);
    func_004C21C0();
    if (D_001E0F44 < r) { D_001E0F44 = r; }
    D_001E10E8[0] = 0x20000000;
    D_001E10E8[1] = (u32)(D_001E0F3C + 4);
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0;
    D_001E10E8 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001E10E8;
    save[2] = 0;
    save[3] = 0;
}
