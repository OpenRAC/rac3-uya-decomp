#include "common.h"

typedef struct O_4244A0 O_4244A0;
typedef struct {
    u8 pad0[16];
    s32 (*fn)(O_4244A0 *);
} V_4244A0;
struct O_4244A0 {
    u8 pad0[20];
    V_4244A0 *vt;
};

extern u8 *func_00537E58(u32);
extern O_4244A0 *func_004EC9B0(u32);

s32 func_004244A0(u32 a0) {
    s32 r = 0;
    O_4244A0 *o;
    if (((a0 >> 24) & 0xF) == 3) {
        r = *(s32 *)(func_00537E58(a0) + 720);
    } else {
        o = func_004EC9B0(a0);
        if (o != 0) {
            r = o->vt->fn(o);
        }
    }
    return r;
}
