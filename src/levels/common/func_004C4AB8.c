#include "common.h"

/* localdecomp:start func_004C4AB8 */
typedef struct { u8 pad[0x1C]; s32 x; } S4C4;
extern S4C4 D_00250180[];
void func_004C4AB8(s32 i) {
    S4C4 *p;
    if (i >= 0) {
        p = &D_00250180[i];
        p->x = 0;
    }
}
/* localdecomp:end func_004C4AB8 */
