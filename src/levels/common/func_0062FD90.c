#include "common.h"
extern float func_0058F430(float *);
extern void func_0058FB48(float *, void *);
extern void func_0058FDD0(float *, float *);
extern void func_0058F7B8(float *, void *, void *);
float func_0062FD90(u8 *p, float *v) {
    float m[16];
    float inv[16];
    float t[4];
    switch (p[6662]) {
    case 0:
        return func_0058F430(v);
    case 1:
    case 2:
        func_0058FB48(m, (void *)(*(s32 *)(p + 9508) + 240));
        func_0058FDD0(inv, m);
        func_0058F7B8(t, v, inv);
        return func_0058F430(t);
    }
    return 0.0f;
}
