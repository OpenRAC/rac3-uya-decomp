#include "common.h"

/* localdecomp:start func_003405B0 */
typedef int Q_3405B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3405B0;
typedef struct {
    u8 pad0[16];
    s32 i16;
} T_3405B0;
typedef struct C_3405B0 {
    u8 pad0[16];
    V4_3405B0 pos;
    u8 pad32[4];
    T_3405B0 *p36;
    u8 pad40[9];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[98];
    s32 i152;
    u8 pad156[36];
    u8 m192[16];
    u8 m208[16];
    u8 pad224[16];
    u8 m240[16];
} C_3405B0;
typedef struct {
    u8 pad0[12];
    f32 f12;
    C_3405B0 *c[4];
    u8 pad32[16];
    s32 a48[4];
    u32 a64[3];
    u32 a76[3];
} S_3405B0;
extern void func_0040C638(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0044B598(void *, s32);
extern void func_004397B0(void *);
extern void func_0044AEB8(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C960(void *, void *, void *);
void func_003405B0(u8 *obj) {
    S_3405B0 *s = *(S_3405B0 **)(obj + 104);
    V4_3405B0 t0, t1;
    Q_3405B0 a, b;
    s32 i;

    if (s->c[0]->p36 != 0) {
        s->c[0]->h52 &= 0xFFFE;
        s->c[0]->b49 = 1;
        s->c[0]->i152 = s->c[0]->p36->i16;
    }
    func_0040C638(s->c[0]->m192, s->c[0]->m240);
    func_0040BE90(s->c[0]->m192, s->c[0]->m192, s->f12);
    func_0040BE90(s->c[0]->m208, s->c[0]->m208, s->f12);
    func_0044B598(s->c[0], func_0040D020(0x80FF8000, s->a48[0], s->f12));
    func_004397B0(s->c[0]);
    for (i = 1; i < 4; i++) {
        if (s->c[i] != 0) {
            if (s->c[i]->p36 != 0) {
                s->c[i]->h52 &= 0xFFFE;
                s->c[i]->b49 = 1;
                s->c[i]->i152 = s->c[i]->p36->i16;
            }
            func_0044AEB8(&t0, &s->a64[i - 1]);
            func_0040C2D0(&t0, &t0, s->c[0]->m192);
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(t0));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(s->c[0]->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(s->c[i]->pos) : "j"(b));
            func_0044AEB8(&t1, &s->a76[i - 1]);
            func_0040C638(s->c[i]->m192, &t1);
            func_0040C960(s->c[i]->m192, s->c[0]->m192, s->c[i]->m192);
            func_0044B598(s->c[i], func_0040D020(0x80FF8000, s->a48[i], s->f12));
            func_004397B0(s->c[i]);
        }
    }
}
/* localdecomp:end func_003405B0 */
