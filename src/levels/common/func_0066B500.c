#include "common.h"

typedef struct {
    u8 pad[16];
    u8 *obj;
    void (*fn)(u8 *, s32);
    s32 time;
} Cb;

extern s32 D_001A5F78[];
extern u8 *D_0024C06C[];
extern u8 *func_0061B038(u8 *);

void func_0066B500(Cb *c) {
    u8 *obj;
    void (*fn)(u8 *, s32);
    u8 *r;

    obj = c->obj;
    if (obj == 0) {
        return;
    }
    fn = c->fn;
    if (fn == 0) {
        return;
    }
    if (D_001A5F78[0] <= c->time + 260) {
        return;
    }
    if (*(s32 *)(obj + 40) != 0 || obj == (r = D_0024C06C[0])) {
        fn(obj, 0);
        return;
    }
    r = func_0061B038(obj);
    if (r != 0 && r[44] != 0) {
        c->fn(c->obj, 0);
    }
}
