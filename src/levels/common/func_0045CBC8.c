#include "common.h"

typedef struct { u8 pad[0x48]; s16 f48, f4A, f4C; u8 pad2[0x46]; s32 f94; s16 f98, f9A, f9C; u8 pad3[0x12]; s32 fB0; } S_1CCFD0b;
extern S_1CCFD0b D_001CCFD0;
extern u8 D_001A30B0[];
extern void func_0045B800(s32, s32, s32, s32 *, s32);
void func_0045CBC8(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    s32 i;
    if (p == 0) return;
    i = *(s32 *)(p + 0x20);
    *(s32 *)p = a;
    if (i >= 0) { u8 *e = D_001A30B0 + (i << 7); *(s32 *)(e + 0xC0) = a; };
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else {
        func_0045B800(D_001CCFD0.f98, D_001CCFD0.f9C, D_001CCFD0.fB0, &D_001CCFD0.f94, D_001CCFD0.f9A);
    }
}
