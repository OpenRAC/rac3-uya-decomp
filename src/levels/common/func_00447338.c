#include "common.h"

typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D7BE8;
void func_00447338(void *qv, void *mv) {
    f32 *q = (f32 *)qv;
    f32 *m = (f32 *)mv;
    N3_3BF058 nxt;
    f32 mm[3][3];
    f32 tr, s;
    s32 i, j, k;
    nxt = D_001D7BE8;
    tr = m[0] + m[5] + m[10];
    if (tr > 0.0f) {
        __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(tr + 1.0f));
        q[3] = s * 0.5f;
        s = 0.5f / s;
        q[0] = (m[9] - m[6]) * s;
        q[1] = (m[2] - m[8]) * s;
        q[2] = (m[4] - m[1]) * s;
    } else {
        mm[0][1] = m[1];
        mm[0][2] = m[2];
        mm[1][0] = m[4];
        mm[1][2] = m[6];
        mm[2][0] = m[8];
        mm[2][1] = m[9];
        mm[0][0] = m[0];
        mm[1][1] = m[5];
        mm[2][2] = m[10];
        i = 0;
        if (mm[0][0] < mm[1][1]) i = 1;
        if (mm[i][i] < mm[2][2]) i = 2;
        j = nxt.v[i];
        k = nxt.v[j];
        __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(mm[i][i] - (mm[j][j] + mm[k][k]) + 1.0f));
        q[i] = s * 0.5f;
        if (s != 0.0f) s = 0.5f / s;
        q[3] = (mm[k][j] - mm[j][k]) * s;
        q[j] = (mm[j][i] + mm[i][j]) * s;
        q[k] = (mm[k][i] + mm[i][k]) * s;
    }
}
