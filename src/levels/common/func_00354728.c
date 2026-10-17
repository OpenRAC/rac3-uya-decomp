#include "common.h"

typedef struct {
    char pad0[0x10];
    int count;
    char pad14[0x1C - 0x14];
    int arg;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;

extern void func_0049B428(int, int, Obj *);
extern void func_00435D78(Obj *, int, int);

void func_00354728(Obj *obj, int arg) {
    Vars *v = obj->vars;
    int n;

    v->arg = arg;
    n = v->count - 1;
    v->count = n;
    if (n == 2) {
        func_0049B428(0, 0, obj);
    } else if (n == 1) {
        func_0049B428(1, 0, obj);
    } else if (n == 0) {
        func_0049B428(2, 0, obj);
        func_00435D78(obj, 3, -1);
    }
}
