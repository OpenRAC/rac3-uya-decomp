#include "common.h"

/* localdecomp:start func_00407010 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[16];
    u128_t v10;
    u8 pad20[3];
    u8 f23;
    u8 pad24[204];
    u128_t vF0;
} Obj_00407010;
extern s32 func_0040BAC0(s16 *);
extern s32 func_00406CA0(Obj_00407010 *, s32, s32);
s32 func_00407010(Obj_00407010 *o, s16 *q, s16 *r, u128_t *a, u128_t *b, s32 sub, s32 add, s32 val, s32 x, s32 y) {
    if (o == 0) {
        return 0;
    }
    if (*r == 2) {
        o->f23 = 0x80;
        return 0;
    }
    if (*r == 0) {
        if (func_0040BAC0(q) == 0) {
            o->f23 -= sub;
            if (func_00406CA0(o, x, y) != 0) {
                return 1;
            }
            *r = 2;
        } else {
            *r = 1;
            o->f23 = 0;
            *q = val;
            o->v10 = *a;
            o->vF0 = *b;
        }
    } else if (*r == 1) {
        if (func_0040BAC0(q) == 0) {
            o->f23 += add;
            if (o->f23 > 0x80) {
                o->f23 = 0x80;
            }
            if (func_00406CA0(o, x, y) != 0) {
                return 1;
            }
            *r = 2;
        } else {
            o->f23 = 0x80;
            *r = 2;
        }
    }
    return 1;
}
/* localdecomp:end func_00407010 */
