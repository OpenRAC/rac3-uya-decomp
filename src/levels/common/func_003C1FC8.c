#include "common.h"

/* localdecomp:start func_003C1FC8 */
typedef int Q_3C1FC8 __attribute__((mode(TI)));
extern s32 D_001E22AC[1];
extern s32 D_001DD728[4];
extern s32 D_001E2280[4];
extern Q_3C1FC8 D_001E2240[4];
void func_003C1FC8(void) {
    s32 i, j;
    for (i = 7; i >= 0; i--) {
        D_001E22AC[i - 7] = 0;
    }
    D_001DD728[0] = 0;
    for (j = 0; j < 4; j++) {
        __asm__("sq $0,%0" : "=m"(D_001E2240[j]));
        D_001E2280[j] = 0;
    }
}
/* localdecomp:end func_003C1FC8 */
