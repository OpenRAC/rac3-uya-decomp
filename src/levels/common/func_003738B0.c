#include "common.h"

/* localdecomp:start func_003738B0 */
typedef struct S_3738B0 S_3738B0;

typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;

struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};

extern S_3738B0 *D_001E1160[];
extern f32 func_0040C018(f32 *a0, f32 *a1);

void func_003738B0(S_3738B0 *a0, S_3738B0 *a1) {
    S_3738B0m *m;
    S_3738B0m *q;
    S_3738B0 **pp;
    f32 d;
    s32 i;

    if (a0 == 0 || a1 == 0) {
        return;
    }
    m = a0->p68;
    for (i = 0; i < 6; i++) {
        pp = &D_001E1160[i];
        if (*pp == 0) {
            continue;
        }
        q = (*pp)->p68;
        if (q == 0 || q->w54 != a1) {
            continue;
        }
        if (m == 0) {
            return;
        }
        d = func_0040C018(a0->pos, a1->pos);
        if (d < func_0040C018((*pp)->pos, a1->pos)) {
            m->w54 = a1;
            q->w54 = 0;
        }
        return;
    }
    m->w54 = a1;
}
/* localdecomp:end func_003738B0 */
