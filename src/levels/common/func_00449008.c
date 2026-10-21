#include "common.h"

/* localdecomp:start func_00449008 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_449008;
extern void func_0040BF20(V4_449008 *, V4_449008 *, V4_449008 *);
extern void func_0040C0F0(V4_449008 *, V4_449008 *, f32);
extern f32 func_0040BEF8(V4_449008 *, V4_449008 *);
extern f32 func_0040BF38(V4_449008 *);
extern f32 func_0040C3F8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040BE90(V4_449008 *, V4_449008 *, f32);
extern void func_0040CBC0(V4_449008 *, V4_449008 *, V4_449008 *);
void func_00449008(V4_449008 *out, V4_449008 *p, V4_449008 *q, s32 flag, f32 scale) {
    V4_449008 v;
    f32 d, n, ang;
    func_0040BF20(&v, q, p);
    func_0040C0F0(&v, &v, 1.0f);
    d = func_0040BEF8(p, q);
    if (flag == 0) {
        n = func_0040BF38(p);
        n *= func_0040BF38(q);
        if (n == 0.0f) {
            *(u128_t *)out = *(u128_t *)p;
            return;
        }
        d /= n;
    }
    ang = (1.5707964f - func_0040C3F8(d)) * 0.5f * scale;
    func_0040BE90(&v, &v, func_0040C3E0(ang));
    v.v[3] = func_0040C3C8(ang);
    func_0040CBC0(out, p, &v);
}
/* localdecomp:end func_00449008 */
