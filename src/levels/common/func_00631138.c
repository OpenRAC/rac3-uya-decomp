#include "common.h"

/* localdecomp:start func_00631138 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00631138;
extern void func_00631040(void *, V_00631138 *);

void func_00631138(void *p) {
    V_00631138 v;
    __asm__("sq $0, %0" : "=m"(*(u128_t *)&v));
    v.z = 0.6f;
    func_00631040(p, &v);
}
/* localdecomp:end func_00631138 */
