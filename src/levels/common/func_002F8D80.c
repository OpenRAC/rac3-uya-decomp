#include "common.h"

/* localdecomp:start func_002F8D80 */
typedef int Q_2F8D80 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2F8D80;
typedef struct {
    u8 pad0[48];
    u8 v48[16];
    u8 v64[16];
    s32 i80_unused[4];
    s32 i96;
    u8 pad100[4];
    void *p104;
    u8 b108;
    u8 b109;
    u8 pad110[2];
    f32 f112;
    f32 f116;
} S_2F8D80;
typedef struct {
    u8 pad0[16];
    V4_2F8D80 pos;
    u8 b32;
    u8 pad33[71];
    S_2F8D80 *s;
} O_2F8D80;
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_004475E8(void *, void *, f32);
extern void func_00441FB8(void *, s32, s32);
s32 func_002F8D80(O_2F8D80 *obj, O_2F8D80 *other, s32 flag, f32 a, f32 b) {
    S_2F8D80 *s = obj->s;
    V4_2F8D80 t0, t1;
    Q_2F8D80 x, y;
    u8 *s1;

    if (obj->b32 == 4) {
        return 0;
    }
    if (a == 0.0f) {
        a = func_004408C0(-0.5235988f, 0.5235988f);
    }
    if (b == 0.0f) {
        b = func_004408C0(0.0f, 0.5235988f);
    }
    if (flag) {
        s->b109 |= 8;
    }
    s1 = (u8 *)s + 48;
    if ((u8)(obj->b32 - 2) < 2) {
        if (flag) {
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(other->pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
            func_0040C0F0(s1, &t0, 0.33333334f);
        } else {
            func_0040C0F0(s1, s->v64, 0.13333334f);
        }
    }
    s->f116 = a;
    s->f112 = b;
    s->i96 = 0;
    s->p104 = other;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(other->pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(x));
    func_0040BF20(&t0, s1, &t1);
    func_0040C0F0((u8 *)s + 32, &t0, 1.0f);
    func_004475E8((u8 *)s + 32, (u8 *)s + 32, 0.20943953f);
    func_00441FB8(obj, 4, -1);
    return 1;
}
/* localdecomp:end func_002F8D80 */
