#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    f32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
} Rec;

void func_0034A658(Rec *p, s32 a1, s32 a2, s32 a3, s32 t0, f32 f12) {
    if (p != 0) {
        p->g = t0;
        p->a = a1;
        p->b = a2;
        p->c = f12;
        p->e = a3;
        p->f = 72;
        p->d = 0;
    }
}
