#include "common.h"

/* localdecomp:start func_00474678 */
extern int D_0021F740[];
extern float func_004746C8(int a);

float func_00474678(int a0)
{
    if (a0 != -1) {
        int v = D_0021F740[a0];
        if (v != 0) {
            return func_004746C8(v);
        }
    }
    return -1.0f;
}
/* localdecomp:end func_00474678 */
