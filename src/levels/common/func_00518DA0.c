#include "common.h"

/* localdecomp:start func_00518DA0 */
extern s32 func_00518DA0();
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;

typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001DC190_003E7F20[];
extern void func_005197F0();
s32 func_00518DA0(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001DC190_003E7F20[0]) == 0) return 0;
    func_005197F0(s);
    return 1;
}
/* localdecomp:end func_00518DA0 */
