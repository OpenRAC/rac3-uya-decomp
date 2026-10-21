#include "common.h"

/* localdecomp:start func_005165F0 */
extern s32 func_005165F0(u8 *p, s32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001DC220_g;

extern s32 D_001DC220_g;
s32 func_005165F0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC220_g)) {
        *(s32 *)(p + 0x50) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_005165F0 */
