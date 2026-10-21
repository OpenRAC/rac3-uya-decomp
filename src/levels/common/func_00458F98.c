#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00458650(u8 *);
extern float func_0040C490(float, float);
extern float func_00436500(u8 *);
extern void func_00458A08(u8 *, float);
extern void func_00457728(u8 *, u8 *);
extern int func_00443080(float *, float *, float, float, float);
extern void func_00457708(u8 *, float);
extern int D_001DFBC0;

#define F(p, o) (*(float *)((p) + (o)))
#define I(p, o) (*(int *)((p) + (o)))

/* localdecomp:start func_00458F98 */
int func_00458F98(u8 *m, float a, float b, float c)
{
    u8 *t;
    float ang;
    float d;
    float out[2];
    float h;
    float k;
    int n;

    t = func_00458650(m);
    if (t == 0) {
        return 0;
    }
    ang = func_0040C490(F(t, 0xA0), F(t, 0xA4));
    d = func_00436500(m);
    if (m[0x42] == m[0x43] && a <= d && d <= c) {
        if (!(I(t, 0x38) & 0x10)) {
            func_00458A08(m, ang);
        }
        F(t, 0xA8) -= F(t, 0x2C);
        func_00457728(m, t + 0xA0);
        if (0.0f < F(t, 0xA8)) {
            F(m, 0x48) = ((b - d) + (b - d)) / (F(t, 0xA8) / F(t, 0x2C));
        } else if (F(m, 0x18) > F(t, 0x90)) {
            h = F(t, 0x2C) * -0.5f;
            n = func_00443080(&out[0], &out[1], h, F(t, 0xA8) - h, F(m, 0x18) - F(t, 0x90));
            k = 600.0f;
            if (n > 0 && 0.0f < out[0] && out[0] < 60.0f) {
                k = out[0];
            }
            F(m, 0x48) = ((c - d) + (c - d)) / k;
        } else {
            F(m, 0x18) = F(t, 0x90);
            F(m, 0x48) = 1.0f;
        }
        if (5.0f < F(m, 0x48)) {
            F(m, 0x48) = 5.0f;
        } else if (F(m, 0x48) < 0.0f) {
            F(m, 0x48) = 0.0f;
        }
    } else if (a <= 0.0f || a < d) {
        func_00457708(m, ang);
        F(m, 0x48) = 1.0f;
    }
    I(t, 0xBC) = D_001DFBC0;
    if (m[0x60] & 2) {
        __asm__("sq $0,%0" : "=m"(*(u128_t *)(t + 0xA0)));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00458F98 */
