#include "common.h"

/* localdecomp:start func_00303E00 */
typedef int Q_303E00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_303E00;
typedef struct {
    Q_303E00 v0;
    s32 w10;
    s32 w14;
    f32 f18;
    u16 h1C;
    u16 h1E;
} Q_303E00_t;
typedef struct {
    u8 pad0[0x10];
    Q_303E00 v10;
    u8 b20;
    u8 pad21[2];
    u8 b23;
    u8 pad24[8];
    f32 f2C;
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[0x68 - 0x34];
    Q_303E00_t *q;
    u8 pad6c[0xF0 - 0x6C];
    Q_303E00 vF0;
} R_303E00;
extern R_303E00 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00438908(R_303E00 *, u8, u8, u8);
extern void func_00439610(R_303E00 *);

R_303E00 *func_00303E00(s32 a0, Q_303E00 *a1, Q_303E00 *a2, s32 a3, u8 a4, u8 a5, u8 a6, u8 a7, f32 scale) {
    R_303E00 *r;
    Q_303E00_t *q;
    V4_303E00 u __attribute__((aligned(16)));
    V4_303E00 t __attribute__((aligned(16)));
    r = func_00435E70(0x4A8, 0x80);
    if (r != 0) {
        q = r->q;
        *(Q_303E00 *)&t = 0;
        t.x = func_004408C0(-3.1415927f, 3.1415927f);
        t.y = func_004408C0(-3.1415927f, 3.1415927f);
        t.z = func_004408C0(-3.1415927f, 3.1415927f);
        *(Q_303E00 *)&u = *(Q_303E00 *)&t;
        r->b20 = 0;
        r->b23 = a7;
        r->b30 = 0xFF;
        r->h32 = 0xFF;
        r->b31 = 1;
        func_00438908(r, a4, a5, a6);
        q->f18 = r->f2C * scale;
        r->f2C = 0;
        q->w10 = a0;
        r->v10 = *a1;
        q->v0 = *a2;
        r->vF0 = *(Q_303E00 *)&u;
        q->h1E = a7;
        q->w14 = a3;
        q->h1C = q->w14;
        func_00439610(r);
    }
    return r;
}
/* localdecomp:end func_00303E00 */
