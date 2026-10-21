#include "common.h"

/* localdecomp:start func_0031C5C0 */
extern short *D_0021DEA0[];
extern int D_001E009C;
extern void func_0031C318(void *, int, void *, void *);

void func_0031C5C0(void *a0, void *a1, int a2, void *a3) {
    short *p = D_0021DEA0[a2];

    if (p != 0) {
        do {
            func_0031C318(a0, D_001E009C + ((*p & 0x7FFF) << 8), a1, a3);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_0031C5C0 */
