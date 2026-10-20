#include "common.h"
typedef struct {
    u8 pad0[20];
    s32 idx;
    s32 val;
} S_327318_Vars;
typedef struct {
    u8 pad0[104];
    S_327318_Vars *vars;
} S_327318_Moby;
typedef struct {
    u8 pad0[32];
    s32 (*get)(void *a0);
    s32 (*get2)(void *a0);
} S_327318_Cls;
extern u8 *D_001E009C;
extern S_327318_Moby *func_003252E8(void);
extern S_327318_Cls *func_00438488(s32, s32, s32);
s32 func_00327318(s32 a0) {
    S_327318_Vars *v;
    S_327318_Cls *c;
    s32 r;
    if (a0 == -3) {
        return 0;
    }
    v = func_003252E8()->vars;
    if (v->idx == -1) {
        return -1;
    }
    c = func_00438488(6877, 0, 104);
    r = c->get(D_001E009C + (v->idx << 8));
    if (r == -1 && a0 != -1) {
        r = c->get2(D_001E009C + (v->idx << 8));
    }
    if (a0 == -2) {
        return r == v->val;
    }
    return r == a0;
}
