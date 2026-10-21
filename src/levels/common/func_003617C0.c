#include "common.h"

/* localdecomp:start func_003617C0 */
typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad1[62];
    s16 b170;
    u8 pad2[84];
} Moby_003617C0;

extern u16 *D_0021CA20[];
extern Moby_003617C0 *D_001DFE1C;
extern s32 D_001DFE58;
extern void func_00451EC8(s32, s32);

void func_003617C0(Moby_003617C0 *self) {
    u16 *p;
    Moby_003617C0 *m;

    if (((u8 *)self)[33] != 255) {
        func_00451EC8(((u8 *)self)[33], 0);
        p = D_0021CA20[((u8 *)self)[33]];
        while (((u8 *)self)[33] != 255 && ((u8 *)self)[33] <= D_001DFE58 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021CA20[((u8 *)self)[33]])) {
            m = &D_001DFE1C[*p & 0x7FFF];
            if (m == 0) break;
            if (m->b170 == self->b170) {
                *(s32 *)(m->vars + 0x2F8) = 1;
            } else if (m->b170 == 0x16BD) {
                *(s32 *)(m->vars + 0x2E8) = 1;
            } else if (m->b170 == 0x1B39) {
                *(s32 *)(m->vars + 0x3E4) = 1;
            }
            p++;
        }
    }
}
/* localdecomp:end func_003617C0 */
