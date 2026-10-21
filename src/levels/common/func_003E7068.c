#include "common.h"

/* localdecomp:start func_003E7068 */
typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Slot;

extern Slot D_001E2AC0[];

void func_003E7068(s32 i, s32 v) {
    Slot *s = &D_001E2AC0[i];
    u8 *o = s->obj;
    if (*(s16 *)(o + 134) == 0) {
        *(s32 *)(*(u8 **)(o + 112) + 600) = v;
    }
}
/* localdecomp:end func_003E7068 */
