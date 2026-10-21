#include "common.h"

/* localdecomp:start func_00485FF8 */
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;

extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern Entry_00485FF8 D_002C5640[];
extern s32 func_00484718(s32, s32, s32);
extern s32 func_004849C0(s32, s32, s32);
extern void func_00512AB0(s32, s32, s32);
extern void func_005131A0(s32, s32);
extern s32 func_00512D70(s32, s32);

void func_00485FF8(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            x = func_00484718(1, i, j);
            y = func_004849C0(0x190069, i, j);
            if (x != 0) {
                if (x == 20) {
                    func_005131A0(y, 0xEAC9);
                } else {
                    func_005131A0(y, ((Entry_00485FF8 *)(D_001425C0[x] * 240 + (s32)D_002C5640))->f56);
                }
                func_00512D70(y, D_00142CA0[x] != 0);
            } else {
                func_00512AB0(y, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_00485FF8 */
