#include "common.h"

/* localdecomp:start func_004068C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4068C8;
typedef struct { V_4068C8 r[4]; } M_4068C8;
typedef struct {
    V_4068C8 v[4];
    u32 col[4];
    f32 uv[4][2];
    long tag;
    long f78;
    long f80;
    long f88;
} E_4068C8;
extern s32 D_001D63D4;
extern s32 D_001D63D8;
extern f32 D_001D63E0[2];
extern f32 D_001D63E4[];
extern long func_00401CD0(s32);
extern u32 func_0040D020(s32, s32, f32);
extern void func_0040CBA0(V_4068C8 *, M_4068C8 *);
extern void func_0040C2F8(V_4068C8 *, V_4068C8 *, M_4068C8 *);
extern void func_00405A58(E_4068C8 *, s32, s32);
void func_004068C8(V_4068C8 *pts, s32 n, V_4068C8 *pos, V_4068C8 *rot, s32 start, s32 m, s32 c0, s32 c1, s32 tex, f32 f) {
    E_4068C8 arr[32];
    M_4068C8 mat;
    f32 step, t;
    u32 col, col0;
    s32 i, j, k, u, cur, d;

    if (m < 2) return;
    step = 1.0f / (f32)(m - 1);
    k = 2;
    t = step * f;
    col0 = func_0040D020(c0, c1, step);
    for (i = 0; i < n >> 1; i++) {
        arr[i].f78 = func_00401CD0(tex);
        arr[i].col[1] = col0;
        arr[i].f80 = 0xFF9000000260;
        arr[i].tag = 5;
        arr[i].col[0] = col0;
        arr[i].f88 = ((long)D_001D63D4 << 2) | ((long)D_001D63D8 << 6) | 0x8000000000;
        for (u = 0; u < 4; u++) {
            arr[i].uv[u][0] = D_001D63E0[u * 2];
            arr[i].uv[u][1] = D_001D63E4[u * 2];
        }
    }
    cur = start;
    func_0040CBA0(&rot[cur], &mat);
    mat.r[3] = pos[cur];
    mat.r[3].w = 1.0f;
    for (i = 0; i < n; i++) {
        func_0040C2F8(&arr[i >> 1].v[i & 1], &pts[i], &mat);
    }
    {
    s32 s;
    for (s = 1; s < m; s++) {
        cur = (cur + m - 1) % m;
        func_0040CBA0(&rot[cur], &mat);
        mat.r[3] = pos[cur];
        mat.r[3].w = 1.0f;
        col = func_0040D020(c0, c1, t);
        t += step;
        if (1.0f < t) {
            t = 1.0f;
        }
        for (j = 0; j < n; j++) {
            func_0040C2F8(&arr[j >> 1].v[k + (j & 1)], &pts[j], &mat);
            arr[j >> 1].col[k + (j & 1)] = col;
        }
        k = (k + 2) % 4;
        for (d = 0; d < n >> 1; d++) {
            func_00405A58(&arr[d], 0, 1);
        }
    }
    }
}
/* localdecomp:end func_004068C8 */
