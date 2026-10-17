#include "common.h"

typedef struct { u8 pad[0x28]; u8 b; u8 pad2[7]; s32 a; s32 c; s32 d; } S_3A5EF8;
extern void func_004C8C60();
void func_004C90C8(S_3A5EF8 *s, s32 a, s32 b, s32 c, s32 d) {
    func_004C8C60(s, c, d);
    s->a = a;
    s->b = b;
    s->c = 100;
    s->d = 0x80000000;
}
