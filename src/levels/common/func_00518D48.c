#include "common.h"

extern s32 func_00518D48();

typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001DC190_003E7EC8;
extern s32 func_005196B8(S_3E7EC8 *a, s32 b);
s32 func_00518D48(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001DC190_003E7EC8)) return func_005196B8(a, b);
    return 0;
}
