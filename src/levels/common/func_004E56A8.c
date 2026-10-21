#include "common.h"

/* localdecomp:start func_004E56A8 */
typedef struct S_4E56A8vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_4E56A8vec __attribute__((aligned(16)));
typedef struct S_4E56A8c {
    u8 pad0[0x46];
    u8 x46;
} S_4E56A8c;
typedef struct S_4E56A8m {
    u8 pad0[0x10];
    S_4E56A8vec x10;
    u8 pad20[4];
    S_4E56A8c *x24;
} S_4E56A8m;
typedef struct S_4E56A8g {
    u8 pad0[0x80];
    S_4E56A8vec x80;
    u8 pad90[0x2A8];
    f32 x338;
    u8 pad33c[0x2288];
    s32 x25C4;
} S_4E56A8g;
typedef struct S_4E56A8q {
    S_4E56A8vec x0;
    f32 x10;
    f32 x14;
    f32 x18;
} S_4E56A8q;
extern S_4E56A8vec D_001A4C60;
extern S_4E56A8q D_001E2AC0;
extern f32 func_0040BFB0(S_4E56A8vec *a, S_4E56A8vec *b);
extern f32 func_0040BFE8(S_4E56A8vec *a, S_4E56A8vec *b);
extern f32 func_0040C490(f32 a, f32 b);
extern f32 func_0040CFB0(f32 a, f32 b);
extern s32 func_00447CA0(S_4E56A8m *m);
f32 func_004E56A8(S_4E56A8m *m, s32 *out, f32 a, f32 b, f32 c, f32 d) {
    S_4E56A8g *g;
    S_4E56A8vec p;
    f32 dist;
    f32 yaw;
    f32 lim;
    f32 pitch;
    f32 t;
    f32 res;

    *out = 0;
    p = D_001A4C60;
    g = (S_4E56A8g *)((u8 *)&D_001A4C60 - 0x80);
    if (g->x25C4 == 20) {
        p.z = g->x338;
    }
    dist = func_0040BFB0(&p, &m->x10);
    if (b < dist) {
        *out = 1;
    }
    yaw = func_0040CFB0(func_0040C490(m->x10.x - p.x, m->x10.y - p.y), a);
    lim = yaw;
    pitch = func_0040CFB0(func_0040C490(func_0040BFE8(&p, &m->x10), m->x10.z - p.z), 0.0f);
    if (g->x25C4 == 1 || g->x25C4 == 29) {
        t = func_0040CFB0(func_0040C490(m->x10.x - D_001E2AC0.x0.x, m->x10.y - D_001E2AC0.x0.y), D_001E2AC0.x18);
        pitch = func_0040CFB0(func_0040C490(func_0040BFE8(&D_001E2AC0.x0, &m->x10), m->x10.z - D_001E2AC0.x0.z), -D_001E2AC0.x14);
        lim = pitch;
        yaw = t + pitch;
        if (pitch < t) {
            lim = t;
        }
    }
    if (0.0f < c && c < lim) {
        *out = 1;
    }
    if (0.0f < d && d < pitch) {
        *out = 1;
    }
    res = dist + yaw * dist;
    if (func_00447CA0(m) != 0) {
        res += b * 0.8f;
    } else if (m != 0 && m->x24 != 0 && m->x24->x46 == 22) {
        res += b * 0.8f;
    }
    return res;
}
/* localdecomp:end func_004E56A8 */
