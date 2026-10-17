#include "common.h"

extern s32 D_002412A8[];
extern s32 D_001DFD94;
extern f32 func_005FCFB0(void);
extern s32 func_00564490(u8 *, f32);
extern void func_005A98E8(s32, s32, u8 *);
extern void func_005632C8(u8 *);
extern void func_00563528(u8 *);
extern void func_00563920(u8 *);

void func_00563240(u8 *arg0)
{
    u8 *v;

    if (D_002412A8[0] == 0) {
        v = *(u8 **)(arg0 + 104);
        if (func_00564490(arg0, func_005FCFB0()) && D_001DFD94 != 40) {
            func_005A98E8(*(s32 *)(*(u8 **)(v + 64) + 9508), 10, v + 48);
            func_005632C8(arg0);
            func_00563528(arg0);
            func_00563920(arg0);
        }
    }
}
