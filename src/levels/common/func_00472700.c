#include "common.h"

/* localdecomp:start func_00472700 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_472700;
typedef struct {
    u8 pad0[12];
    f32 f0C;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    u8 b1C;
    u8 b1D;
} Q_472700;
typedef struct {
    u8 b0, b1, b2, b3;
    u8 pad4[4];
    u8 b8, b9;
    s16 h0A;
    f32 f0C;
    V4_472700 v10;
    Q_472700 q;
} P_472700;
extern u8 *D_00221318[];
extern P_472700 *func_0045E438(s32);
extern s32 func_00440878(s32, s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
P_472700 *func_00472700(V4_472700 *a, V4_472700 *b, s32 c, u8 d, f32 e, f32 f) {
    P_472700 *p;
    Q_472700 *q;
    s32 r;
    p = func_0045E438(0x80);
    if (p != 0) {
        p->b1 = 0;
        p->b9 = 0x42;
        p->b3 = 0x48;
        q = &p->q;
        r = func_00440878(0, 3);
        if (r == 0) {
            p->b2 = D_00221318[0][0];
        } else if (r == 1) {
            p->b2 = D_00221318[0][1];
        } else if (r >= 2) {
            p->b2 = D_00221318[0][2];
        }
        p->f0C = e * 210000.0f;
        p->b8 = func_00440848(0xFF);
        p->h0A = func_00440878(100, 120);
        q->b1C = 0;
        q->f10 = 1.0f / (f32)p->h0A;
        q->f14 = f;
        q->b1D = d;
        p->v10 = *a;
        *(V4_472700 *)q = *b;
        q->f0C = func_004408C0(1.6f, 6.0f) * 0.00027777778f;
    }
    return p;
}
/* localdecomp:end func_00472700 */
