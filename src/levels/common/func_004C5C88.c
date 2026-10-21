#include "common.h"

/* localdecomp:start func_004C5C88 */
extern void func_00435F98(void *);
extern void func_0040BBA8(void *, s32, s32);
extern void func_00439610(void *);

void func_004C5C88(u8 *a0) {
    void *p = *(void **)(a0 + 104);
    func_00435F98(a0);
    *(void **)(a0 + 104) = p;
    func_0040BBA8(p, 0, 128);
    if (!(*(u16 *)(a0 + 52) & 4)) {
        func_00439610(a0);
    }
}
/* localdecomp:end func_004C5C88 */
