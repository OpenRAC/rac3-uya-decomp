#include "common.h"

/* localdecomp:start func_00346A00 */
typedef int Q_346A00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_346A00;
typedef struct {
    V4_346A00 v0;
    s16 pad16[5];
    s16 h26;
    u8 pad28[12];
    s32 i40;
    u8 pad44[4];
    V4_346A00 v48;
    V4_346A00 v64;
} S_346A00;
typedef struct {
    u8 pad0[16];
    V4_346A00 pos;
    u8 b32;
    u8 pad33[71];
    S_346A00 *p104;
} O_346A00;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} T_346A00;
extern u8 D_0014262F[];
extern T_346A00 D_002C5640[];
extern s32 func_00454168(s32, s32);
extern void func_00436220(O_346A00 *);
extern void func_004C6EC8(V4_346A00 *, V4_346A00 *);
extern void func_003477F8(O_346A00 *);
extern void func_0040BE68(V4_346A00 *, V4_346A00 *, V4_346A00 *, f32);
extern void func_003478E8(O_346A00 *, V4_346A00 *);
extern void func_00348A38(O_346A00 *, V4_346A00 *);
extern s32 func_00346D90(O_346A00 *, V4_346A00 *);
extern s32 func_0040BA90(void *);

void func_00346A00(O_346A00 *o) {
    V4_346A00 tmp;
    V4_346A00 t;
    S_346A00 *s;
    Q_346A00 a, b;
    s32 n;
    s32 i;
    s32 few;
    f32 hi;

    n = ((T_346A00 *)(D_0014262F[0] * 240 + (s32)D_002C5640))->b1;
    s = o->p104;
    if (func_00454168(3076, s->h26) == 0) {
        func_00436220(o);
        return;
    }
    if (o->b32 == 2) {
        func_004C6EC8(&o->pos, &o->pos);
        func_003477F8(o);
        return;
    }
    if (s->i40 == 1) {
        tmp = s->v64;
    } else {
        tmp = o->pos;
    }
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(s->v0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(a));
    if (s->i40 == 1) {
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(s->v64));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(s->v48));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(s->v64) : "j"(a));
    }
    if (o->b32 == 0) {
        o->b32 = 1;
    }
    few = n < 2;
    for (i = 0; i < 4; i++) {
        func_0040BE68(&t, &tmp, &o->pos, (f32)i * 0.25f);
        func_003478E8(o, &t);
    }
    if (!few) {
        func_00348A38(o, &o->pos);
        func_0040BE68(&t, &tmp, &o->pos, 0.5f);
        func_00348A38(o, &t);
    }
    if (o->pos.x < 2.0f || o->pos.x > 1021.0f || o->pos.y < 2.0f || o->pos.y > 1021.0f
        || o->pos.z < 2.0f || o->pos.z > 1021.0f) {
        if (o->pos.x < 5.0f) {
            o->pos.x = 5.0f;
        }
        if (o->pos.y < 5.0f) {
            o->pos.y = 5.0f;
        }
        if (o->pos.z < 5.0f) {
            o->pos.z = 5.0f;
        }
        hi = 1016.0f;
        if (hi < o->pos.x) {
            o->pos.x = hi;
        }
        if (hi < o->pos.y) {
            o->pos.y = hi;
        }
        if (hi < o->pos.z) {
            o->pos.z = hi;
        }
        o->b32 = 2;
    } else if (func_00346D90(o, &tmp) != 0 || func_0040BA90(&s->pad16) != 0) {
        o->b32 = 2;
    } else {
        func_003477F8(o);
    }
}
/* localdecomp:end func_00346A00 */
