#include "common.h"

/* localdecomp:start func_004909F0 */
extern s32 *func_004909F0();

extern s32 D_001E0B84;
extern s32 D_001E0B78;
extern u8 *D_001E0B7C[];
extern u8 D_001D8F38[];
s32 *func_004909F0(void) {
    if (D_001E0B84 == 0) { D_001E0B7C[0] = D_001D8F38; D_001E0B78 = 1; D_001E0B84 = 1; }
    return &D_001E0B78;
}
/* localdecomp:end func_004909F0 */
