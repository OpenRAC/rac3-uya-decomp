#include "common.h"

/* localdecomp:start func_003F38D0 */
typedef struct {
    s32 f0;
    u8 pad[16];
} S_003F38D0;
extern S_003F38D0 D_002F7700[];
s32 func_003F38D0(s32 id) {
    s32 i;
    for (i = 0; D_002F7700[i].f0 != -1 && D_002F7700[i].f0 != id; i++) {
    }
    return i;
}
/* localdecomp:end func_003F38D0 */
