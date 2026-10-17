#include "common.h"

extern u32 *D_001E10E8;
extern void func_0041DFF0();
extern s32 D_001DFD8C;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;

extern u32 *D_001E10E8;
extern s32 func_0041D950_00392878();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001DFD8C;
void func_0041DFF0(s32 tex, s32 x, s32 y, s32 w, s32 h, s32 alpha) {
    unsigned long *q;
    D_001E10E8[0] = 0x10000005;
    D_001E10E8[1] = 0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000005;
    q = (unsigned long *)(D_001E10E8 + 4);
    D_001E10E8 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_0041D950_00392878(tex);
    q[3] = 0x156;
    q[4] = ((long)alpha << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0 - 8) | ((long)(y * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[7] = (h << 20) + (w << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0 - 8) | ((long)((y + h) * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[9] = 0;
    D_001E10E8 += 0x14;
}
