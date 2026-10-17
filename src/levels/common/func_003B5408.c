#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad1[62];
    s16 b170;
    u8 pad2[84];
} Moby_003B5408;

extern u16 *D_0021CC60[];
extern Moby_003B5408 *D_001DFD9C;
extern s32 D_001DFDD8 __attribute__((section(".sdata")));

void func_003B5408(Moby_003B5408 *self) {
    u16 *p;
    Moby_003B5408 *m;

    if (((u8 *)self)[33] != 255) {
        p = D_0021CC60[((u8 *)self)[33]];
        while (((u8 *)self)[33] != 255 && ((u8 *)self)[33] <= D_001DFDD8 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021CC60[((u8 *)self)[33]])) {
            m = &D_001DFD9C[*p & 0x7FFF];
            if (m == 0) break;
            if (m->b170 == self->b170) {
                *(s32 *)(m->vars + 1116) = 1;
            }
            p++;
        }
    }
}
