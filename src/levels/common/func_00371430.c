#include "common.h"

typedef int Q_371430 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_371430;

typedef struct {
    u8 pad0[724];
    s32 f724;
} O_371430;

typedef struct {
    u8 pad0[16];
    V4_371430 pos;
    u8 pad32[104 - 32];
    O_371430 *o;
} M_371430;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    u8 pad4[40];
    f32 f44;
} P_371430;

typedef struct {
    u8 pad0[0x5C];
    u8 *p;
} D_371430;

extern u8 D_001A4EC0[];
extern D_371430 D_00221118;
extern u8 *D_002211EC[];

extern f32 func_0040BF38(O_371430 *);
extern void func_0040C0F0(V4_371430 *, V4_371430 *, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(V4_371430 *, void *, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_0013D3E0(void);
extern P_371430 *func_00466F98(V4_371430 *, V4_371430 *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
extern s32 func_00440848(s32);
extern void func_00448CD0(V4_371430 *, f32);
extern P_371430 *func_00462190(V4_371430 *, V4_371430 *, u32, u32, s32, s32, s32, s32, f32, s32);

/* localdecomp:start func_00371430 */
void func_00371430(M_371430 *m, V4_371430 *from, V4_371430 *to) {
    V4_371430 a;
    V4_371430 b;
    V4_371430 tmp;
    V4_371430 pos;
    V4_371430 step;
    V4_371430 v;
    u32 c1 = 0x407FFF;
    u32 c2 = 0x4040FF;
    u32 c3, c4, c5;
    O_371430 *o;
    f32 len;
    f32 f;
    s32 n, i, k, j, sz;
    u32 col;
    P_371430 *p;
    P_371430 *q;

    *(Q_371430 *)&a = *(Q_371430 *)from;
    o = m->o;
    *(Q_371430 *)&b = *(Q_371430 *)to;
    len = func_0040BF38(o);
    n = len / 0.1f;
    *(Q_371430 *)&pos = *(Q_371430 *)&b;
    __asm__(
        "lqc2 vf1, %1\n\t"
        "lqc2 vf2, %2\n\t"
        "vsub.xyz vf1, vf1, vf2\n\t"
        "sqc2 vf1, %0"
        : "=m"(step) : "m"(a), "m"(b));
    func_0040C0F0(&step, &step, len / n);
    if (o->f724 == 2 || o->f724 == 3) {
        c1 = 0xFF7F40;
        c2 = 0xFF4040;
    }
    if (o->f724 < 4) {
        for (i = 0; i < n; i++) {
            k = func_00440918(1.0f, 3.0f);
            f = -(func_004408C0(0.1f, 0.2f) * 0.0166666675f);
            func_0040BE90(&tmp, D_001A4EC0, f);
            j = func_00440878(3, 6);
            if (func_0013D3E0() & 2) {
                sz = 64;
                col = c1;
            } else {
                sz = 96;
                col = c2;
            }
            p = func_00466F98(&pos, &tmp, j, sz, col, k, 63000.0039f, 10000.0f, 1.0f, 0.0f, 0.0f);
            {
                Q_371430 x;
                __asm__(
                    "lqc2 vf1, %1\n\t"
                    "lqc2 vf2, %2\n\t"
                    "vadd.xyz %0, vf1, vf2"
                    : "=j"(x) : "m"(pos), "m"(step));
                __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
            }
            if (p != 0) {
                p->b2 = *D_00221118.p;
                p->b3 = (sz == 64) ? 72 : 68;
            }
        }
    }
    c3 = 0x7F407FFF;
    c4 = 0x7F80DFFF;
    c5 = 0xFF;
    if (o->f724 == 2 || o->f724 == 3) {
        c3 = 0x7FFF7F40;
        c4 = 0x7FFFDF80;
        c5 = 0xFF0000;
    }
    if (o->f724 < 4) {
        if (func_00440848(2) != 0) {
            func_0040BE90(&v, o, -0.0333333351f);
            func_00448CD0(&v, 0.100000009f);
            v.z += 0.0500000045f;
            col = func_00440848(2) ? c3 : c4;
            q = func_00462190(&m->pos, &v, col, c5, func_00440878(10, 20), 0, -1, -1, 94500.0f, 0);
            if (q != 0) {
                q->f44 = 0.00166666671f;
                q->b2 = *D_002211EC[0];
            }
        }
    }
}
/* localdecomp:end func_00371430 */
