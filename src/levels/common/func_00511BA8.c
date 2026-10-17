#include "common.h"

extern void func_00511BA8();

extern void func_00512248();
extern void func_005110B8(s32);
extern void func_005122A0(void);
typedef struct { s32 a[5]; s32 idx; } Q_3E1668;
typedef struct { s32 pad; Q_3E1668 *q; } S_3E1668;
void func_00511BA8(S_3E1668 *p) {
    s32 v; func_00512248(p); v = p->q->a[p->q->idx]; if (v) func_005110B8(v); func_005122A0();
}
