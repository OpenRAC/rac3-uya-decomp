#include "common.h"

/* localdecomp:start func_00460088 */
typedef int Q_460088 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_460088;
typedef struct {
    s32 i0;
    s32 i4;
    s32 i8;
    s32 i12;
    s16 h16;
    s16 h18;
    s16 h20;
    s16 h22;
    s16 h24;
} S_460088;
typedef struct {
    u8 pad0[4];
    s32 i4;
    u8 b8;
    u8 pad9;
    s16 h10;
    f32 f12;
    V4_460088 pos;
    S_460088 s;
} O_460088;
extern s32 D_001DFBC0[];
extern void func_0044AEB8(void *, void *);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0040BE68(void *, void *, void *, f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_00460088(O_460088 *obj) {
    S_460088 *s = &obj->s;
    V4_460088 tmp;
    V4_460088 a;
    V4_460088 b;
    f32 t;

    if (D_001DFBC0[0] & 1) {
        obj->b8++;
    }
    if (s->h16 != 0) {
        Q_460088 x, y;
        *(volatile s32 *)0x10000000 = 0;
        func_0044AEB8(&tmp, s);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(x));
        obj->i4 = func_0040D020(s->i8 & 0xFFFFFF, s->i8, 1.0f - (f32)obj->h10 / (f32)s->h16);
        obj->f12 = (f32)(s->h22 * 1000);
        if (func_0040BAC0(&obj->h10) != 0) {
            s->h16 = 0;
            obj->h10 = s->h18;
        }
    } else if (s->h18 != 0) {
        Q_460088 x, y;
        func_0044AEB8(&a, s);
        func_0044AEB8(&b, &s->i4);
        t = (f32)obj->h10 / (f32)s->h18;
        func_0040BE68(&tmp, &b, &a, t);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(x));
        obj->f12 = ((f32)(s->h22 - s->h24) * t + (f32)s->h24) * 1000.0f;
        obj->i4 = func_0040D020(s->i12, s->i8, t);
        if (func_0040BAC0(&obj->h10) != 0) {
            s->h18 = 0;
            obj->h10 = s->h20;
        }
    } else {
        Q_460088 x, y;
        func_0044AEB8(&tmp, &s->i4);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(x));
        obj->i4 = func_0040D020(s->i12 & 0xFFFFFF, s->i12, (f32)obj->h10 / (f32)s->h20);
        obj->f12 = (f32)(s->h24 * 1000);
        if (func_0040BAC0(&obj->h10) != 0) {
            func_0045E580(obj);
        }
    }
}
/* localdecomp:end func_00460088 */
