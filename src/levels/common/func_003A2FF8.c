#include "common.h"

/* localdecomp:start func_003A2FF8 */
typedef int s128_3A2FF8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[0x24 - 0x14]; f32 x24; u8 pad28[0x44 - 0x28]; u16 x44; } O_3A2FF8;
typedef struct M_3A2FF8 {
    u8 pad0[0x10];
    s128_3A2FF8 x10;
    u8 pad20[0x4];
    O_3A2FF8 *x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x4];
    u16 x34;
    u8 pad36[0xD];
    u8 x43;
    u8 pad44[0x24];
    struct V_3A2FF8 *x68;
    u8 pad6c[0x2C];
    s32 x98;
    u8 pad9c[0x54];
    s128_3A2FF8 xF0;
    u8 padFF[0x0];
} M_3A2FF8;
typedef struct V_3A2FF8 {
    u8 pad0[0x5E];
    u8 x5E;
    u8 x5F;
    u8 x60;
    u8 pad61[0x2EC - 0x61];
    s32 x2EC;
    u8 pad2F0[0x380 - 0x2F0];
    s128_3A2FF8 x380;
    u8 pad390[0x420 - 0x390];
    f32 x420;
} V_3A2FF8;
extern void func_00441FB8(M_3A2FF8 *, s32, s32);
extern void func_00441C78(M_3A2FF8 *, s32, s32, s32);

void func_003A2FF8(M_3A2FF8 *m) {
    V_3A2FF8 *v = m->x68;
    O_3A2FF8 *t;

    v->x5E = 0;
    v->x60 = 0;
    v->x5F = 0;
    __asm__("sq $0,%0" : "=m"(m->xF0));
    t = m->x24;
    m->x2C = t->x24;
    m->x10 = v->x380;
    *(f32 *)((u8 *)m + 0xF8) = v->x420;
    m->x34 &= 0xFFBE;
    m->x34 |= t->x44 & 0x1000;
    m->x98 = t->x10;
    m->x34 &= 0xFFFD;
    func_00441FB8(m, 7, 2);
    if (m->x43 != 8) {
        func_00441C78(m, 8, 0, 0);
    }
    if (v->x2EC != -1) {
        func_00441FB8(m, 9, -1);
    }
}
/* localdecomp:end func_003A2FF8 */
