#include "common.h"

/* localdecomp:start func_003E9510 */
typedef int u128_003E9510 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E9510;
extern Slot_003E9510 D_001E2AC0[];
extern u8 *func_003F1368(s32, s32);
void func_003E9510(s32 a0, u128_003E9510 *a1) {
    u8 *o = (&D_001E2AC0[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_003F1368(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E9510 *)(*(u8 **)(r + 112) + 144) = *a1;
}
/* localdecomp:end func_003E9510 */
