#include "common.h"

/* localdecomp:start func_003CFF70 */
extern void func_003D04B0(void);
extern void func_003D0950(void);
extern void func_004026A0(void *, s32);

void func_003CFF70(s32 a0, s32 *a1) {
    if (a1[4] >= 0) {
        func_003D04B0();
        func_004026A0(func_003D0950, a0);
    }
}
/* localdecomp:end func_003CFF70 */
