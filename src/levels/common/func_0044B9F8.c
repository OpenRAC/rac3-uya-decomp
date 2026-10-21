#include "common.h"

/* localdecomp:start func_0044B9F8 */
typedef int s128_44B9F8 __attribute__((mode(TI)));

extern f32 func_0040BFB0(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C8C0(void *, void *);

int func_0044B9F8(int unused, u8 *list, int n, s128_44B9F8 *a, s128_44B9F8 *b, s128_44B9F8 *outPos, void *outMat) {
    s128_44B9F8 tmp[2];
    s128_44B9F8 mat[4];
    f32 best = 9999.0f;
    int bestIdx = 0;
    int i;
    u8 *p;
    s128_44B9F8 *pt = tmp;
    s128_44B9F8 *pm = mat;

    tmp[0] = *a;
    tmp[1] = *b;
    for (i = 0; i < n; i++) {
        f32 d = func_0040BFB0(pt, list + i * 64 + 48);
        if (d < best) {
            best = d;
            bestIdx = i;
        }
    }
    p = list + bestIdx * 64;
    func_0040C8E0(pm, p);
    func_0040C8C0(outMat, pm);
    *outPos = *(s128_44B9F8 *)(p + 48);
    return bestIdx;
}
/* localdecomp:end func_0044B9F8 */
