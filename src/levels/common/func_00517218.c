#include "common.h"

/* localdecomp:start func_00517218 */
extern s32 func_00517218(u8 *p, s32 a, u8 *out);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 func_00519410();
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC250_g;

extern s32 D_001DC250_g;
extern s32 func_00519410();
s32 func_00517218(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC250_g)) {
        *out = func_00519410(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00517218 */
