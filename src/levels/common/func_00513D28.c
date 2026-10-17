#include "common.h"

typedef struct UnkObj513D28 UnkObj513D28;

typedef struct {
    void *pad0;
    void *pad4;
    void *pad8;
    void *padC;
    int (*isA)(UnkObj513D28 *, int);
} UnkVtbl513D28;

struct UnkObj513D28 {
    int pad0;
    int pad4;
    UnkVtbl513D28 *vtbl;
};

typedef struct {
    int w0;
    int w4;
} UnkMgr513D28;

extern UnkMgr513D28 D_001E1660[];
extern int D_001DC250;

extern UnkMgr513D28 *func_00511BF8(UnkMgr513D28 *);
extern void *func_00511E28(UnkMgr513D28 *);
extern UnkObj513D28 *func_00511368(void *, int);
extern void func_0051C288(UnkObj513D28 *);

int func_00513D28(int id) {
    UnkMgr513D28 *mgr;
    UnkObj513D28 *obj;
    UnkObj513D28 *cast;
    int ret = 0;
    if (D_001E1660->w4 != 0) {
        mgr = D_001E1660;
    } else {
        mgr = func_00511BF8(D_001E1660);
    }
    obj = func_00511368(func_00511E28(mgr), id);
    cast = (obj != 0 && obj->vtbl->isA(obj, D_001DC250)) ? obj : 0;
    if (cast != 0) {
        func_0051C288(cast);
        ret = 1;
    }
    return ret;
}
