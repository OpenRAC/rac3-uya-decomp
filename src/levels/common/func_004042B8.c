#include "common.h"

extern s32 D_001E10E8;

extern s32 D_001D4BD0_00387118, D_001D4BD4_00387118;
extern s32 D_001E10E8;
s32 func_004042B8(s32 u, s32 v, s32 w, s32 h, long *c, long t1, s32 flag, f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_00387118 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_00387118 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_00387118 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_00387118 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;
    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) return 0;
    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }
    p = (long *)D_001E10E8;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14 | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = c[0];
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = c[1];
    p[7] = (v << 20) + uw4;
    p[8] = (long)x1 | (long)y0 << 16;
    p[9] = c[2];
    p[10] = (v1 << 20) + u4;
    p[11] = (long)x0 | (long)y1 << 16;
    p[12] = c[3];
    p[13] = (v1 << 20) + uw4;
    p[14] = (long)x1 | (long)y1 << 16;
    p[15] = 0;
    D_001E10E8 += 0x80;
    return 1;
}
