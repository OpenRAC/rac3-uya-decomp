#include "common.h"

/* localdecomp:start func_00329678 */
typedef int Q_329678 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_329678;
typedef struct {
    V4_329678 vel;
    f32 f16;
    f32 f20;
    s16 h24;
    s16 h26;
    s16 h28;
    s16 h30;
    s32 arr[4];
    s32 i48;
    s32 i52;
    s32 i56;
    s16 h60;
    s16 h62;
} S_329678;
typedef struct {
    u8 pad0[16];
    V4_329678 pos;
    u8 pad20[12];
    f32 f44;
    u8 pad30[56];
    S_329678 *s;
    u8 pad6C[132];
    f32 f240;
    f32 f244;
} O_329678;
extern f32 func_0040CEC8(f32, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern void func_0040C260(void *, void *, void *);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0044E108(void *, void *, void *, f32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern void func_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_00436220(void *);
extern s32 func_0040BAC0(void *);
extern V4_329678 D_001EAAC0;
void func_00329678(O_329678 *obj) {
    V4_329678 tmp;
    V4_329678 rnd;
    S_329678 *s = obj->s;
    s32 i, n, t;
    Q_329678 a, b;

    obj->f240 = func_0040CEC8(obj->f240, s->f16);
    obj->f244 = func_0040CEC8(obj->f244, s->f20);
    if (s->i52 != 0) {
        tmp = obj->pos;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(s->vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(a));
        if (func_003F8448(&tmp, &obj->pos, 16, obj, 0) != 0) {
            func_0040C260(s, s, &D_001EAAC0);
            func_0040C0F0(s, s, func_0040BF38(s) * 0.8f);
        }
    } else {
        Q_329678 c, d;
        __asm__("lqc2 %0, %1" : "=j"(c) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(d) : "m"(s->vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(c), "j"(d));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(c));
    }
    func_0044E108(obj, s, s, (f32)s->h30 * 0.0078125f * 0.00027777778f);
    if (s->i48 == 1) {
        if (func_00440848(2) != 0) {
            V4_329678 *p = &obj->pos;
            *(Q_329678 *)&rnd = 0;
            rnd.x = func_004408C0(-1.0f, 1.0f);
            rnd.y = func_004408C0(-1.0f, 1.0f);
            rnd.z = func_004408C0(-1.0f, 1.0f);
            tmp = rnd;
            func_0040C0F0(&tmp, &tmp, 0.016666668f);
            n = func_00440848(4);
            func_00460318(p, &tmp, s->arr[n], 0, 45, s->h60, s->h62, s->i56);
        }
    }
    if (s->i48 == 4 || s->i48 == 2) {
        V4_329678 *q = &obj->pos;
        s32 *arr = s->arr;
        for (i = 2; i >= 0; i--) {
            *(Q_329678 *)&rnd = 0;
            rnd.x = func_004408C0(-1.0f, 1.0f);
            rnd.y = func_004408C0(-1.0f, 1.0f);
            rnd.z = func_004408C0(-1.0f, 1.0f);
            tmp = rnd;
            func_0040C0F0(&tmp, &tmp, 0.016666668f);
            n = func_00440848(4);
            func_00460318(q, &tmp, *(s32 *)((u8 *)arr + (n << 2)), 0, 45, s->h60, s->h62, s->i56);
        }
    }
    if (obj->pos.x < 0.0f || obj->pos.y < 0.0f || obj->pos.z < 0.0f) {
        func_00436220(obj);
        return;
    }
    t = s->h26 / 4;
    if (s->h24 < t) {
        obj->f44 = (f32)s->h28 * 0.0078125f * (f32)s->h24 / (f32)t;
    }
    if (func_0040BAC0(&s->h24) != 0) {
        func_00436220(obj);
    }
}
/* localdecomp:end func_00329678 */
