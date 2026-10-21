#include "common.h"

/* localdecomp:start func_004848A8 */
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
extern s32 D_001D87C0;
extern s32 D_001D8874;
extern s32 D_001D87D0[2];
extern s32 D_001D87F0[2];
extern u8 D_001425C0[];
extern E_4848A8 D_002C5640[];
extern void func_00512AB0(s32, s32, s32);
extern void func_005131A0(s32, s32);
void func_004848A8(void) {
    s32 x;
    switch (D_001D87C0) {
    case 0:
        x = D_001D87D0[D_001D8874];
        if (x != 0) {
            func_00512AB0(0x190083, 1, 1);
            func_005131A0(0x190083, ((E_4848A8 *)(D_001425C0[x] * 240 + (s32)D_002C5640))->h38);
        } else {
            func_00512AB0(0x190083, 1, 0);
        }
        break;
    case 1:
        x = D_001D87F0[D_001D8874];
        if (x != 0) {
            func_00512AB0(0x190083, 1, 1);
            func_005131A0(0x190083, ((E_4848A8 *)(D_001425C0[x] * 240 + (s32)D_002C5640))->h38);
        } else {
            func_00512AB0(0x190083, 1, 0);
        }
        break;
    }
}
/* localdecomp:end func_004848A8 */
