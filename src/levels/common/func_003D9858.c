#include "common.h"

/* localdecomp:start func_003D9858 */
typedef struct {
    u8 pad[32];
    s32 active;
    s32 pad2;
    f32 t;
    u8 pad3[4];
} S_002A2EC0;

extern S_002A2EC0 D_002A2EC0[];
extern f32 func_0040C3E0(f32);
extern void func_004082B0(S_002A2EC0 *, s32, s32, s32, f32, f32, f32);
extern void func_003D9B98(S_002A2EC0 *, s32, s32, f32, f32, f32, f32);

void func_003D9858(void)
{
    s32 i;

    for (i = 0; i < 64; i++) {
        S_002A2EC0 *p = &D_002A2EC0[i];
        if (p->active != 0) {
            func_004082B0(p, 57, 0x207F7F8F, 1, func_0040C3E0(p->t) * 0.25f + 0.5f, -0.1f, p->t);
            func_004082B0(p, 57, 0x207F7F8F, 1, func_0040C3E0(p->t) * 0.25f + 0.5f, -0.1f, -p->t);
            func_003D9B98(p, 59, 1, (func_0040C3E0(p->t) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        }
    }
}
/* localdecomp:end func_003D9858 */
