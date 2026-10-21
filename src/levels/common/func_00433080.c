#include "common.h"

/* localdecomp:start func_00433080 */
typedef struct { s32 a; s32 b; } S_433080e;
typedef struct { u8 pad[0x24E10]; S_433080e arr[3]; } S_433080;
extern S_433080 *D_001D67C8;

void func_00433080(u32 i) {
    if (i < 3) {
        D_001D67C8->arr[i].a = 0;
        D_001D67C8->arr[i].b = 0;
    }
}
/* localdecomp:end func_00433080 */
