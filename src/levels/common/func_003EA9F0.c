#include "common.h"

/* localdecomp:start func_003EA9F0 */
typedef int s128_003EA9F0 __attribute__((mode(TI)));
typedef struct {
    s128_003EA9F0 m0;
    s128_003EA9F0 m10;
    s128_003EA9F0 m20;
    s128_003EA9F0 m30;
} Mtx_003EA9F0;
typedef struct {
    u8 pad0[256];
    s32 state;
    u8 pad104[52];
    s32 id;
} Sub_003EA9F0;
typedef struct {
    u8 pad0[84];
    Mtx_003EA9F0 *mtx;
    u8 pad58[248];
    Sub_003EA9F0 sub;
    u8 pad28C[152];
    s32 f324;
} Ent_003EA9F0;
typedef struct {
    u8 pad0[8];
    s32 id;
} Tgt_003EA9F0;
typedef struct {
    u8 pad0[128];
    s32 f80;
    u8 pad84[52];
    Tgt_003EA9F0 tgt;
} Moby_003EA9F0;
typedef struct {
    s128_003EA9F0 m0;
    s128_003EA9F0 m10;
    s128_003EA9F0 m20;
    s128_003EA9F0 m30;
    u8 pad40[48];
    Moby_003EA9F0 *moby;
    u8 pad74[32];
    s32 idx;
} Obj_003EA9F0;
extern u8 D_001E2AC0[];
extern void func_003EA090(Obj_003EA9F0 *);
extern void func_003EA998(Obj_003EA9F0 *);
extern void func_003F3EA0(s32, s128_003EA9F0 *, f32);
void func_003EA9F0(Obj_003EA9F0 *o) {
    Ent_003EA9F0 *e;
    Sub_003EA9F0 *s;
    Tgt_003EA9F0 *t;
    e = (Ent_003EA9F0 *)(D_001E2AC0 + o->idx * 1120);
    s = &e->sub;
    t = &o->moby->tgt;
    if (s->state == 43 || (u32)(s->state - 35) < 3) {
        if (t->id != s->id) {
            e->mtx->m30 = o->m30;
            e->mtx->m0 = o->m0;
            e->mtx->m10 = o->m10;
            e->mtx->m20 = o->m20;
            func_003EA090(o);
            ((Ent_003EA9F0 *)(D_001E2AC0 + o->idx * 1120))->f324 = 45;
        }
    }
    func_003EA998(o);
    func_003F3EA0(o->idx, &o->m30, 0.5f);
    o->moby->f80 = 0;
}
/* localdecomp:end func_003EA9F0 */
