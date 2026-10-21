#include "common.h"

/* localdecomp:start func_005175D8 */
extern s32 func_005175D8(u8 *p, f32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001DC250[];
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

extern s32 D_001DC250[];
extern void func_0051C328(void *, f32);
s32 func_005175D8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC250[0])) {
        func_0051C328(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_005175D8 */
