#include "common.h"

typedef int s128_455C88 __attribute__((mode(TI)));

typedef union {
    s128_455C88 q;
    f32 f[4];
} V_455C88;

typedef struct {
    u8 pad0[0x10];
    V_455C88 v16;
} P_455C88;

typedef struct {
    V_455C88 v0;
    V_455C88 v16;
    V_455C88 v32;
    u8 pad30[0x40 - 0x30];
    s32 w64;
    u8 pad44[0x50 - 0x44];
    P_455C88 *p80;
    u8 pad54[0x58 - 0x54];
    s32 w88;
    u8 pad5C[0x70 - 0x5C];
    V_455C88 v112;
} S_455C88;

extern s32 func_00455A60(P_455C88 *a0, S_455C88 *s);
extern void func_004559A8(P_455C88 *a0, S_455C88 *s);
extern f32 func_0040BFE8(void *a, void *b);
extern void func_00454C30(P_455C88 *a0, S_455C88 *s, s32 a2, s32 a3, f32 f12);

#define RESET_455C88()                          \
    {                                           \
        s128_455C88 t = s->v16.q;               \
        s->v0.q = t;                            \
        s->v32.q = t;                           \
        func_00454C30(a0, s, a2, a3, 12.0f);    \
        s->v112.q = a0->v16.q;                  \
        s->w64 = 0;                             \
    }

void func_00455C88(P_455C88 *a0, S_455C88 *s, s32 a2, s32 a3) {
    V_455C88 tmp;
    V_455C88 *pos;

    s->w88 = func_00455A60(a0, s);
    if (a2 == 0 && a3 == 0) {
        func_004559A8(a0, s);
    }
    if (s->p80 != 0) {
        s->v16.q = s->p80->v16.q;
        tmp.q = s->p80->v16.q;
    } else {
        tmp.q = s->v16.q;
    }
    if (s->v16.f[0] == 0.0f && s->v16.f[1] == 0.0f) {
        return;
    }
    if (func_0040BFE8(&s->v32, &tmp) > 1.0f) {
        RESET_455C88()
    }
    pos = &a0->v16;
    if (func_0040BFE8(pos, s) < 0.75f) {
        RESET_455C88()
    }
    if (func_0040BFE8(pos, &s->v112) > 8.0f) {
        RESET_455C88()
    }
    if (s->w64 >= 8) {
        RESET_455C88()
    }
}
