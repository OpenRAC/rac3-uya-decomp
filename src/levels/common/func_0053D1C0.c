#include "common.h"

typedef struct {
    u8 pad[136];
    s32 f88[1];
} S_352C4C;

extern S_352C4C *D_00352C4C[];
extern void *func_0066B3C0(void *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_005B2498(s32);
extern void func_006601C8(void *, void *, s32);

void func_0053D1C0(u8 *m) {
    void *h;
    s32 v;
    s32 x;
    s32 buf[2];

    h = func_0066B3C0(m, 1, 0, 2500);
    v = D_00352C4C[0]->f88[*(s32 *)(*(u8 **)(m + 104) + 28)];
    if (v == 0) {
        x = 1;
    } else if (v == 1) {
        x = 0;
    } else {
        x = func_005B2498(2);
    }
    buf[0] = x;
    func_006601C8(h, buf, 4);
}
