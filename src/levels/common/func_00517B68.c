#include "common.h"

extern s32 func_00517B68();
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;

typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001DC1F0_003E6CE8;
extern void func_0051AAD0();
s32 func_00517B68(S_3E6CE8 *p, s32 b) {
    s32 r;
    if (!p->vt->fn(p, D_001DC1F0_003E6CE8)) r = 0; else {
        func_0051AAD0(p, b);
        p->h4A = 0;
        r = 1;
    }
    return r;
}
