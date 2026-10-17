#include "common.h"
typedef void (*Fn_6600D8)(void *, void *);
extern u8 *func_0061AA60(s32 a0);
void func_006600D8(u8 *a0) {
    u8 *o = func_0061AA60(*(s32 *)(a0 + 8));
    a0[84] = 0;
    if (o) {
        (*(Fn_6600D8 *)(*(u8 **)(o + 20) + 20))(o, a0);
    }
}
