#include "common.h"
typedef struct {
    u8 pad0[416];
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    u8 pad1AC[844 - 428];
    s32 k;
    s32 n;
    s32 a[7];
} S_005C0F88;
extern S_005C0F88 D_00225900;
s32 func_005C0F88(S_005C0F88 *a0) {
    S_005C0F88 *p;
    if (a0 != 0) {
        p = a0;
    } else {
        p = &D_00225900;
    }
    if (p->n >= 2) {
        return ~p->a[(p->k + 5) % 7] & p->a[(p->k + 6) % 7];
    }
    if (p->n == 1) {
        return ~p->f1A0 & p->a[(p->k + 6) % 7];
    }
    return p->f1A4;
}
