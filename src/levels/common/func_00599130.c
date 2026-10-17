#include "common.h"
typedef struct {
    s32 v;
    s32 x;
} S_599130;
typedef struct {
    u8 pad0[8];
    S_599130 e[10];
    s32 end;
    s32 cur;
} S_599130b;
extern s32 D_001A4CD0[];
void func_00599130(S_599130b *a0) {
    s32 i = a0->cur;
    while (i != a0->end) {
        s32 v = a0->e[i].v;
        if (v >= 0) {
            D_001A4CD0[(u32)v >> 2] |= 1 << (v & 31);
        }
        i = (i + 1 != 10) ? i + 1 : 0;
    }
}
