#include "common.h"

/* localdecomp:start func_00419A68 */
extern u8 *D_001DFD98;
extern s32 D_001DFDC0[];
#define D_001DFDC0 (D_001DFDC0[0])
extern s32 D_001DFDC8[];
#define D_001DFDC8 (D_001DFDC8[0])
extern s32 D_001DFDCC[];
#define D_001DFDCC (D_001DFDCC[0])
extern s32 D_001DFDD0[];
#define D_001DFDD0 (D_001DFDD0[0])

extern void func_004AD678(void *, s32, s32, s32, s32);
extern void func_00433EA0(void *, u8 *);
extern void func_00419C38(s32, u8 *);

void func_00419A68(s32 arg0, u8 *arg1, void *arg2) {
    if (*(s32 *)(D_001DFD98 + 84) != 0) {
        s32 n = *(s32 *)(D_001DFD98 + 84);
        func_004AD678(arg2, *(s32 *)(D_001DFD98 + 148), 0, D_001DFDC0 / 16, 0);
        func_00433EA0(arg2, arg1);
        func_00419C38(0, arg1);
        arg1 += n;
    }
    if (*(s32 *)(D_001DFD98 + 92) != 0) {
        s32 n = *(s32 *)(D_001DFD98 + 92);
        func_004AD678(arg2, *(s32 *)(D_001DFD98 + 156), 0, D_001DFDC8 / 16, 0);
        func_00433EA0(arg2, arg1);
        func_00419C38(2, arg1);
        arg1 += n;
    }
    if (arg0 == 0 || arg0 == 2) {
        if (*(s32 *)(D_001DFD98 + 96) != 0) {
            s32 n = *(s32 *)(D_001DFD98 + 96);
            func_004AD678(arg2, *(s32 *)(D_001DFD98 + 160), 0, D_001DFDCC / 16, 0);
            func_00433EA0(arg2, arg1);
            func_00419C38(3, arg1);
            arg1 += n;
        }
    }
    if ((u32)(arg0 - 1) < 2) {
        u8 *p = *(u8 * volatile *)&D_001DFD98;
        if (*(s32 *)(p + 100) != 0) {
            func_004AD678(arg2, *(s32 *)(p + 164), 0, D_001DFDD0 / 16, 0);
            func_00433EA0(arg2, arg1);
            func_00419C38(4, arg1);
        }
    }
}
/* localdecomp:end func_00419A68 */
