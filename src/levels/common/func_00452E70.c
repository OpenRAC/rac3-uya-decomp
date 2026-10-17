#include "common.h"
typedef int u128_452E70 __attribute__((mode(TI)));
typedef struct Obj_452E70 {
    u8 pad0[16];
    u128_452E70 q10;
    u8 pad20[16];
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[4];
    unsigned long d38;
    u8 pad40[120];
    struct Obj_452E70 *pB8;
    u8 padBC[52];
    u128_452E70 qF0;
} Obj_452E70;
extern void func_00439610(Obj_452E70 *);
void func_00452E70(Obj_452E70 *a0, Obj_452E70 *a1) {
    a0->b30 = 255;
    a0->h32 = 255;
    a0->b31 = 1;
    if (a1 != 0) {
        a0->pB8 = a1;
        a0->q10 = a1->q10;
        a0->qF0 = a1->qF0;
        a0->d38 = a1->d38;
        func_00439610(a0);
    }
}
