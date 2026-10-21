#include "common.h"

/* localdecomp:start func_003CB130 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0;
    u128_t v10;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x10];
    u16 h34;
    u8 pad36[0x62];
    s32 w98;
    u8 pad9c[0x54];
    u128_t vF0;
} O_3CB130;
typedef struct {
    u128_t v0;
    u128_t v10;
    s32 w20;
    s32 w24;
    u16 h28;
    u16 h2A;
    u16 h2C;
    u8 b2E;
    u8 b2F;
    u8 b30;
} Q_3CB130;
typedef struct {
    u8 pad0[0x10];
    u128_t v10;
    u8 pad20[0x10];
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[0x34];
    Q_3CB130 *q68;
    u8 pad6c[0x4C];
    O_3CB130 *wB8;
} R_3CB130;
extern R_3CB130 *func_00435E70(s32, s32);
extern void func_004A7200(s32, s32, R_3CB130 *);
extern void func_00439610(O_3CB130 *);

R_3CB130 *func_003CB130(O_3CB130 *o, u128_t *pos, u128_t *vec, u8 flag, s32 a4, s32 a5, s32 a6, s32 a7, s32 s0, s32 s1) {
    R_3CB130 *r;
    Q_3CB130 *q;
    r = func_00435E70(0x1B10, 0x80);
    if (r != 0) {
        if (flag) {
            func_004A7200(0, 0, r);
        } else {
            func_004A7200(1, 0, r);
        }
        o->w98 = 0;
        o->h34 = (o->h34 & 0xEFFF) | 0x42;
        r->b30 = 0xFF;
        r->wB8 = o;
        r->h32 = 0;
        r->b31 = 0;
        q = r->q68;
        r->v10 = o->v10;
        q->b2E = a4;
        q->b2F = a5;
        q->h2C = a7;
        q->w20 = s0;
        q->w24 = s1;
        if (flag) q->b30 = 1;
        if (o->h34 & 1) {
            o->b23 = 0;
            o->h34 = o->h34 & 0xFFFE;
            q->h2A = q->h2C;
            o->v10 = *pos;
            o->vF0 = *vec;
            q->h28 = 1;
        } else {
            q->h2A = a6;
            q->v0 = *pos;
            q->v10 = *vec;
            q->h28 = 0;
        }
        func_00439610(o);
    } else {
        o->v10 = *pos;
        o->vF0 = *vec;
    }
    return r;
}
/* localdecomp:end func_003CB130 */
