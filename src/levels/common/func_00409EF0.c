#include "common.h"

/* localdecomp:start func_00409EF0 */
typedef int Q_409EF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_409EF0;
typedef struct { V4_409EF0 v[4]; } M4_409EF0;
typedef struct { V4_409EF0 v[3]; } M3_409EF0;
typedef struct { f32 a[3]; f32 b[3]; } P_409EF0;
typedef struct { s32 a; s32 b; } W_409EF0;
typedef struct { f32 x, y, z, w; } F_409EF0;
extern P_409EF0 D_001E9450[];
extern W_409EF0 D_001E9C90[];
extern W_409EF0 D_001E9A80[];
extern F_409EF0 D_001EA2C0[];
extern F_409EF0 D_001E9EA0[];
extern s32 D_001E945C[];
extern s32 D_001E9A84[];
extern s32 D_001E9EA8[];
extern s32 D_001E9C94[];
extern s32 D_001EA2C8[];
extern f32 D_002C5240[];
extern f32 D_002C5348[];
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_00401BB0(void *, f32 *, f32 *);
extern void func_0040BCB8(void *, void *, s32);
extern void func_0040C2F8(void *, void *, void *);
extern f32 func_00444F60(f32, f32, f32);
extern void func_004051B8(void);
extern void func_004C1FE8(s32, unsigned long);
extern long func_00401CD0(s32);
extern void func_004066DC(s32, void *, void *, void *, s32);
void func_00409EF0(M4_409EF0 m, s32 n, f32 k, f32 ang, s32 c0, s32 c1, s32 c2, s32 t0, s32 t1) {
    V4_409EF0 p40;
    V4_409EF0 p50;
    M3_409EF0 r60;
    M3_409EF0 r90;
    V4_409EF0 pos;
    f32 scr[4];
    f32 mid[4];
    V4_409EF0 uv;
    V4_409EF0 out;
    Q_409EF0 x, y;
    s32 step;
    s32 i;
    s32 cnt;
    P_409EF0 *pp;
    F_409EF0 *ps;
    W_409EF0 *pc;
    W_409EF0 *pw;
    F_409EF0 *pf;

    if (n & 1) {
        n &= ~1;
    }
    if (n > 64) {
        n = 64;
    }
    step = 64 / n;
    if (64 % step) {
        n -= 64 % step;
        step = 64 / n;
    }
    if (n < 4) {
        return;
    }
    __asm__("sq $0,%0" : "=m"(p50));
    p50.x = ang;
    func_0040C638(&r60, &p50);
    func_0040C960(&r90, &m, &r60);
    pos = m.v[3];
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(r90.v[0]));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p40) : "j"(x));
    func_00401BB0(&p40, &scr[0], &scr[1]);
    uv.w = 1.0f;
    pp = D_001E9450;
    pc = D_001E9C90;
    pw = D_001E9A80;
    ps = D_001EA2C0;
    pf = D_001E9EA0;
    uv.x = 0.0f;
    for (i = 0; i <= n; i++) {
        func_0040BCB8(pp->a, &p40, 12);
        uv.y = D_002C5348[i * step];
        uv.z = D_002C5240[i * step];
        func_0040C2F8(&out, &uv, &r90);
        func_0040BCB8(pp->b, &out, 12);
        pc->a = c1;
        pc->b = c0;
        func_00401BB0(&out, &ps->z, &ps->w);
        if (i == 0) {
            ps->x = scr[0];
            ps->y = scr[1];
        } else {
            mid[0] = (ps[-1].z + ps->z) * 0.5f;
            mid[1] = (ps[-1].w + ps->w) * 0.5f;
            ps->x = func_00444F60(scr[0], mid[0], k);
            ps->y = func_00444F60(scr[1], mid[1], k);
        }
        pw->a = c2;
        pw->b = c2;
        pf->x = 0.5f;
        pf->y = 1.0f;
        pf->z = i & 1;
        pf->w = 0.0f;
        pp++;
        pc++;
        pw++;
        ps++;
        pf++;
    }
    func_004051B8();
    cnt = n * 2 + 1;
    func_004C1FE8(0x47, 0x513F1);
    func_004C1FE8(6, func_00401CD0(t0));
    func_004C1FE8(8, 4);
    func_004C1FE8(0x42, 0x800000004AUL);
    func_004066DC(cnt, D_001E945C, D_001E9A84, D_001E9EA8, 1);
    func_004C1FE8(6, func_00401CD0(t1));
    func_004C1FE8(8, 5);
    func_004C1FE8(0x42, 0x8000000054UL);
    func_004066DC(cnt, D_001E945C, D_001E9C94, D_001EA2C8, 1);
    func_004C1FE8(0x47, 0x5360B);
}
/* localdecomp:end func_00409EF0 */
