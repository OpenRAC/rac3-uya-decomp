#include "common.h"

/* localdecomp:start func_004A7680 */
typedef struct { s32 id; s32 val; } E_4A7680;
extern E_4A7680 D_002F7800[];
typedef struct { s16 id; s16 idx; s32 val; } O_4A7680;
void func_004A7680(O_4A7680 *a0) {
    s32 i;
    for (i = 0; D_002F7800[i].id != -1 && D_002F7800[i].id != a0->id; i++) {
    }
    a0->idx = i;
    a0->val = D_002F7800[i].val;
}
/* localdecomp:end func_004A7680 */
