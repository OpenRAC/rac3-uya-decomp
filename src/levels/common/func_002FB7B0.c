#include "common.h"

/* localdecomp:start func_002FB7B0 */
typedef int Q_2FB7B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2FB7B0;
typedef struct {
    s32 a[4];
} __attribute__((packed)) C16_2FB7B0;
typedef struct {
    V4_2FB7B0 vel;
    f32 f16;
    f32 f20;
    s16 h24;
    s16 h26;
    f32 f28;
    s32 i32;
    s32 i36;
} S_2FB7B0;
typedef struct {
    u8 pad0[16];
    V4_2FB7B0 pos;
    u8 pad20[12];
    f32 f44;
    u8 pad30[56];
    S_2FB7B0 *s;
    u8 pad6C[80];
    u8 bBC;
    u8 padBD[51];
    f32 f240;
    f32 f244;
} O_2FB7B0;
extern C16_2FB7B0 D_001DC388;
extern V4_2FB7B0 D_001EAAC0;
extern f32 func_0040CEC8(f32, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern void func_0040C260(void *, void *, void *);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0044E108(void *, void *, void *, f32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00445C50(s32, s32);
extern void func_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_00436220(void *);
extern s32 func_0040BAC0(void *);
void func_002FB7B0(O_2FB7B0 *obj) {
    S_2FB7B0 *s = obj->s;
    s32 flag;
    s32 t, a, b;
    Q_2FB7B0 x, y;

    flag = 1;
    if (s->i32 != 0) {
        if (func_00440848(2) != 0) {
            flag = 0;
        }
    }
    if ((obj->bBC & 1) && flag) {
        C16_2FB7B0 cols;
        V4_2FB7B0 tmp;
        V4_2FB7B0 rnd;

        cols = D_001DC388;
        *(Q_2FB7B0 *)&rnd = 0;
        rnd.x = func_004408C0(-1.0f, 1.0f);
        rnd.y = func_004408C0(-1.0f, 1.0f);
        rnd.z = func_004408C0(-1.0f, 1.0f);
        tmp = rnd;
        func_0040C0F0(&tmp, &tmp, 0.016666668f);
        if (obj->bBC & 0xFE) {
            a = func_00445C50(cols.a[func_00440848(4)], obj->bBC >> 1);
            b = func_00445C50(0x4FFF, obj->bBC >> 1);
            func_00460318(&obj->pos, &tmp, a, b, 45, 50, 120, 1);
        } else {
            func_00460318(&obj->pos, &tmp, cols.a[func_00440848(4)], 0x4FFF, 45, 50, 120, 1);
        }
    }
    obj->f240 = func_0040CEC8(obj->f240, s->f16);
    obj->f244 = func_0040CEC8(obj->f244, s->f20);
    if (s->i36 != 0) {
        V4_2FB7B0 old;
        Q_2FB7B0 a1, b1;

        old = obj->pos;
        __asm__("lqc2 %0, %1" : "=j"(a1) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(b1) : "m"(s->vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a1) : "j"(a1), "j"(b1));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(a1));
        if (func_003F8448(&old, &obj->pos, 16, obj, 0) != 0) {
            func_0040C260(s, s, &D_001EAAC0);
            func_0040C0F0(s, s, func_0040BF38(s) * 0.8f);
        }
    } else {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(x));
    }
    func_0044E108(obj, s, s, 0.0040555559f);
    if (obj->pos.x < 0.0f || obj->pos.y < 0.0f || obj->pos.z < 0.0f) {
        func_00436220(obj);
        return;
    }
    t = s->h26 / 4;
    if (s->h24 < t) {
        obj->f44 = s->f28 * (f32)s->h24 / (f32)t;
    }
    if (func_0040BAC0(&s->h24) != 0) {
        func_00436220(obj);
    }
}
/* localdecomp:end func_002FB7B0 */
