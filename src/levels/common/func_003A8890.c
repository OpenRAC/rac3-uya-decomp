#include "common.h"

/* localdecomp:start func_003A8890 */
typedef int s128 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A8890;

typedef struct {
    V4_3A8890 v0;
    V4_3A8890 v10;
    V4_3A8890 v20;
    f32 f30;
} V_3A8890;

typedef struct M_3A8890 {
    u8 p0[0x10];
    V4_3A8890 pos;
    u8 b32;
    u8 p21[2];
    u8 b35;
    u8 p24[0xC];
    u8 b48;
    u8 b49;
    s16 h50;
    u16 h52;
    u8 p36[2];
    unsigned long d56;
    u8 p40[8];
    s32 w72;
    u8 p4C[0x1C];
    V_3A8890 *pVar;
    u8 p6C[0x2A];
    s16 h150;
    u8 p98[0x20];
    struct M_3A8890 *pB8;
    u8 pBC[0x34];
    s128 xF0;
} M_3A8890;

extern M_3A8890 *func_00435E70(s32 a, s32 b);

M_3A8890 *func_003A8890(M_3A8890 *src, V4_3A8890 *p, V4_3A8890 *q, s32 n, f32 f) {
    M_3A8890 *m = func_00435E70(6457, 128);
    V_3A8890 *v;

    if (m != 0) {
        m->b48 = 255;
        m->h50 = 255;
        m->b49 = 1;
        m->b32 = 0;
        v = m->pVar;
        m->d56 = src->d56;
        m->pos = *q;
        v->v0 = *p;
        v->v10 = *q;
        v->v20 = *q;
        *(f32 *)((u8 *)v + 0x2C) = 0.1f;
        *(f32 *)((u8 *)v + 0x1C) = 1.0f;
        m->h150 = 0;
        m->w72 = 0;
        *(f32 *)((u8 *)v + 0xC) = (f32)n;
        m->pB8 = src;
        v->f30 = f;
        m->b35 = 128;
        __asm__("sq $0,%0" : "=m"(m->xF0));
        m->h52 |= 0x100;
    }
    return m;
}
/* localdecomp:end func_003A8890 */
