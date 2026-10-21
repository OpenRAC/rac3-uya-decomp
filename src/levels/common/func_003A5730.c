#include "common.h"

/* localdecomp:start func_003A5730 */
typedef int s128_3A5730 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[0x24 - 0x14]; f32 x24; u8 pad28[0x44 - 0x28]; u16 x44; } O_3A5730;
typedef struct M_3A5730 {
    u8 pad0[0x10];
    s128_3A5730 x10;
    u8 pad20[0x4];
    O_3A5730 *x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x4];
    u16 x34;
    u8 pad36[0xD];
    u8 x43;
    u8 pad44[0x24];
    struct V_3A5730 *x68;
    u8 pad6c[0x2C];
    s32 x98;
    u8 pad9c[0x54];
    s128_3A5730 xF0;
} M_3A5730;
typedef struct V_3A5730 {
    u8 pad0[0x5E];
    u8 x5E;
    u8 x5F;
    u8 x60;
    u8 pad61[0x2FC - 0x61];
    s32 x2FC;
    u8 pad300[0x320 - 0x300];
    s128_3A5730 x320;
    u8 pad330[0x3AC - 0x330];
    f32 x3AC;
} V_3A5730;
extern void func_00441FB8(M_3A5730 *, s32, s32);
extern void func_00441C78(M_3A5730 *, s32, s32, s32);

void func_003A5730(M_3A5730 *m) {
    V_3A5730 *v = m->x68;
    O_3A5730 *t;

    v->x5E = 0;
    v->x60 = 0;
    v->x5F = 0;
    __asm__("sq $0,%0" : "=m"(m->xF0));
    t = m->x24;
    m->x2C = t->x24;
    m->x10 = v->x320;
    *(f32 *)((u8 *)m + 0xF8) = v->x3AC;
    m->x34 &= 0xFFBE;
    m->x34 |= t->x44 & 0x1000;
    m->x98 = t->x10;
    m->x34 &= 0xFFFD;
    if (m->x43 != 2) {
        func_00441C78(m, 2, 0, 10);
    }
    func_00441FB8(m, 6, 3);
    if (v->x2FC != -1) {
        func_00441FB8(m, 8, -1);
    }
}
/* localdecomp:end func_003A5730 */
