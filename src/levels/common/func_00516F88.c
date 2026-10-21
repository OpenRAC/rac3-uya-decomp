#include "common.h"

/* localdecomp:start func_00516F88 */
extern s32 func_00516F88(u8 *p, s32 a, s16 b, s16 c, s32 d);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC250_003E6108;
extern void func_0051C340(void *, s32, s16, s16, s32);
s32 func_00516F88(u8 *p, s32 a, s16 b, s16 c, s32 d) {
    if ((*(VT_3E6108 **)(p + 8))->isA(p, D_001DC250_003E6108)) {
        func_0051C340(p, a, b, c, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00516F88 */
