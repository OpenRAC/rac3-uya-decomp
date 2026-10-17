#include "common.h"

extern void func_0045CC48(s32, long);
typedef struct { u8 pad[0x48]; s16 f48, f4A, f4C; u8 pad2[0x46]; s32 f94; s16 f98, f9A, f9C; u8 pad3[0x12]; s32 fB0; } S_1CCFD0b;
extern S_1CCFD0b D_001CCFD0;

extern s32 D_001D7DF0;
extern void func_0045BA68(s32, s32, s32);
void func_0045CC48(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else if (D_001D7DF0 == 0) {
        func_0045BA68(D_001CCFD0.f48, D_001CCFD0.f4C, D_001CCFD0.f4A);
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
