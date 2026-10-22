#include "common.h"

/* localdecomp:start func_00660240 */
extern void func_0058F1B0(void *, void *, s32);

void func_00660240(u8 *p, void *out, s32 n) {
    func_0058F1B0(out, &p[p[0x54] + 0xC], n);
    p[0x54] += n;
}
/* localdecomp:end func_00660240 */
