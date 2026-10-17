#include "common.h"

typedef struct Obj Obj;
typedef struct {
    void *pad0;
    void *pad4;
    void *pad8;
    void *padC;
    s32 (*check)(Obj *, s32);
} ObjVtbl;

struct Obj {
    u8 pad0[8];
    ObjVtbl *vt;
    u8 padC[0x3E];
    s16 field_4A;
};

extern s32 D_001E1660[];
extern s32 D_001DC1F0;
extern void *func_00511BF8(void);
extern void *func_00511E28(void *);
extern Obj *func_00511368(void *, s32);
extern void func_0051AAD0(Obj *, s32);

s32 func_00513F60(s32 a0, s32 a1, s32 a2) {
    s32 *g;
    void *p;
    Obj *o;
    s32 r = 0;

    g = D_001E1660;
    if (g[1] != 0) p = g;
    else p = func_00511BF8();
    o = func_00511368(func_00511E28(p), a0);
    if (o == 0 || o->vt->check(o, D_001DC1F0) == 0) o = 0;
    if (o != 0) {
        func_0051AAD0(o, a1);
        r = 1;
        o->field_4A = a2;
    }
    return r;
}
