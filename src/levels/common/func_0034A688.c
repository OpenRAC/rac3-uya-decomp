#include "common.h"

typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    int wC;
} Unk34A688;

extern int func_0042DBA8(int, int);
extern void func_0045E320(void *, Unk34A688 *, int, int);

void func_0034A688(Unk34A688 *s, void *a1) {
    if (s == 0) {
        return;
    }
    s->f8 += s->f4;
    while (s->f8 > 1.0f) {
        s->f8 -= 1.0f;
        func_0045E320(a1, s, func_0042DBA8(s->h2, s->h0), s->wC);
    }
}
