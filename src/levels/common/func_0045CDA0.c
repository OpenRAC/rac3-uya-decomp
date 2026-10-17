#include "common.h"

extern void func_0045CDA0(s32, long);

void func_0045CDA0(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    if (*(u32 *)p == 0xFFFFFFFF) {
        *(s32 *)p = a;
        if (a == 0) *(s16 *)(p + 0xA) = 7;
    }
}
