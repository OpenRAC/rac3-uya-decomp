#include "common.h"

/* localdecomp:start func_0046AB08 */
typedef int Q_46AB08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46AB08;
typedef struct {
    s32 w0;
    s32 w4;
    s16 h8;
    s16 hA;
    s32 wC;
} S_46AB08;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x9F];
    V4_46AB08 vC0;
} R_46AB08;
typedef struct { f32 x, y, z; } F3_46AB08;
typedef struct {
    f32 x, y, z;
    s32 wC;
    f32 x10, y10, z10;
    S_46AB08 *w1C;
} P_46AB08;
extern s32 D_001D6694;
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0045E580(void *);
extern s32 func_00444338(f32, s32, s32);
extern s32 func_0040BAC0(void *);

void func_0046AB08(u8 *o) {
    P_46AB08 *p = (P_46AB08 *)(o + 0x20);
    S_46AB08 *s;
    V4_46AB08 v, t, r;
    Q_46AB08 x1, x2, y;
    R_46AB08 *q;
    s32 d;
    if (p != 0) {
        s = p->w1C;
        *(f32 *)(o + 0xC) = (f32)((s->h8 * (s->wC - *(s16 *)(o + 0xA))) / s->wC + s->hA) * 1000.0f;
        v.x = p->x;
        v.y = p->y;
        v.z = p->z;
        func_0040BE90(&v, &v, 0.98f);
        p->x = v.x;
        p->y = v.y;
        p->z = v.z;
        if (D_001D6694 == 0 && (q = (R_46AB08 *)p->wC) != 0) {
            d = q->b20;
            if (d == 0xFE) goto kill;
            if (d != 0xFD) {
            t.x = p->x10;
            t.y = p->y10;
            t.z = p->z10;
            __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(v));
            __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(x1), "j"(x2));
            __asm__("sqc2 %1, %0" : "=m"(t) : "j"(y));
            p->x10 = t.x;
            p->y10 = t.y;
            p->z10 = t.z;
            func_0040C2D0(&r, &t, &q->vC0);
            __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(r));
            __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(*(V4_46AB08 *)(p->wC + 0x10)));
            } else {
kill:
                func_0045E580(o);
                return;
            }
        } else {
            __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(*(V4_46AB08 *)(o + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(v));
        }
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(x1), "j"(x2));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_46AB08 *)(o + 0x10)) : "j"(y));
        o[8]++;
        *(s32 *)(o + 4) = func_00444338((f32) * (s16 *)(o + 0xA) / (f32)s->wC, s->w4, s->w0);
        if (func_0040BAC0(o + 0xA)) {
            func_0045E580(o);
        }
    }
}
/* localdecomp:end func_0046AB08 */
