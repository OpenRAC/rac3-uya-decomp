#include "common.h"

/* localdecomp:start func_004A8E50 */
typedef struct { u8 pad0[52]; u16 flags; u8 pad1[98]; s32 x; } Obj_004A8E50;
extern Obj_004A8E50 *D_0016C580[];
extern Obj_004A8E50 *D_0023ACF0[];
void func_004A8E50(void) {
    s32 i;
    if (D_0016C580[0] != 0) {
        D_0016C580[0]->flags |= 3;
        D_0016C580[0]->x = 0;
        for (i = 0; D_0023ACF0[i] != 0; i++) {
            D_0023ACF0[i]->flags |= 3;
            D_0023ACF0[i]->x = 0;
        }
    }
}
/* localdecomp:end func_004A8E50 */
