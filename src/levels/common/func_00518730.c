#include "common.h"

/* localdecomp:start func_00518730 */
extern s32 func_00518730(u8 *p, s32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC280_g;

extern s32 D_001DC280_g;
s32 func_00518730(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC280_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00518730 */
