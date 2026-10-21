#include "common.h"
extern float D_001A4BE0[];
extern void func_004450C0(float, float *, float);
/* localdecomp:start func_004EB350 */
void func_004EB350(float x, float y) {
    if (D_001A4BE0[109] < D_001A4BE0[108]) {
        func_004450C0(D_001A4BE0[108], &D_001A4BE0[109], x);
    } else {
        func_004450C0(D_001A4BE0[108], &D_001A4BE0[109], y);
    }
}
/* localdecomp:end func_004EB350 */
