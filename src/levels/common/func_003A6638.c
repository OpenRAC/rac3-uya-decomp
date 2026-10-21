#include "common.h"

/* localdecomp:start func_003A6638 */
typedef int Q_3A6638 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A6638;

typedef struct {
    u8 pad0[0x10];
    V4_3A6638 pos;
    u8 pad20[0xB0 - 0x20];
    u8 bB0;
    u8 padB1[0xC0 - 0xB1];
    V4_3A6638 vC0;
    u8 padD0[0xF0 - 0xD0];
    V4_3A6638 vF0;
    u8 pad100[0x100 - 0x100];
} O_3A6638;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[0x28 - 0x1C];
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x50 - 0x34];
    s32 f50;
    s32 f54;
    u8 pad58[0x5C - 0x58];
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    V4_3A6638 v70;
    V4_3A6638 v80;
    V4_3A6638 v90;
    V4_3A6638 vA0;
    V4_3A6638 vB0;
} P_3A6638;

extern O_3A6638 *D_001E009C;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
extern void func_0040C658(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_0040C638(void *, void *);
extern void func_00439610(O_3A6638 *);
extern void func_00441FB8(O_3A6638 *, s32, s32);

void func_003A6638(O_3A6638 *o, P_3A6638 *p) {
    O_3A6638 *m;
    V4_3A6638 t0, t16, t32;
    Q_3A6638 x, y, r;
    f32 k;

    p->f50 = -1;
    p->f54 = -1;
    p->f68 = 0;
    p->f6C = 0;
    p->f60 = 0;
    p->f64 = 0;
    func_0040C658(&p->v90, &o->vF0);
    m = &D_001E009C[p->f8];
    p->v70 = m->pos;
    p->v80 = m->vF0;
    o->pos = m->pos;
    o->vF0 = m->vF0;
    if (p->fC != 0) {
        if ((o->bB0 != 255 && (D_001BBC40[o->bB0 + D_001D545C * 16] & 0x80))
            || (p->f5C != -1 && D_001BBB18[p->f5C + D_001D545C * 8] != 0)) {
            p->f68 = 1;
            p->f0 = -1;
            p->f4 = -1;
            if (p->f10 != 0.0f || p->f14 != 0.0f || p->f18 != 0.0f) {
                func_0040BE90(&t16, &p->v90, p->f10);
                func_0040BE90(&t0, &p->vA0, p->f14);
                __asm__ __volatile__(
                    "lqc2 %0, %2\n"
                    "lqc2 %1, %3\n"
                    : "=&j"(x), "=&j"(y) : "m"(t0), "m"(t16));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(t16) : "j"(r));
                func_0040BE90(&t0, &p->vB0, p->f18);
                __asm__ __volatile__(
                    "lqc2 $vf1, %0\n"
                    "lqc2 $vf2, %1\n"
                    "vadd.xyz $vf2, $vf2, $vf1\n"
                    "lqc2 $vf1, %2\n"
                    "sqc2 $vf1, %3\n"
                    "sqc2 $vf2, %1\n"
                    "lqc2 $vf1, %1\n"
                    "lqc2 $vf2, %3\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, %4\n"
                    : : "m"(t0), "m"(t16), "m"(p->v70), "m"(t32), "m"(o->pos) : "memory");
                m->pos = o->pos;
            }
            if (p->f28 != 0.0f || p->f2C != 0.0f || p->f30 != 0.0f) {
                k = 0.017453292f;
                o->vF0.x = func_0040CEC8(p->v80.x, p->f28 * k);
                o->vF0.y = func_0040CEC8(p->v80.y, p->f2C * k);
                o->vF0.z = func_0040CEC8(p->v80.z, p->f30 * k);
                func_0040C638(&o->vC0, &o->vF0);
                m->vF0 = o->vF0;
                func_0040C638(&m->vC0, &m->vF0);
            }
            func_00439610(m);
        }
    }
    func_00441FB8(o, 1, -1);
}
/* localdecomp:end func_003A6638 */
