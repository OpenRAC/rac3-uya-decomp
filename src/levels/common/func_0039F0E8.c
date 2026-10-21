#include "common.h"

/* localdecomp:start func_0039F0E8 */
extern s32 D_001DE2B8;
extern s32 D_001DE2D8;
extern s32 D_001DE2E8;
void *func_0039F0E8(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 5:
        *a2 = 12;
        return &D_001DE2E8;
    case 1:
        *a2 = 28;
        return &D_001DE2B8;
    case 2:
        *a2 = 12;
        return &D_001DE2D8;
    }
    return 0;
}
/* localdecomp:end func_0039F0E8 */
