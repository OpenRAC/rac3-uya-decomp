#include "common.h"

/* localdecomp:start func_003A5430 */
typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad1[62];
    s16 b170;
    u8 pad2[84];
} Moby_003A5430;

extern u16 *D_0021DEA0[];
extern Moby_003A5430 *D_001E009C;
extern s32 D_001E00D8 __attribute__((section(".sdata")));

void func_003A5430(Moby_003A5430 *self) {
    u16 *p;
    Moby_003A5430 *m;

    if (((u8 *)self)[33] != 255) {
        p = D_0021DEA0[((u8 *)self)[33]];
        while (((u8 *)self)[33] != 255 && ((u8 *)self)[33] <= D_001E00D8 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021DEA0[((u8 *)self)[33]])) {
            m = &D_001E009C[*p & 0x7FFF];
            if (m == 0) break;
            if (m->b170 == self->b170) {
                *(s32 *)(m->vars + 744) = 1;
            }
            p++;
        }
    }
}
/* localdecomp:end func_003A5430 */
