#include "common.h"
extern u8 *D_001DFD90[];
extern u8 *D_001DFD90_0041A098[];
extern u8 *D_001DFD90_0041A098_b[];
extern u8 *D_001DFD94[];
extern void func_0041A068(void);
void *func_0041A098(u32 n) {
    u8 *r;
    if (D_001DFD90_0041A098_b[0] == 0) {
        func_0041A068();
    }
    if ((s32)(D_001DFD94[0] - D_001DFD90_0041A098[0]) < (s32)n) {
        return 0;
    }
    r = D_001DFD90_0041A098[0];
    n = (n + 15) & 0xFFFFFFF0;
    D_001DFD90[0] = r + n;
    return r;
}
