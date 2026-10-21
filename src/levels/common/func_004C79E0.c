#include "common.h"

typedef struct { u8 p0[0x16]; s16 h16; } F_3A4860;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3A4860;
typedef struct { f32 m[16]; } M_3A4860;
extern void func_0040CE20();
extern void func_0040CE78(void *, void *, void *, f32);
extern void func_0040CD88();
extern void func_0040C9B0();
void func_004C79E0(A_3A4860 *a, M_3A4860 *out, f32 t) {
    f32 tmp[12];
    s32 i;
    s32 frame = (s32)t;
    f32 frac;
    u8 *src = a->data + frame * a->stride;
    for (i = 0; i < a->n; i++, src += 0x18) {
        func_0040CE20(src, &out[i]);
    }
    { f32 ti, tf; /* retail keeps (s32)t in an FPR (cvt.w.s/cvt.s.w); gcc always goes through a GPR */ __asm__("cvt.w.s %0, %1" : "=f"(ti) : "f"(t)); __asm__("cvt.s.w %0, %1" : "=f"(tf) : "f"(ti)); frac = t - tf; }
    if (0.001f < frac) {
        s32 next = frame + 1;
        if (!(next < a->nframes)) next = 0;
        src = a->data + next * a->stride;
        for (i = 0; i < a->n; i++, src += 0x18) {
            func_0040CE20(src, tmp);
            func_0040CE78(&out[i], &out[i], tmp, frac);
        }
    }
    {
        F_3A4860 *f = (F_3A4860 *)(a->data + (s32)t * a->stride);
        s32 j;
        for (j = 0; j < a->n; j++, f++) {
            func_0040CD88(&out[j], &out[j].m[4], &out[j].m[8], &out[j]);
            if (f->h16 >= 0) func_0040C9B0(&out[j], &out[f->h16], &out[j]);
        }
    }
}
