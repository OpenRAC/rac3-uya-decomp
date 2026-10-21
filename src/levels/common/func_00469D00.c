#include "common.h"

typedef struct { u8 p0[4]; u32 w4; u8 b8; u8 p9; u16 h_a; f32 f_c; u8 p10[0x30 - 0x10]; f32 f30; } S_00469D00;
extern void func_0045E580(S_00469D00 *p);

/* localdecomp:start func_00469D00 */
void func_00469D00(S_00469D00 *p) {
    s32 t;
    __asm__ __volatile__("lqc2 $vf1, 0x10(%0)\n\tlqc2 $vf2, 0x20(%0)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0x10(%0)" : : "r"(p) : "memory");
    p->f_c = p->f_c + p->f30;
    p->b8 = p->b8 + 1;
    t = (s32)p->h_a - 1;
    p->h_a = t;
    if ((t << 16) == 0) {
        p->h_a = 2;
        p->w4 = p->w4 + 0xFF000000;
    }
    if ((p->w4 & 0xFF000000) == 0) {
        func_0045E580(p);
    }
}
/* localdecomp:end func_00469D00 */
