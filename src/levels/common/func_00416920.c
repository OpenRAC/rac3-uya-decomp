#include "common.h"

/* localdecomp:start func_00416920 */
typedef struct {
    u8 pad[6];
    s16 f6;
    u8 pad8[2];
} S_00416920;
extern S_00416920 D_002E9F78[];
s32 func_00416920(s32 id) {
    s32 i;
    for (i = 0; D_002E9F78[i].f6 != -1; i++) {
        if (id == D_002E9F78[i].f6) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_00416920 */
