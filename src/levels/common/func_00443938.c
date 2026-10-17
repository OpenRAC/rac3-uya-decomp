#include "common.h"

typedef int u128_443938 __attribute__((mode(TI)));

typedef struct {
    u128_443938 v0;
    u128_443938 v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_443938;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_443938;

extern Ring_443938 D_001EAA80;
extern Entry_443938 D_001EED00[];
extern f32 func_0040BF38(u128_443938 *a0);

void func_00443938(u8 *a0, s32 a1, s32 a2, u128_443938 *a3, u128_443938 *t0, f32 f) {
    s32 slot = D_001EAA80.next;
    s32 flags = 0;
    Entry_443938 *e;
    Entry_443938 *p;

    if (a0[168] != 255) {
        p = &D_001EED00[a0[168]];
        if (p->owner == a0) {
            if (f < p->f2C) {
                p->flags |= a2;
                return;
            }
            flags = p->flags;
        }
    }
    e = &D_001EED00[slot];
    e->flags = a2 | flags;
    e->w20 = a1;
    e->b28 = 0;
    e->owner = a0;
    e->f34 = e->f2C = f;
    e->w3C = 0;
    if (func_0040BF38(t0) > 0.0001f) {
        e->w30 = 1;
    } else {
        e->w30 = 0;
    }
    D_001EED00[slot].v0 = *a3;
    D_001EED00[slot].v10 = *t0;
    a0[168] = slot;
    D_001EAA80.next = (slot + 1) & 63;
}
