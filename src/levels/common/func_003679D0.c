#include "common.h"

/* localdecomp:start func_003679D0 */
typedef int Q_003679D0 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003679D0;

typedef struct {
    s32 type;
    f32 size;
    u32 c1;
    u32 c2;
    s32 n;
    s32 pad[3];
    V4_003679D0 pos;
    V4_003679D0 pos2;
} Draw_003679D0;

extern s32 D_001E1C00;
extern s32 D_001E1C90;
extern s32 D_001E1C10;
extern s32 D_001E1C50;
extern f32 D_001E1CE4;
extern f32 D_001E1CA8;
extern u32 func_0040D020(u32, s32, f32);
extern void func_003676F0(Draw_003679D0 *);
extern void func_0040BE90(V4_003679D0 *, V4_003679D0 *, f32);
extern void func_004434F8(V4_003679D0 *, V4_003679D0 *, V4_003679D0 *, V4_003679D0 *);

void func_003679D0(s32 unused, V4_003679D0 *pos) {
    V4_003679D0 t0;
    V4_003679D0 t1;
    V4_003679D0 t2;
    Draw_003679D0 d;
    V4_003679D0 *p;
    s32 i;
    s32 st;
    Q_003679D0 qa;
    Q_003679D0 qb;

    d.pos = *pos;
    for (i = 0; i < 4; i++) {
        st = (&D_001E1C00)[i];
        if (st == 0) {
            continue;
        }
        switch (st) {
            case 1 ... 3:
                d.type = 23;
                d.size = 0.25f;
                if ((&D_001E1C90)[i] != -1) {
                    d.c1 = (&D_001E1C90)[i];
                    d.c2 = func_0040D020((&D_001E1C90)[i] & 0xFFFFFF, 0, 0.25f) + ((&D_001E1C90)[i] & 0xFF000000);
                } else {
                    d.c1 = 0x306020FF;
                    d.c2 = 0x304820E0;
                }
                if (0.0f < D_001E1CE4) {
                    d.c1 -= (s32)(D_001E1CE4 * 16.0f) << 24;
                    d.c2 = (d.c2 & 0xFFFFFF) + (d.c1 & 0xFF000000);
                }
                d.n = 6;
                break;
            case 4 ... 6:
                d.type = 47;
                d.size = 0.3f;
                if ((&D_001E1C90)[i] != -1) {
                    d.c1 = (&D_001E1C90)[i];
                    d.c2 = func_0040D020((&D_001E1C90)[i] & 0xFFFFFF, 0, 0.25f) + ((&D_001E1C90)[i] & 0xFF000000);
                } else {
                    d.c1 = 0x68F02060;
                    d.c2 = 0x68802040;
                }
                if (0.0f < D_001E1CE4) {
                    d.c1 -= (s32)(D_001E1CE4 * 32.0f) << 24;
                    d.c2 = (d.c2 & 0xFFFFFF) + (d.c1 & 0xFF000000);
                }
                d.n = 4;
                break;
        }
        d.pos2 = ((V4_003679D0 *)&D_001E1C10)[i];
        if ((&D_001E1C00)[i] != 3 && (&D_001E1C00)[i] != 6) {
            func_003676F0(&d);
        }
        switch ((&D_001E1C00)[i]) {
            case 2 ... 3:
                d.n -= 3;
                break;
            case 5 ... 6:
                d.n -= 1;
                break;
            default:
                continue;
        }
        if ((&D_001E1C00)[i] != 3 && (&D_001E1C00)[i] != 6) {
            func_0040BE90(&t0, &((V4_003679D0 *)&D_001E1C50)[i], D_001E1CA8);
            p = &((V4_003679D0 *)&D_001E1C10)[i];
            __asm__(
                "lqc2 %1, %2\n\t"
                "lqc2 %0, %3\n\t"
                "vadd.xyz %0, %0, %1"
                : "=&j"(qb), "=&j"(qa) : "m"(*p), "m"(t0));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(qb));
            func_004434F8(&t1, p, &t0, pos);
            __asm__ __volatile__(
                "lqc2 vf2, %2\n\t"
                "lqc2 vf1, %3\n\t"
                "vsub.xyz vf1, vf1, vf2\n\t"
                "sqc2 vf1, %1\n\t"
                "lqc2 vf2, %3\n\t"
                "lqc2 vf1, %1\n\t"
                "vadd.xyz vf2, vf2, vf1\n\t"
                "sqc2 vf2, %0"
                : "=m"(d.pos2), "=m"(t2) : "m"(*p), "m"(t1));
        }
        d.c1 += 0x20000000;
        d.size = -d.size;
        d.c2 += 0x20000000;
        func_003676F0(&d);
    }
}
/* localdecomp:end func_003679D0 */
