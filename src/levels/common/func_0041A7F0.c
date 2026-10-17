#include "common.h"
typedef struct { u8 pad[12]; s16 a; s16 b; } S_0041A7F0;
typedef struct { u8 pad[104]; S_0041A7F0 *p; } T_0041A7F0;
void func_0041A7F0(T_0041A7F0 *t, int v) {
    S_0041A7F0 *p = t->p;
    p->a = 4;
    p->b = v;
}
