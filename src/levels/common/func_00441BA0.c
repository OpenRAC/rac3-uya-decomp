#include "common.h"

typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_00436350();
void func_00441BA0(S_3BE418 *p, s32 idx, s32 lim) {
    s32 v;
    s32 n;
    v = lim;
    if (!(lim < p->f24->e[idx]->n)) v = p->f24->e[idx]->n - 1;
    p->f42 = idx;
    p->f40 = v;
    p->f41 = v + 1;
    n = p->f24->e[idx]->n - 1;
    if (n < p->f41) p->f41 = n;
    p->f43 = idx;
    p->f44 = 0;
    if (!(p->f41 < p->f24->e[idx]->n)) p->f41 = 0;
    func_00436350(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
