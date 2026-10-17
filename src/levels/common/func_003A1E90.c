#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad1[62];
    s16 b170;
    u8 pad2[84];
} Moby_003A1E90;

extern u16 *D_0021BEA0[];
extern Moby_003A1E90 *D_001DF21C;
extern s32 D_001DF258 __attribute__((section(".sdata")));

void func_003A1E90(Moby_003A1E90 *self) {
    u16 *p;
    Moby_003A1E90 *m;

    if (((u8 *)self)[33] != 255) {
        p = D_0021BEA0[((u8 *)self)[33]];
        while (((u8 *)self)[33] != 255 && ((u8 *)self)[33] <= D_001DF258 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021BEA0[((u8 *)self)[33]])) {
            m = &D_001DF21C[*p & 0x7FFF];
            if (m == 0) break;
            if (m->b170 == self->b170) {
                *(s32 *)(m->vars + 788) = 1;
            }
            p++;
        }
    }
}
