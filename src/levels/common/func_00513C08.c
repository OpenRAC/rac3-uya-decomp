#include "common.h"

typedef struct S_513C08o S_513C08o;
typedef struct {
    u8 pad0[0x10];
    s32 (*fn10)(S_513C08o *, s32);
} S_513C08vt;
struct S_513C08o {
    u8 pad0[8];
    S_513C08vt *vt;
};

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} S_513C08g;

extern S_513C08g D_001E1660[];
extern s32 D_001DC250;
extern S_513C08g *func_00511BF8(void);
extern s32 func_00511E28(S_513C08g *);
extern S_513C08o *func_00511368(s32, s32);
extern void func_0051C428(S_513C08o *, s32, s32);

s32 func_00513C08(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    S_513C08g *g;
    S_513C08g *x;
    S_513C08o *o;
    s32 ret = 0;

    g = D_001E1660;
    if (g->w4 != 0) {
        x = g;
    } else {
        x = func_00511BF8();
    }
    o = func_00511368(func_00511E28(x), a0);
    if (o == 0 || o->vt->fn10(o, D_001DC250) == 0) {
        o = 0;
    }
    if (o != 0) {
        ret = 1;
        func_0051C428(o, 4, a1);
        func_0051C428(o, 8, a3);
        func_0051C428(o, 16, a4);
        func_0051C428(o, 32, a2);
        func_0051C428(o, 64, a5);
    }
    return ret;
}
