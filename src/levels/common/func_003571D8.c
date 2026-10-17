#include "common.h"

typedef struct {
    u16 x0;
    u8 pad[10];
} S_1A7E18;

extern S_1A7E18 D_001A7E18[];
extern s32 func_003EB9E0(void *, s32);
extern void func_003ED198(void *, s32);

void func_003571D8(void *a, s32 i) {
    S_1A7E18 *p = &D_001A7E18[i];

    if (p->x0 == 0) {
        if (func_003EB9E0(a, i) == 0) {
            func_003ED198(a, i);
        }
        if (p->x0 == 0) {
            p->x0 = 1;
        }
    }
}
