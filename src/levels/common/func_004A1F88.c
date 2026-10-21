#include "common.h"

/* localdecomp:start func_004A1F88 */
extern u32 *D_001E10E8;
extern u32 *D_001E0E60_003D97C8;
extern s32 D_001E0E64;
extern s32 D_001D4BB0;
extern s32 func_004A3AD8(s32);
extern void func_004C21C0(void);
void func_004A1F88(void) {
    u32 *save = D_001E10E8;
    s32 r;
    D_001E10E8 += 4;
    D_001E0E60_003D97C8[0] = 0x20000000;
    D_001E0E60_003D97C8[1] = (u32)D_001E10E8;
    D_001E0E60_003D97C8[2] = 0;
    D_001E0E60_003D97C8[3] = 0;
    r = func_004A3AD8(D_001D4BB0);
    func_004C21C0();
    if (D_001E0E64 < r) { D_001E0E64 = r; }
    D_001E10E8[0] = 0x20000000;
    D_001E10E8[1] = (u32)(D_001E0E60_003D97C8 + 4);
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0;
    D_001E10E8 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001E10E8;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_004A1F88 */
