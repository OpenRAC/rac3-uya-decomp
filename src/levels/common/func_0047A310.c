#include "common.h"

/* localdecomp:start func_0047A310 */
typedef struct {
    u8 pad0[0x50];
    s32 x50[1];
} D_002E9FD8_t;
extern D_002E9FD8_t D_002E9FD8;

s32 func_0047A310(s32 i) {
    return D_002E9FD8.x50[i];
}
/* localdecomp:end func_0047A310 */
