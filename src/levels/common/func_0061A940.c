#include "common.h"

typedef struct {
    u8 pad0[0x24C9];
    u8 idx;
    u8 pad24CA[0x4E];
    u8 on;
} S_61A940;

extern s32 D_00241298[];
extern u8 D_001DA778[8];
extern S_61A940 *func_006197C0(s32);
extern void func_00589FE8(s32, s32, s32, s32);

void func_0061A940(void) {
    S_61A940 *p = func_006197C0(D_00241298[0]);
    if (p->on) {
        if (D_001DA778[p->idx] < 96) {
            D_001DA778[p->idx] += 2;
        }
    } else {
        if (D_001DA778[p->idx] == 0) {
            return;
        }
        D_001DA778[p->idx] -= 2;
    }
    if (D_001DA778[p->idx]) {
        func_00589FE8(0, 0, 0, D_001DA778[p->idx]);
    }
}
