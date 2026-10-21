#include "common.h"

/* localdecomp:start func_003C4AD0 */
typedef int u128_t __attribute__((mode(TI)));
extern float func_0040CEC8(float, float);
void func_003C4AD0(u8 *a, float *b) {
    __asm__("sq $0,%0" : "=m"(*(u128_t *)b));
    b[2] = func_0040CEC8(*(float *)(a + 0xF8), 3.1415927f);
}
/* localdecomp:end func_003C4AD0 */
