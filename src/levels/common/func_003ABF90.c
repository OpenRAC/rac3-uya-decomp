#include "common.h"

typedef struct { u8 p0[0x34]; u16 h34; } M_3ABF90;
extern void func_00425C18(M_3ABF90 *, s32, s32, s32, s32);
extern s32 D_001DE760[2];

void func_003ABF90(M_3ABF90 *m, s32 i) {
    m->h34 &= ~0x80;
    func_00425C18(m, D_001DE760[i], 14, 14, 14);
}
