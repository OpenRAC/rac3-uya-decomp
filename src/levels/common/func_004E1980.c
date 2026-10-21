#include "common.h"

/* localdecomp:start func_004E1980 */
typedef struct G {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad1[0x350 - 0x88];
    f32 p[3];
    u8 pad2[0x9C4 - 0x35C];
    u16 cnt;
} G;
extern G D_001A4BE0;
extern f32 func_004408C0(f32, f32);
extern void func_00467288(f32 *, f32 *, s32, f32, f32);
extern s32 func_00440848(s32);
void func_004E1980(s32 a0, s32 a1) {
    f32 v[3];
    f32 r;
    G *g = &D_001A4BE0;
    g->cnt += 1;
    if (a1 < (s16)g->cnt) {
        v[0] = g->x + func_004408C0(-0.05f, 0.05f);
        v[1] = g->y + func_004408C0(-0.05f, 0.05f);
        v[2] = g->p[0];
        r = func_004408C0(0.4f, 0.6f);
        func_00467288(v, g->p, -1, r, 5250.0f);
        g->cnt = func_00440848(a0);
    }
}
/* localdecomp:end func_004E1980 */
