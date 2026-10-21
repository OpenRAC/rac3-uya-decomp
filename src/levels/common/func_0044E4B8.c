#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
extern float func_0044E480(void *, void *);
/* localdecomp:start func_0044E4B8 */
float func_0044E4B8(void *a0, u128_t *a1) {
    u128_t t = *a1;
    float r = func_0044E480(a0, &t);
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(r));
    return r;
}
/* localdecomp:end func_0044E4B8 */
