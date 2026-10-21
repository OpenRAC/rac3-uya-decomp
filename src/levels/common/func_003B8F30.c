#include "common.h"

/* localdecomp:start func_003B8F30 */
typedef int Q_3B8F30 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3B8F30;

extern void func_003B8758(V4_3B8F30 *p, V4_3B8F30 *dir, V4_3B8F30 *proj, V4_3B8F30 *perp);
extern f32 func_003E4620(V4_3B8F30 *a, V4_3B8F30 *b);
extern f32 func_003E4660(V4_3B8F30 *a);
extern void func_00418598(V4_3B8F30 *v, f32 s, f32 len);

void func_003B8F30(u8 *seg, V4_3B8F30 *p, f32 *t, f32 s) {
    V4_3B8F30 dir;
    V4_3B8F30 proj;
    V4_3B8F30 perp;
    Q_3B8F30 a, b;

    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_3B8F30 *)(seg + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_3B8F30 *)seg));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(a));
    func_00418598(p, s * *(f32 *)(seg + 0x28), *(f32 *)(seg + 0x28));
    if (t != 0 && *(f32 *)(seg + 0x28) > 0.0f) {
        *t = func_003E4660(p) / *(f32 *)(seg + 0x28);
    }
    func_003B8758(p, &dir, &proj, &perp);
    if (func_003E4620(&dir, &proj) > 0.0f) {
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(perp));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(proj));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(a));
    } else {
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(perp));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(proj));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(a));
    }
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_3B8F30 *)seg));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*p));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(a));
}
/* localdecomp:end func_003B8F30 */
