#include "common.h"

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[16];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M3C7568;

extern s32 func_004B6C68(void);
extern void func_00441FB8(M3C7568 *, s32, s32);

void func_003C7568(M3C7568 *m) {
    u8 st = m->state;

    switch (st) {
    case 0:
        if (func_004B6C68() != 0) {
            m->unk31 = 0;
            m->unk34 |= 1;
            func_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        if (func_004B6C68() == 0) {
            m->unk31 = st;
            m->unk34 &= ~1;
            func_00441FB8(m, 0, -1);
        }
        break;
    }
}
