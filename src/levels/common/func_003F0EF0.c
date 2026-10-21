#include "common.h"

/* localdecomp:start func_003F0EF0 */
typedef struct {
    u8 pad0[1056];
    s32 w420;
    f32 f424;
    f32 f428;
    f32 f42C;
    f32 f430;
    s32 w434;
    u8 b438;
    u8 b439;
    u8 pad43A[1120 - 1082];
} S_3F0EF0;
extern S_3F0EF0 D_001E2AC0[];
extern f32 D_001E76B0[];
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_003FFAC8(void);
void func_003F0EF0(s32 a0) {
    S_3F0EF0 *p = &D_001E2AC0[a0];
    f32 s;
    p->b439 = 0;
    p->f424 = 1.11002934f;
    p->f428 = 1.11002934f;
    s = func_0040C3E0(0.55501467f);
    D_001E76B0[0] = s / func_0040C3C8(0.55501467f);
    func_003FFAC8();
    p->f42C = 0.00499999989f;
    p->f430 = 0.200000003f;
    p->w420 = 0;
    p->w434 = 0;
}
/* localdecomp:end func_003F0EF0 */
