#include "common.h"

extern u32 *D_001E10E8;
extern void func_0041DB78();
extern s32 D_001DFD8C;
typedef struct { s16 a; s16 b; } P_392108;

typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400;
extern P_392108 *D_001DFDA0_00392400;
extern W_392400 *D_001DFDA4_00392400;
extern u32 *D_001E10E8;
extern s32 func_0041D950_00392400();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001DFD8C;
void func_0041DB78(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 col) {
    unsigned long *q;
    P_392108 *p = (P_392108 *)((idx << 2) + (s32)D_001DFDA0_00392400);
    W_392400 *e = &D_001DFDA4_00392400[p->b];
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    D_001E10E8[0] = 0x10000005;
    D_001E10E8[1] = 0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000005;
    q = (unsigned long *)(D_001E10E8 + 4);
    D_001E10E8 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_0041D950_00392400(idx);
    q[3] = 0x156;
    q[4] = ((long)col << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0 - 8) | ((long)(y * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0 - 8) | ((long)((y + h) * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[9] = 0;
    D_001E10E8 += 0x14;
}
