#include "common.h"

/* localdecomp:start func_00334B28 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 *D_0021F740[];
extern u8 *D_001E0180;
extern u8 *D_001E009C;
extern f32 func_0040BFE8(void *, void *);
extern void func_00458E48(void *, void *, s32, s32);
extern void func_00455EC8(void *, void *, void *);
extern void func_00455E98(void *, void *, void *);

s32 func_00334B28(u8 *a0, s32 a1, u8 *a2, u8 *a3, s32 a4, u8 *a5)
{
    s32 *path;
    f32 d;
    u128_t tmp;

    if (*(s32 *)(a5 + 108) != -1 && a5[153] == 0) {
        path = D_0021F740[*(s32 *)(a5 + 108)];
        d = func_0040BFE8(a2 + 16, path + 4);
        if (func_0040BFE8(a2 + 16, path + path[0] * 4) < d) {
            func_00458E48(a2, path, 0, 0);
        } else {
            func_00458E48(a2, path, path[0] - 1, 0);
        }
    }
    if (a5[16] != 2 && a5[17] != 2) {
        if (*(s32 *)(a5 + 100) != -1) {
            tmp = *(u128_t *)(&D_001E0180[*(s32 *)(a5 + 100) << 7] + 48);
            func_00455EC8(a2, &tmp, a3 + 1008);
        } else if (*(s32 *)(a5 + 96) != -1) {
            func_00455E98(a2, D_001E009C + *(s32 *)(a5 + 96) * 256, a3 + 1008);
        }
    }
    a0[188] = 0;
    return 0;
}
/* localdecomp:end func_00334B28 */
