#include "common.h"

/* localdecomp:start func_00319028 */
typedef int Q_319028 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_319028;
typedef struct {
    V4_319028 v0;
    V4_319028 v16;
    V4_319028 pos;
    V4_319028 v48;
    V4_319028 v64;
    f32 rot[3];
    f32 rspd[3];
    f32 scl[3];
    f32 rot2[3];
    f32 rspd2[3];
    f32 scl2[3];
    s32 i152;
    void *owner;
    s32 i160;
    s32 i164;
    s32 i168;
    u8 pad172[4];
} S_319028;
extern Q_319028 D_001A4CC0;
extern S_319028 D_00273C00[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040BE68(void *, void *, void *, f32);
extern s32 func_0040BA90(s32 *);
void func_00319028(void *obj) {
    s32 i;
    S_319028 *arr = D_00273C00;
    for (i = 0; i < 6; i++) {
        S_319028 *s = &arr[i];
        V4_319028 d;
        Q_319028 x, y;
        if (s->owner != obj) {
            continue;
        }
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->v64));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
        *(Q_319028 *)&s->pos = D_001A4CC0;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(s->v64) : "j"(x));
        if (s->i160 != 0) {
            s->rot[0] = func_0040CEC8(s->rot[0], s->rspd[0] * 100.0f);
            s->rot[1] = func_0040CEC8(s->rot[1], s->rspd[1] * 100.0f);
            s->rot[2] = func_0040CEC8(s->rot[2], s->rspd[2] * 100.0f);
            s->rot2[0] = func_0040CEC8(s->rot2[0], s->rspd2[0] * 100.0f);
            s->rot2[1] = func_0040CEC8(s->rot2[1], s->rspd2[1] * 100.0f);
            s->rot2[2] = func_0040CEC8(s->rot2[2], s->rspd2[2] * 100.0f);
        } else {
            s->rot[0] = func_0040CEC8(s->rot[0], s->rspd[0] * 50.0f);
            s->rot[1] = func_0040CEC8(s->rot[1], s->rspd[1] * 50.0f);
            s->rot[2] = func_0040CEC8(s->rot[2], s->rspd[2] * 50.0f);
            s->rot2[0] = func_0040CEC8(s->rot2[0], s->rspd2[0] * 50.0f);
            s->rot2[1] = func_0040CEC8(s->rot2[1], s->rspd2[1] * 50.0f);
            s->rot2[2] = func_0040CEC8(s->rot2[2], s->rspd2[2] * 50.0f);
        }
        s->v0.x = func_0040C3C8(s->rot[0]) * s->scl[0];
        s->v0.y = func_0040C3E0(s->rot[1]) * s->scl[1];
        s->v0.z = -func_0040C3E0(s->rot[2]) * s->scl[2];
        s->v16.x = func_0040C3C8(s->rot2[0]) * s->scl2[0];
        s->v16.y = func_0040C3E0(s->rot2[1]) * s->scl2[1];
        s->v16.z = -func_0040C3E0(s->rot2[2]) * s->scl2[2];
        func_0040BE68(&s->v48, &s->pos, &s->v64, 1.0f - (f32)s->i160 / (f32)s->i164);
        if (func_0040BA90(&s->i160)) {
            if (s->i168 == 0) {
                s->i168 = 1;
            }
            if (func_0040BA90(&s->i152)) {
                s->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_00319028 */
