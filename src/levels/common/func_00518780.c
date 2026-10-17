#include "common.h"

extern s32 func_00518780();
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };

typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001DC280_003E7900;
s32 func_00518780(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001DC280_003E7900) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
