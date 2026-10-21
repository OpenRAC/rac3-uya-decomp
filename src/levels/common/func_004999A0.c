#include "common.h"

/* localdecomp:start func_004999A0 */
typedef struct { s32 w0; s32 w4; s32 w8; u8 padC[0x18 - 0xC]; } E_4999A0;
extern s32 D_001D949C;
extern s32 D_001D94A8;
extern s32 D_001D9498;
extern s32 D_001D94E4;
extern s32 D_002EC228[];
extern E_4999A0 D_002EC3B8[];
extern s32 func_00494DD0(s32);
extern s32 func_00494E58(s32);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern void func_005131A0(s32, s32);
extern void func_00512D70(s32, s32);
void func_004999A0(void) {
    s32 *t;
    if (D_001D949C != 0) {
        t = D_002EC228;
        D_001D94A8 = t[func_00494E58(func_00494DD0(0))];
    }
    if (D_001D94A8 < 0) {
        return;
    }
    if (D_001D9498 != D_001D94A8) {
        func_00512FE8(0x4E0006, func_004181A0(((E_4999A0 *)(D_001D94A8 * 24 + (s32)D_002EC3B8))->w0));
        D_001D94E4 = 30;
    }
    if (D_001D94E4 != 0 && --D_001D94E4 == 0) {
        func_005131A0(0x4E0003, D_002EC3B8[D_001D94A8].w8 + 1);
        func_00512D70(0x4E0003, 1);
    }
    D_001D9498 = D_001D94A8;
}
/* localdecomp:end func_004999A0 */
