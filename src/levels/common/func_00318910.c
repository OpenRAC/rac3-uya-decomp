#include "common.h"

/* localdecomp:start func_00318910 */
typedef struct { u8 pad0[0x23]; u8 f23; u8 pad24[0x10]; u16 f34; } M_318910;
typedef struct { u8 pad0[0x1200]; M_318910 *m[3]; u8 padC[0x44]; } R_318910;
typedef struct { u8 pad0[0x25C0]; M_318910 *f25C0; } S_318910;
extern S_318910 D_001A4BE0;

void func_00318910(void) {
    S_318910 *g = &D_001A4BE0;
    R_318910 *r;
    g->f25C0->f23 = 0x7F;
    g->f25C0->f34 &= ~0x2000;
    r = (R_318910 *)g;
    do {
        if (r->m[0] != 0) {
            r->m[0]->f23 = 0x7F;
            r->m[0]->f34 &= ~0x2000;
        }
        if (r->m[1] != 0) {
            r->m[1]->f23 = 0x7F;
            r->m[1]->f34 &= ~0x2000;
        }
        if (r->m[2] != 0) {
            r->m[2]->f23 = 0x7F;
            r->m[2]->f34 &= ~0x2000;
        }
        r = (R_318910 *)((u8 *)r + 0x50);
    } while ((s32)r < (s32)((u8 *)g + 0x230));
}
/* localdecomp:end func_00318910 */
