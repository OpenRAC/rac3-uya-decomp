#include "common.h"

/* localdecomp:start func_003E08B8 */
typedef int Q_003E08B8 __attribute__((mode(TI)));
extern void func_00446A40(void *, s32, Q_003E08B8 *);
extern void func_003C0218(void *, Q_003E08B8 *, Q_003E08B8 *, s32, s32, s32, s32, f32, f32);

void func_003E08B8(void *o, u8 *b) {
    Q_003E08B8 m[4];
    Q_003E08B8 v[2];
    Q_003E08B8 x, y;
    func_00446A40(o, 1, m);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m[1]));
    __asm__("vsub.xyz %0, $vf0, %1" : "=j"(y) : "j"(x));
    __asm__("sqc2 %1, 0x10+%0" : "=m"(m) : "j"(y));
    v[0] = m[3];
    v[1] = m[1];
    func_003C0218(o, &v[0], &v[1], 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(b + 0x6C), 0.65f);
}
/* localdecomp:end func_003E08B8 */
