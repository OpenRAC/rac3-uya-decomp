#include "common.h"

/* localdecomp:start func_0042DA20 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s32 id;
    s32 val;
    s32 w8;
    s32 wC;
} S_42DA20e;

typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x20];
    s32 w28;
    u8 pad2C[4];
    S_42DA20e e[8];
} S_42DA20;

extern S_42DA20 D_001F4020;
extern s128 D_001F4050[];
extern s32 D_001DF9C8;
extern void func_0042D170(s32, s32, s32, s32);

s32 func_0042DA20(s32 id) {

    s32 ret;
    s32 best;
    s32 i;
    s128 t;


    if (D_001F4020.w28 == 0) {
        return 0;
    }
    ret = 0;
    best = 0;
    for (i = 0; i < 8 && D_001F4020.e[i].id != id; i++) {
        if (D_001F4020.e[i].val < D_001F4020.e[best].val) {
            best = i;
        }
    }
    if (i == 8) {
        func_0042D170(D_001F4020.e[best].w8, id, D_001F4020.w0, D_001F4020.w4);
        D_001F4020.e[best].id = id;
        i = best;
        ret = 1;
    }
    if (i != 0) {
        t = D_001F4050[0];
        D_001F4050[0] = D_001F4050[i];
        D_001F4050[i] = t;
    }
    D_001F4020.e[0].val = D_001DF9C8;
    return ret;
}
/* localdecomp:end func_0042DA20 */
