#include "common.h"

/* localdecomp:start func_00464068 */
typedef int Q_464068 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_464068;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    f32 f16;
    f32 f20;
    f32 f24;
} T_464068;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 i4;
    u8 b8;
    u8 b9;
    u16 h10;
    f32 f12;
    V4_464068 pos;
    T_464068 t;
} S_464068;
extern u8 *D_00221188[];
extern S_464068 *func_0045E438(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0040C8A0(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_0013D3E0(void);
void func_00464068(V4_464068 *pos, void *m, f32 r) {
    S_464068 *s;
    T_464068 *t;
    V4_464068 v0;
    V4_464068 v16;
    V4_464068 v32;
    u8 mtx[64];
    Q_464068 x, y;
    s32 a, b, c;

    s = func_0045E438(28);
    if (s == 0) {
        return;
    }
    t = &s->t;
    v16.x = func_004408C0(-0.03f, 0.03f);
    v16.y = func_004408C0(-0.03f, 0.03f);
    *(s32 *)&v16.z = 0;
    if (m != 0) {
        func_0040C8A0(mtx, m);
        func_0040C2F8(&v0, &v16, mtx);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v0));
    } else {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v16));
    }
    __asm__ __volatile__("vadd.xyz %0, %0, %2\n\tsqc2 %0, %1" : "+j"(x), "=m"(s->pos) : "j"(y));
    s->pos.z -= 0.05f;
    a = func_0013D3E0() % 96;
    if (a == 0) {
        a = 1;
    }
    b = func_0013D3E0() % a % 64;
    if (b == 0) {
        b = 1;
    }
    c = func_0013D3E0() % b % 48;
    s->b9 = 68;
    s->b3 = 72;
    s->b1 = 0;
    s->b8 = 0;
    s->i4 = (a + 143) | ((b + 143) << 8) | ((c + 111) << 16);
    s->b2 = *D_00221188[0];
    t->f4 = func_004408C0(0.0f, 0.0223456f) + 1e-5f;
    s->f12 = func_004408C0(10080.0f, 19950.0f);
    t->f8 = 0.0f;
    s->h10 = 252;
    t->f12 = 1.0f;
    __asm__("sq $0, %0" : "=m"(v32));
    if (m != 0) {
        v32.x = r;
        v32.z = -0.0025f;
        func_0040C2D0(&t->f16, &v32, m);
    } else {
        t->f16 = func_004408C0(-r, r);
        t->f20 = func_004408C0(-r, r);
        t->f24 = -0.0025f;
    }
}
/* localdecomp:end func_00464068 */
