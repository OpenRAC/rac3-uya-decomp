#include "common.h"

extern void func_0041A278();

typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern void func_0041A3F0();
void func_0041A278(S_38EC18 *p) {
    func_0041A3F0(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
