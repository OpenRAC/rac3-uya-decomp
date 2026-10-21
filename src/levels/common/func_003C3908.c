#include "common.h"

typedef int Q_3C3908 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C3908;
extern void func_00439610(u8 *a);
extern void func_00449988(u8 *a, void *b, u8 *c, u8 *d);

/* localdecomp:start func_003C3908 */
void func_003C3908(s32 a0, u8 *a1) {
    V_3C3908 v;
    Q_3C3908 x, y;
    u8 *p;
    u8 *q;
    s32 i = 4;
    u8 **pp = (u8 **)(a1 + 0x40);
    do {
        p = *pp;
        i--;
        pp++;
        if (p != 0) {
            q = *(u8 **)(p + 0x68);
            func_00439610(p);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_3C3908 *)(p + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3C3908 *)(q + 0x70)));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
            func_00449988(q + 0x30, &v, q + 0x80, p + 0xF0);
            *(Q_3C3908 *)(q + 0x70) = *(Q_3C3908 *)(p + 0x10);
            *(Q_3C3908 *)(q + 0x80) = *(Q_3C3908 *)(p + 0xF0);
        }
    } while (i >= 0);
}
/* localdecomp:end func_003C3908 */
