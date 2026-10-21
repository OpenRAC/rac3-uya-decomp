#include "common.h"

/* localdecomp:start func_0050F828 */
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

extern s16 D_002C4CA2[];
extern G_0050F828 D_00142660;

extern s32 func_00417EA0(void);

void func_0050F828(s32 *out, s32 *total, s32 *acc) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 191; i++) {
        if ((D_002C4CA2 - 1)[i * 2] < 0) {
            break;
        }
        sum += (D_002C4CA2 - 1)[i * 2];
        if ((D_00142660.x34 >> 5) < sum) {
            break;
        }
        *acc += D_002C4CA2[i * 2];
        *out = sum;
        if (func_00417EA0() == 0 && i >= 90) {
            break;
        }
    }
    *total = sum;
}
/* localdecomp:end func_0050F828 */
