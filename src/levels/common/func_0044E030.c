#include "common.h"

/* localdecomp:start func_0044E030 */
typedef int Q_44E030 __attribute__((mode(TI)));
extern s32 D_001D673C;
extern void func_0044DF40(void *, void *, s32);
void func_0044E030(void *a, Q_44E030 *b) {
    if (D_001D673C == 0) {
        Q_44E030 x;
        __asm__("vmr32.wxyz %0, $vf0" : "=j"(x));
        __asm__("sqc2 %1, %0" : "=m"(*b) : "j"(x));
    } else {
        func_0044DF40(a, b, 1);
    }
}
/* localdecomp:end func_0044E030 */
