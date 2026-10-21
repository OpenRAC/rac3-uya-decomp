#include "common.h"

/* localdecomp:start func_003E70A0 */
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E70A0; extern Slot_003E70A0 D_001E2AC0[];
void func_003E70A0(s32 a0, f32 x, f32 y, f32 z) {
    u8 *o = (&D_001E2AC0[a0])->o;
    if (*(s16 *)(o + 134) == 0) {
        u8 *q = *(u8 **)(o + 112) + 528;
        if (x != -1.0f) *(f32 *)(q + 60) = x;
        if (y != -1.0f) *(f32 *)(q + 64) = y;
        if (z != -1.0f) *(f32 *)(q + 68) = z;
    }
}
/* localdecomp:end func_003E70A0 */
