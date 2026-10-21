#include "common.h"

/* localdecomp:start func_00443840 */
typedef int u128_443840 __attribute__((mode(TI)));

typedef struct {
    u128_443840 v0;
    u128_443840 v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 b29;
    u16 h2A;
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_443840;

typedef struct {
    u128_443840 v0;
    s32 w10;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    f32 f24;
    s32 w28;
} Src_443840;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_443840;

extern Ring_443840 D_001EAA80;
extern Entry_443840 D_001EED00[];

void func_00443840(u8 *a0, Src_443840 *t0) {
    s32 slot = D_001EAA80.next;
    s32 flags = 0;
    Entry_443840 *e;
    Entry_443840 *p;

    if (a0[168] != 255) {
        p = &D_001EED00[a0[168]];
        if (p->owner == a0) {
            if (p->f2C > t0->f1C) {
                p->flags |= t0->flags;
                return;
            }
            flags = p->flags;
        }
    }
    e = &D_001EED00[slot];
    __asm__("sq $0,%0" : "=m"(e->v0));
    D_001EED00[slot].v10 = t0->v0;
    e->flags = t0->flags | flags;
    e->w20 = t0->w10;
    e->b28 = t0->b18;
    e->b29 = t0->b19;
    e->h2A = t0->h1A;
    e->f2C = t0->f1C;
    e->f34 = t0->f24;
    e->w30 = t0->w20;
    e->owner = a0;
    e->w3C = t0->w28;
    a0[168] = slot;
    D_001EAA80.next = (slot + 1) & 63;
}
/* localdecomp:end func_00443840 */
