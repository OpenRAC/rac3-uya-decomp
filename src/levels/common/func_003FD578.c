#include "common.h"
typedef struct {
    s32 f[10];
} Ent40;
extern Ent40 D_001E68D0[];
void func_003FD578(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, s32 s8, u32 idx) {
    if (idx < 32) {
        D_001E68D0[idx].f[0] = a0;
        D_001E68D0[idx].f[1] = a1;
        D_001E68D0[idx].f[2] = a2;
        D_001E68D0[idx].f[3] = a3;
        D_001E68D0[idx].f[4] = t0;
        D_001E68D0[idx].f[5] = t1;
        D_001E68D0[idx].f[6] = t2;
        D_001E68D0[idx].f[7] = t3;
        D_001E68D0[idx].f[8] = s0;
        D_001E68D0[idx].f[9] = s8 * 45 + 240;
    }
}
