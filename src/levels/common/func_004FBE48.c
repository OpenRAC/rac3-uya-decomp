#include "common.h"

/* localdecomp:start func_004FBE48 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 p0[16];
    s128 pos;
    u8 p20[17];
    u8 b49;
    u8 p50;
    u16 h52;
    u8 p54[116];
    s16 h170;
} M_4FBE48;

typedef struct {
    u8 p0[128];
    s128 v128;
    u8 p90[8];
    float f152;
    u8 p9C[1360];
    float f1516;
    u8 p5F0[1184];
    M_4FBE48 *f2704;
    s32 f2708;
    u8 pA98[6964];
    s32 f9676;
} G_4FBE48;

typedef struct {
    u8 p0[9540];
    s32 f9540;
} H_4FBE48;

extern G_4FBE48 D_001A4BE0;
extern H_4FBE48 D_001A4C60;
extern M_4FBE48 *D_001F0468[];
extern s32 func_00452F60(M_4FBE48 *);
extern float func_0040BFB0(void *, void *);
extern float func_0040BFE8(void *, void *);
extern float func_004E56A8(float, float, float, float, M_4FBE48 *, s32 *);
extern s32 func_003F8448(void *, void *, s32, s32, s32);

s32 func_004FBE48(void) {
    M_4FBE48 *best;
    M_4FBE48 *m;
    s32 i;
    float bestDist, d, a, c, e;
    s32 out;
    s128 v[2];

    if (D_001A4BE0.f9676 == 33) return D_001A4BE0.f2708;
    D_001A4BE0.f2708 = 0;
    best = 0;
    bestDist = 100000000.0f;
    for (i = 0; i < 32; i++) {
        m = D_001F0468[i];
        if (m == 0) break;
        if (m->h170 != 2461) continue;
        if (m->h52 & 1) continue;
        if (func_00452F60(m)) continue;
        if (func_0040BFB0(&D_001A4C60, &m->pos) > 30.0f) continue;
        c = 0.52359879f;
        e = -1.0f;
        if (D_001A4C60.f9540 == 1 || D_001A4C60.f9540 == 29) {
            c = e = 0.08726646f;
        }
        a = D_001A4BE0.f152;
        if (D_001A4BE0.f9676 == 15) a = D_001A4BE0.f1516;
        d = func_004E56A8(a, 30.0f, c, e, m, &out);
        if (out != 0) continue;
        if (func_0040BFE8(&D_001A4BE0.v128, &m->pos) < 4.0f) continue;
        if (m->b49 == 0) d += 10.0f;
        if (d < bestDist) {
            bestDist = d;
            best = m;
        }
    }
    if (best) {
        v[0] = D_001A4BE0.v128;
        D_001A4BE0.f2704 = best;
        ((float *)&v[0])[2] += 0.5f;
        v[1] = best->pos;
        if (func_003F8448(&v[0], &v[1], 2, 0, 0) == 0) D_001A4BE0.f2708 = 1;
    }
    return D_001A4BE0.f2708;
}
/* localdecomp:end func_004FBE48 */
