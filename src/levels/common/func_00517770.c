#include "common.h"

/* localdecomp:start func_00517770 */
extern s32 func_00517770(u8 *p, f32 a, f32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001DC250[];
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern void func_0051C3B8(u8 *, s32, f32, f32);

extern s32 D_001DC250[];
extern void func_0051C3B8(u8 *, s32, f32, f32);
s32 func_00517770(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC250[0])) {
        func_0051C3B8(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00517770 */
