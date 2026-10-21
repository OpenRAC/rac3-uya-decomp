#include "common.h"

/* localdecomp:start func_003ED200 */
typedef int Q_3ED200 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3ED200;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
} S_3ED200;
typedef struct {
    u8 pad0[8];
    S_3ED200 *s;
    u8 pad0C[0x40 - 0xC];
    V4_3ED200 v40;
} O_3ED200;
extern s32 D_001D545C;
extern V4_3ED200 D_001A4C60;
extern void func_004A7798(O_3ED200 *, u8, s32, u8, u8);
extern void func_0040C2D0(void *, void *, void *);

void func_003ED200(O_3ED200 *o) {
    S_3ED200 *s = o->s;
    V4_3ED200 a, b, c;
    Q_3ED200 q1, q2, q3;
    s32 v;
    if (D_001D545C == 0x30 || D_001D545C == 0x15) {
        func_004A7798(0, s->b0, s->w4, s->b1, s->b2);
        return;
    }
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->v40));
    c = D_001A4C60;
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(c));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q3));
    a.w = 0;
    func_0040C2D0(&b, &a, (u8 *)o + 0x50);
    if (__builtin_fabsf(b.x) <= 1.0f && __builtin_fabsf(b.y) <= 1.0f && __builtin_fabsf(b.z) <= 1.0f) {
        v = (s32)((f32)s->w4 * ((b.x + 1.0f) * 0.5f));
        if (s->w4 < v) v = s->w4;
        func_004A7798(o, s->b0, v, s->b1, s->b2);
        s->b3 = 1;
    } else if (s->b3 != 0) {
        if (0.0f < b.x) {
            func_004A7798(0, s->b0, s->w4, s->b1, s->b2);
        } else {
            func_004A7798(o, 0, 0, 0, 0);
        }
        s->b3 = 0;
    }
}
/* localdecomp:end func_003ED200 */
