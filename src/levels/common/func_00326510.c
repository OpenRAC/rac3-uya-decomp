#include "common.h"

typedef struct S_326510n {
    s32 w0;
    struct S_326510n *next;
} S_326510n;

typedef struct {
    u8 pad0[0x1A0];
    S_326510n *a1A0[32];
    s32 a220[32];
    S_326510n *a2A0[32];
} S_326510t;

typedef struct {
    u8 pad0[0x68];
    S_326510t *p68;
} S_326510;

extern S_326510 *func_003252E8(s32 a0);
extern s32 func_003255A0(S_326510t *a0, s32 a1);
extern void func_00325E48(S_326510 *a0, S_326510t *a1, s32 a2);
extern S_326510n *func_00445F18(S_326510n *a0);

S_326510n *func_00326510(s32 a0) {
    S_326510 *o;
    S_326510t *t;
    s32 k;
    S_326510n *x;
    S_326510n *y;

    o = func_003252E8(a0);
    t = o->p68;
    k = func_003255A0(t, a0);
    if (t->a1A0[k] == 0) {
        func_00325E48(o, t, k);
        if (t->a1A0[k] == 0) {
            return 0;
        }
    }
    x = t->a1A0[k];
    y = func_00445F18(x);
    t->a1A0[k] = y->next;
    t->a220[k]--;
    y->next = t->a2A0[k];
    t->a2A0[k] = x;
    return x;
}
