#include "common.h"

typedef struct {
    u8 pad[0x18];
    s16 f18;
    u8 pad1A[0x17C - 0x1A];
    s32 f17C;
} S_005992A8;
extern void func_005992A0(s32 *);
extern S_005992A8 D_001A4560;
extern s32 D_001D71E4;
extern s32 D_001E03B0;
extern s32 D_0024057C;
extern s32 D_00240580;
extern s32 D_0024145C;

void func_005992A8(s32 a0) {
    s32 buf = a0;
    s32 v;
    S_005992A8 *g;
    func_005992A0(&buf);
    v = buf;
    D_001D71E4 = 1;
    D_00240580 = D_0024145C;
    D_001E03B0 = v;
    if (v == -1) {
        g = &D_001A4560;
        if (g->f17C != 0) {
            g->f17C = 0;
        }
        if (g->f18 >= 0) {
            g->f18 = v;
        }
        D_0024057C &= ~0x200;
    }
}
