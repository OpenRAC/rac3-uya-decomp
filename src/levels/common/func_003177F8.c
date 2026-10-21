#include "common.h"

/* localdecomp:start func_003177F8 */
typedef struct {
    u8 pad0[56];
    s32 w56;
    s32 w60;
} S_00142660;

extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s32 D_001EFD00[][3];
extern s32 D_001EFDC0[][3];
extern S_00142660 D_00142660;
extern s32 func_00440760(void *, s32, s32);
extern s32 func_003FE4C0(s32);

void func_003177F8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    u8 *q;
    s32 r;
    s32 sh;
    u8 v;

    if (a0[32] == 0) {
        a0[48] = 255;
        a0[32]++;
    }
    if (func_00440760(D_001A4C60, p[1], 0) == 0) {
        return;
    }
    D_001A4C60[9591] = a0[176];
    if (p[2] != 0) {
        return;
    }
    if ((D_001BBC40[a0[176] + D_001D545C * 16] >> (a0[177] * 2)) & 3) {
        return;
    }
    p[2] = 1;
    r = func_003FE4C0(a0[176]);
    q = &D_001BBC40[(a0[176] & 15) + D_001D545C * 16];
    sh = (a0[177] & 3) * 2;
    v = *q;
    if ((v >> sh) & 3) {
        return;
    }
    *q = (v & ~(3 << sh)) | (r << sh);
    D_00142660.w56 += D_001EFD00[a0[176] & 15][a0[177] & 3];
    D_00142660.w60 += D_001EFDC0[a0[176] & 15][a0[177] & 3];
}
/* localdecomp:end func_003177F8 */
