#include "common.h"

typedef struct {
    s32 f0;
    s32 a;
    s32 b;
} Inner378850;

typedef struct {
    u8 pad0[104];
    Inner378850 *inner;
} Obj378850;

f32 func_00378850(Obj378850 *obj) {
    Inner378850 *p = obj->inner;
    if ((p->a != -1 || p->b != -1) && (p->a != 0 || p->b != 0)) {
        return 0.5f;
    }
    return 0.25f;
}
