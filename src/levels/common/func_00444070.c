#include "common.h"

/* localdecomp:start func_00444070 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    union {
        s128 q;
        f32 f[4];
    } pos;
    s128 col;
} E_001E8D00;

extern s32 D_001DFA60;
extern E_001E8D00 D_001E8D00[];
extern s128 D_001EAAC0[];
extern f32 func_00443140(void *, s32, s32, f32);
extern s32 func_003FC730(void);

void func_00444070(u8 *a0, f32 scale)
{
    f32 h;
    f32 t;
    E_001E8D00 *e;
    s32 n;

    if (a0[49] == 0) {
        return;
    }
    if (D_001DFA60 >= 32) {
        return;
    }
    D_001E8D00[D_001DFA60].pos.q = *(s128 *)(a0 + 16);
    h = func_00443140(a0 + 16, 0, 0, 0.5f);
    if (func_003FC730() == 0) {
        return;
    }
    n = D_001DFA60;
    e = &D_001E8D00[n];
    e->pos.f[2] = h + 0.025f;
    D_001E8D00[n].col = D_001EAAC0[0];
    t = (8.0f - __builtin_fabsf(*(f32 *)(a0 + 24) - h)) * 0.125f;
    if (t < 0.25f) {
        t = 0.25f;
    }
    D_001DFA60 = n + 1;
    e->pos.f[3] = scale * t;
}
/* localdecomp:end func_00444070 */
