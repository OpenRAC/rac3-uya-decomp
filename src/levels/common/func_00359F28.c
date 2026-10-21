#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 m[36];
} Sub;

typedef struct {
    u128_t q0;
    u128_t q1;
    f32 pos[2][4];
    u8 pad40[0x20];
    Sub a[2];
    Sub x[2];
    Sub b[2];
    Sub y[2];
    s32 c[2];
    s32 pad4E8[2];
    f32 d[2];
    f32 pad4F8[2];
    f32 e[2];
    f32 pad508[2];
    s32 f510;
    s32 active;
    s32 f518;
    s32 f51C;
    u8 pad520[0x10];
} Ent;

extern Ent D_00284580[];
extern void func_00359EB8(Sub *p);
extern f32 func_004408C0(f32 lo, f32 hi);
extern s32 func_0013D3E0(void);

/* localdecomp:start func_00359F28 */
void func_00359F28(s32 unused, f32 *pos, u128_t *qa, u128_t *qb)
{
    s32 i;
    s32 j;
    Ent *p;
    f32 r;
    f32 r1;
    f32 r2;

    Ent *base = D_00284580;
    for (i = 0; i < 25; i++) {
        p = &base[i];
        if (p->active == 0) {
            for (j = 0; j < 2; j++) {
                s32 off = j * 144;
                f32 *m;
                f32 *v;
                func_00359EB8((Sub *)((u8 *)p + (off + 672)));
                m = (f32 *)((u8 *)p + off);
                func_00359EB8((Sub *)((u8 *)p + (off + 96)));
                r1 = func_004408C0(0.3f, 0.5f);
                m[25] *= r1;
                m[29] *= r1;
                m[33] *= r1;
                m[37] *= r1;
                r2 = func_004408C0(0.2f, 1.3f);
                m[30] *= r2;
                m[38] *= r2;
                m[29] *= 0.4f;
                m[37] *= 0.4f;
                r = func_004408C0(-0.1f, 0.1f);
                v = (f32 *)((u8 *)p + j * 16);
                v[8] = pos[0] + r;
                r = func_004408C0(-0.1f, 0.1f);
                v[9] = pos[1] + r;
                v[10] = pos[2];
                v[11] = 1.0f;
                p->d[j] = func_004408C0(-0.03f, -0.01f);
                p->e[j] = func_004408C0(-7.99f, 0.0f);
                p->c[j] = func_0013D3E0() % 2;
            }
            p->f510 = 0;
            p->active = 1;
            p->f518 = 0;
            p->f51C = 0;
            p->q1 = *qb;
            p->q0 = *qa;
            return;
        }
    }
}
/* localdecomp:end func_00359F28 */
