#include "common.h"

typedef struct { u32 w[4]; } Q_403E40;

extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern Q_403E40 *D_001E10E8;

/* localdecomp:start func_00403E40 */
int func_00403E40(float x, float y, float w, float h, int u, int v, int tw, int th, u32 *col, unsigned long tex0) {
    int x0;
    int x1;
    int y0;
    int y1;
    unsigned long *q;
    int u1;
    int v1;
    int uv0, uv1, uv2, uv3;

    x0 = (int)(x * 16.0f) + D_001D4BD0 - 8;
    x1 = (int)((x + w) * 16.0f) + D_001D4BD0 - 9;
    y0 = (int)(y * 16.0f) + D_001D4BD4 - 8;
    y1 = (int)((y + h) * 16.0f) + D_001D4BD4 - 9;

    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) {
        return 0;
    }

    u1 = u + tw;
    v1 = v + th;
    uv0 = (v << 20) + (u << 4);
    uv1 = (v << 20) + (u1 << 4);
    uv2 = (v1 << 20) + (u << 4);
    uv3 = (v1 << 20) + (u1 << 4);

    ((u32 *)D_001E10E8)[0] = 0x10000009;
    ((u32 *)D_001E10E8)[1] = 0;
    ((u32 *)D_001E10E8)[2] = 0;
    ((u32 *)D_001E10E8)[3] = 0x50000009;
    D_001E10E8++;
    ((unsigned long *)D_001E10E8)[0] = 0x0400000000008001UL;
    ((unsigned long *)D_001E10E8)[1] = 0x8531531531531068UL;
    D_001E10E8++;
    q = (unsigned long *)D_001E10E8;
    q[0] = 2 | (2 << 2) | ((unsigned long)u << 4) | ((unsigned long)(u1 - 1) << 14) | ((unsigned long)v << 24) | ((unsigned long)(v1 - 1) << 34);
    q[1] = tex0;
    q[2] = 348;
    q[3] = col[0];
    q[4] = uv0;
    q[5] = (unsigned long)x0 | ((unsigned long)y0 << 16) | 0xFFFFF000000000UL;
    q[6] = col[1];
    q[7] = uv1;
    q[8] = (unsigned long)x1 | ((unsigned long)y0 << 16) | 0xFFFFF000000000UL;
    q[9] = col[2];
    q[10] = uv2;
    q[11] = (unsigned long)x0 | ((unsigned long)y1 << 16) | 0xFFFFF000000000UL;
    q[12] = col[3];
    q[13] = uv3;
    q[14] = (unsigned long)x1 | ((unsigned long)y1 << 16) | 0xFFFFF000000000UL;
    q[15] = 5;
    D_001E10E8 += 8;
    return 1;
}
/* localdecomp:end func_00403E40 */
