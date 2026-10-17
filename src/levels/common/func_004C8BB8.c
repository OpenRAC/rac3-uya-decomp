#include "common.h"

extern void func_004C9BE0();

typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[4]; u8 f18; u8 pad3[7]; s32 f20; } S_3A59E8;
extern void func_004C9BE0();
void func_004C8BB8(S_3A59E8 *s, s32 v) {
    if (v == s->f10) return;
    if (s->f20 != 0 && s->f18 == 0) {
        func_004C9BE0(s->f20, s->f10);
        s->f18 = 1;
    }
    s->f10 = v;
}
