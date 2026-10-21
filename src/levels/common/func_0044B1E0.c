#include "common.h"

/* localdecomp:start func_0044B1E0 */
typedef int Q_44B1E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_44B1E0;
typedef struct {
    u8 pad0[0x10];
    V_44B1E0 pos;
    u8 f20;
    u8 pad21[0x23 - 0x21];
    u8 f23;
    u8 pad24[0x40 - 0x24];
    u8 f40;
    u8 f41;
    u8 f42;
    u8 f43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    u8 pad60[0x7C - 0x60];
    u16 f7C;
    u8 pad7E[0xAA - 0x7E];
    s16 fAA;
    u8 padAC[0xC0 - 0xAC];
    Q_44B1E0 fC0;
    Q_44B1E0 fD0;
    Q_44B1E0 fE0;
    Q_44B1E0 fF0;
} O_44B1E0;
typedef struct {
    Q_44B1E0 hist[2][8];
    u8 pad100[0x10];
    s32 delay[4];
    O_44B1E0 *objs[4];
    f32 scale[4];
    s16 idx;
    s16 count;
    O_44B1E0 *src;
    s32 n;
    s32 on;
} S_44B1E0;

extern void func_0044B4B8(S_44B1E0 *);
extern void func_00436350(O_44B1E0 *);
extern void func_0040BE90(void *, void *, f32);
extern void func_00439610(O_44B1E0 *);

void func_0044B1E0(S_44B1E0 *s, s32 dec) {
    V_44B1E0 d;
    Q_44B1E0 x, y;
    O_44B1E0 *src;
    O_44B1E0 *o;
    s32 i, j, d0, done;
    O_44B1E0 *p;
    Q_44B1E0 *h;

    if (s->on == 0) {
        return;
    }
    if (s->src == 0 || s->src->f20 == 254 || s->src->f20 == 253) {
        func_0044B4B8(s);
        return;
    }
    *(Q_44B1E0 *)((s->idx << 4) + (s32)s) = *(Q_44B1E0 *)&s->src->pos;
    ((Q_44B1E0 *)((s->idx << 4) + (s32)s))[8] = s->src->fF0;
    s->idx = (s->idx + 1) % 8;
    if (++s->count > 8) {
        s->count = 8;
    }
    for (i = 0; i < s->n; i++) {
        d0 = s->delay[i];
        if (s->count >= d0) {
            o = s->objs[i];
            j = (s->idx - d0 + 8) % 8;
            o->f42 = s->src->f42;
            o->f43 = s->src->f43;
            o->f40 = s->src->f40;
            o->f41 = s->src->f41;
            o->f44 = s->src->f44;
            if (o->fAA == 0) {
                o->f58 = s->src->f58;
                o->f5C = s->src->f5C;
            } else {
                func_00436350(o);
            }
            h = (Q_44B1E0 *)((j << 4) + (s32)s);
            *(Q_44B1E0 *)&o->pos = h[0];
            o->fF0 = h[8];
            if (s->scale[i] != 0.0f) {
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->src->pos));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
                func_0040BE90(&d, &d, s->scale[i]);
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(x));
            }
            func_00439610(o);
            src = s->src;
            if (src->f7C & 0x8000) {
                o->fC0 = src->fC0;
                o->fD0 = src->fD0;
                o->fE0 = src->fE0;
            }
        }
    }
    if (dec != 0) {
        done = 1;
        for (i = 0; i < s->n; i++) {
            p = s->objs[i];
            if (p != 0) {
                p->f23 -= (dec < p->f23) ? dec : p->f23;
                if (p->f23 != 0) {
                    done = 0;
                }
            }
        }
        if (done) {
            func_0044B4B8(s);
        }
    }
}
/* localdecomp:end func_0044B1E0 */
