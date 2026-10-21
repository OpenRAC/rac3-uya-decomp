#include "common.h"

/* localdecomp:start func_00516E58 */
extern s32 func_00516E58(u8 *p, f32 a, f32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;

extern s32 D_001DC250[];
extern void func_00519480(void *, f32, f32);
s32 func_00516E58(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC250[0])) {
        func_00519480(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00516E58 */
