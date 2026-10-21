#include "common.h"

/* localdecomp:start func_003EAB30 */
extern u8 *D_001DF884[];

void func_003EAB30(s32 i) {
    u8 *q = *(u8 **)(D_001DF884[0] + i * 32 + 28);
    q[56] = 1;
    q[57] = 0;
}
/* localdecomp:end func_003EAB30 */
