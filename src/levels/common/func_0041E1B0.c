#include "common.h"

/* localdecomp:start func_0041E1B0 */
typedef struct {
    s16 h0;
    s16 h2;
} E_41E1B0;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
} T_41E1B0;

extern E_41E1B0 *D_001DFDA0;
extern T_41E1B0 *D_001DFDA4;
extern s32 D_001E10E8;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001DFD8C;
extern long func_0041D950(int);

void func_0041E1B0(int idx, int x, int y, int w, int h, int a, unsigned int col) {
    T_41E1B0 *t = &D_001DFDA4[D_001DFDA0[idx].h2];
    int tw = 1 << t->b6;
    int th = 1 << t->b7;
    u8 *p;

    *(s32 *)(D_001E10E8 + 0) = 0x10000005;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000005;
    p = (u8 *)D_001E10E8 + 0x10;
    D_001E10E8 = (s32)p;
    *(long *)(p + 0) = 0x7400000000008001UL;
    *(long *)(p + 8) = 0x5353106;
    *(long *)(p + 0x10) = func_0041D950(idx);
    *(long *)(p + 0x18) = 342;
    *(long *)(p + 0x20) = (long)(u8)col | (long)(col & 0xFF00) | ((long)(u8)(col >> 16) << 16) | ((long)a << 24);
    *(long *)(p + 0x28) = 0;
    *(long *)(p + 0x30) = (x + D_001D4BD0 - 8) | ((long)(y + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    *(long *)(p + 0x38) = (th << 20) + (tw << 4);
    *(long *)(p + 0x40) = (x + w + D_001D4BD0 - 8) | ((long)(y + h + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    *(long *)(p + 0x48) = 0;
    D_001E10E8 = D_001E10E8 + 0x50;
}
/* localdecomp:end func_0041E1B0 */
