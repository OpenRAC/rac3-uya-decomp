#include "common.h"

/* localdecomp:start func_003A31F0 */
extern s32 D_001DE300;
extern s32 D_001DE320;
s32 *func_003A31F0(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 5:
        *a2 = 12;
        return &D_001DE320;
    case 1:
        *a2 = 28;
        return &D_001DE300;
    }
    return 0;
}
/* localdecomp:end func_003A31F0 */
