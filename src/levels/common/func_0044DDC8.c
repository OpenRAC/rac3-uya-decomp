#include "common.h"

/* localdecomp:start func_0044DDC8 */
extern void func_0044DC18(void *, void *, f32);
extern void func_0040C140(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);

void func_0044DDC8(u8 *a0, void *a1, f32 f) {
    func_0044DC18(a0, a1, f);
    func_0040C140(a1, a1, f);
    func_0040C2D0(a1, a1, a0 + 192);
}
/* localdecomp:end func_0044DDC8 */
