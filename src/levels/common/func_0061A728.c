#include "common.h"

typedef struct {
    u8 pad[4];
    s32 (*f4)(void *);
    u8 pad8[24];
    s32 (*f32)(void *);
} V61A728;

typedef struct O61A728 {
    u8 pad[184];
    struct O61A728 *parent;
} O61A728;

extern V61A728 *func_005BF058(O61A728 *);

s32 func_0061A728(O61A728 *o) {
    s32 r = 0;
    V61A728 *v;

    if (func_005BF058(o) != 0) {
        r = func_005BF058(o)->f32(o);
        if (r != 0) {
            return r;
        }
    }
    while (o->parent != 0) {
        o = o->parent;
    }
    v = func_005BF058(o);
    if (v != 0) {
        r = v->f4(o);
    }
    return r;
}
