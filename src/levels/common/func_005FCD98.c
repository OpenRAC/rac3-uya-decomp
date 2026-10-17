#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 pad[16];
    f32 x;
    f32 y;
    f32 z;
    u8 *owner;
} E_5FCD98;

extern E_5FCD98 D_002C44E0[128];
extern void func_005BA378(Vec4 *, E_5FCD98 *, s32);

s32 func_005FCD98(u8 *owner, Vec4 *pos, f32 x, f32 y, f32 z) {
    Vec4 v;
    E_5FCD98 *e;
    s32 i;

    e = D_002C44E0;
    for (i = 0; i < 128; i++, e++) {
        if (e->owner == 0) {
            if (pos != 0) {
                v.q = pos->q;
            } else {
                v.q = *(u128_t *)(owner + 16);
            }
            e->owner = owner;
            e->x = x;
            e->y = y;
            e->z = z;
            func_005BA378(&v, e, 1);
            return i;
        }
    }
    return -1;
}
