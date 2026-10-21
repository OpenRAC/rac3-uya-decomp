#include "common.h"

/* localdecomp:start func_0031BD78 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s32 i0;
    f32 f4;
    s32 i8;
    u8 padC[4];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 i20;
    s32 i24;
    s32 i28;
    s32 i2C;
    f32 v30[3];
    s32 i3C;
} P_0031BD78;
typedef struct {
    u8 pad0[0x10];
    u128_t v10;
    u8 b20;
    u8 pad21[15];
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    P_0031BD78 *p68;
} O_0031BD78;
extern O_0031BD78 *func_00435E70(s32, s32);
extern void func_0031BF40(void);
extern void func_004026A0(void (*)(void), O_0031BD78 *);
O_0031BD78 *func_0031BD78(u128_t *a, f32 *v, s32 n, s32 i3, s32 i4, s32 i5, s32 i6, s32 i7, f32 f0, f32 f1, f32 f2, f32 f3) {
    O_0031BD78 *o;
    P_0031BD78 *p;
    f32 *q;
    o = func_00435E70(0xDC1, 0x80);
    if (o != 0) {
        o->b20 = 0;
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b31 = 1;
        o->h34 |= 0x41;
        o->v10 = *a;
        p = o->p68;
        q = p->v30;
        q[0] = v[0];
        q[1] = v[1];
        q[2] = v[2];
        p->f1C = f3;
        p->f4 = 1.0f / (f32)n;
        p->i20 = i3;
        p->i24 = i4;
        p->i28 = i5;
        p->i2C = i6;
        p->i3C = i7;
        p->f10 = f0;
        p->f14 = f1;
        p->f18 = f2;
        p->i0 = n;
        p->i8 = 0;
        func_004026A0(func_0031BF40, o);
    }
    return o;
}
/* localdecomp:end func_0031BD78 */
