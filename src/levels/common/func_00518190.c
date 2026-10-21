#include "common.h"

/* localdecomp:start func_00518190 */
extern s32 func_00518190(u8 *p, s32 a, s32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern void func_00519490();
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC1C0_g;

extern s32 D_001DC1C0_g;
extern void func_00519490();
s32 func_00518190(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC1C0_g)) {
        func_00519490(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00518190 */
