#include "common.h"

/* localdecomp:start func_003D16B8 */
extern void func_003D1068(void *, void *);
extern void func_003D1188(void *, void *);
extern void func_003D1598(void *, void *);

void func_003D16B8(void *a0, u8 *a1) {
    if (*(s32 *)(a1 + 52) != 0) {
        func_003D1068(a0, a1);
        func_003D1188(a0, a1);
        func_003D1598(a0, a1);
    }
}
/* localdecomp:end func_003D16B8 */
