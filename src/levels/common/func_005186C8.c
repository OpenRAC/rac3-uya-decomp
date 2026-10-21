#include "common.h"

/* localdecomp:start func_005186C8 */
extern s32 func_005186C8(u8 *p, f32 a, f32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001DC280[];

extern s32 D_001DC280[];
s32 func_005186C8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC280[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_005186C8 */
