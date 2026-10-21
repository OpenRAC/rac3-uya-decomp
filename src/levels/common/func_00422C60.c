#include "common.h"

/* localdecomp:start func_00422C60 */
typedef int s128_422C60 __attribute__((mode(TI)));

extern u8 D_001FFB8A[];
extern u8 *D_001FD200[];
extern s32 D_002006F0[];
extern s128_422C60 D_00200E70[];
extern s32 D_001EAA38[];
extern void func_00424008(u8 *, s32);
extern void func_0040BBA8(void *, s32, s32);

void func_00422C60(s32 restore) {
    u8 idx;

    if (restore) {
        idx = D_001FFB8A[0];
        *(s32 *)D_001FD200[0] = *(s32 *)D_001FD200[idx];
        D_001FD200[0][4] = D_001FD200[idx][4];
        D_001FD200[0][5] = D_001FD200[idx][5];
        D_001FD200[0][6] = D_001FD200[idx][6];
        D_001FD200[0][7] = D_001FD200[idx][7];
        *(s32 *)(D_001FD200[0] + 32) = *(s32 *)(D_001FD200[idx] + 32);
        D_002006F0[0] = D_002006F0[idx];
        D_00200E70[0] = D_00200E70[idx];
    } else {
        func_00424008(D_001FD200[0], D_001EAA38[0]);
        D_002006F0[0] = 0xFFFC0000;
        func_0040BBA8(D_00200E70, -1, 16);
    }
    D_001FD200[0][9] = D_001FD200[0][8];
}
/* localdecomp:end func_00422C60 */
