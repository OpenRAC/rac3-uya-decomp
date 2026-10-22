#include "common.h"

/* localdecomp:start func_00663378 */
extern void func_00635C10(u8 *);

void func_00663378(u8 *p) {
    func_00635C10(p);
    p[0x4D23] = 0;
    __asm__ __volatile__("sq $0, 0x4D50(%0)" : : "r"(p));
    p[0x4D21] = 0;
}
/* localdecomp:end func_00663378 */
