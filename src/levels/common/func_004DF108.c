#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef float vec4_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_004DF108;

typedef struct {
    u8 pad0[0x10];
    V4_004DF108 v10;
    u8 pad20[0xA0];
    u8 mC0[0x30];
} O_004DF108;

typedef struct {
    u8 pad[0x1200];
    O_004DF108 *p[3];
} E_004DF108;

typedef struct {
    u8 m0[0x40];
    u8 m40[0x22D0 - 0x40];
    f32 s[3];
    u8 pad2[0x25C0 - 0x22DC];
    O_004DF108 *x25C0;
    u8 pad3[0x25E4 - 0x25C4];
    u8 x25E4;
    u8 pad4[0x2888 - 0x25E5];
    s16 x2888;
    s16 x288A;
} S_004DF108;

extern S_004DF108 D_001A4BE0;
extern V4_004DF108 D_001A4C60;
extern f32 D_002F42C0[];
extern void func_0040C5A8(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C960(void *, void *, void *);
extern void func_0040C2D0(void *, void *, void *);

/* localdecomp:start func_004DF108 */
void func_004DF108(void) {
    u128_t m[3];
    u128_t m2[3];
    V4_004DF108 v;
    S_004DF108 *g;
    s32 i, j;
    O_004DF108 *o;
    f32 f;

    if (D_001A4BE0.x2888 == 0) {
        return;
    }
    if (D_001A4BE0.x288A != 0) {
        f = D_002F42C0[++D_001A4BE0.x288A];
        if (f == -1.0f) {
            D_001A4BE0.x2888 = 0;
            D_001A4BE0.x288A = 0;
            return;
        }
        D_001A4BE0.s[2] = 1.0f;
        D_001A4BE0.s[0] = f;
        D_001A4BE0.s[1] = f;
    }
    g = &D_001A4BE0;
    func_0040C5A8(m);
    func_0040C0F0(&m[0], &m[0], g->s[0]);
    func_0040C0F0(&m[1], &m[1], g->s[1]);
    func_0040C0F0(&m[2], &m[2], g->s[2]);
    func_0040C960(m2, m, g->m40);
    func_0040C960(m2, g->m0, m2);
    func_0040C960(g->x25C0->mC0, g->x25C0->mC0, m);
    if (g->x25E4 == 0) {
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 3; j++) {
                E_004DF108 *e = (E_004DF108 *)((u8 *)&D_001A4BE0 + i * 80);
                o = e->p[0];
                if (j == 1) {
                    o = e->p[1];
                } else if (j == 2) {
                    o = e->p[2];
                }
                if (o != 0) {
                    vec4_t a, b, c, d, r1, r2;
                    func_0040C960(o->mC0, m2, o->mC0);
                    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->v10));
                    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001A4C60));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(a), "j"(b));
                    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r1));
                    func_0040C2D0(&v, &v, m2);
                    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(v));
                    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(D_001A4C60));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(c), "j"(d));
                    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r2));
                }
            }
        }
    }
    if (D_001A4BE0.x288A == 0 && D_001A4BE0.s[0] == 1.0f && D_001A4BE0.s[1] == 1.0f && D_001A4BE0.s[2] == 1.0f) {
        D_001A4BE0.x2888 = 0;
    }
    D_001A4BE0.s[0] = 1.0f;
    D_001A4BE0.s[1] = 1.0f;
    D_001A4BE0.s[2] = 1.0f;
}
/* localdecomp:end func_004DF108 */
