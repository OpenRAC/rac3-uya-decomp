#include "common.h"

/* localdecomp:start func_0047A608 */
typedef struct {
    s32 pad[3];
    s32 a[4];
} S_47A608;
extern S_47A608 D_002E9FD8;
extern void func_0040BBA8(s32, s32, s32);
void func_0047A608(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0040BBA8(D_002E9FD8.a[i], 0, 2048);
    }
}
/* localdecomp:end func_0047A608 */
