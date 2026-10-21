#include "common.h"

/* localdecomp:start func_00482960 */
extern s32 D_001D858C;
extern s32 D_001D8590;
extern f32 D_001D85AC;
extern f32 D_001D85B0;
extern u8 D_00142CA0[];
extern int func_004821D8(int, int);
extern void func_00512AB0(s32, s32, s32);
extern void func_00474C68(s32, s32, f32, f32);

void func_00482960(void) {
    s32 i;

    i = func_004821D8(D_001D858C, D_001D8590);
    if (D_00142CA0[i] != 0) {
        func_00512AB0(0xE0009, 1, 1);
        func_00474C68(i, 0xE0009, D_001D85AC, D_001D85B0);
    } else {
        func_00512AB0(0xE0009, 1, 0);
    }
}
/* localdecomp:end func_00482960 */
