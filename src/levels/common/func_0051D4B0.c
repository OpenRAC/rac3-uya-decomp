#include "common.h"

typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;

s32 func_0051D4B0(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
