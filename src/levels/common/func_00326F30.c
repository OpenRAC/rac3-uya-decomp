#include "common.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p1[3]; s32 w24; u8 p2[0xC]; u16 h34; u8 p3[0x62]; s32 w98; } M_326F30;
extern void func_004A6DF8(M_326F30 *, s32);
void func_00326F30(M_326F30 *m) {
    m->b20 = 253;
    m->h34 |= 2;
    if (m->w24 != 0) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_004A6DF8(m, 1);
    }
}
