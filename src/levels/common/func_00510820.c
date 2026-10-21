#include "common.h"

/* localdecomp:start func_00510820 */
void func_00510820(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_00510820 */
