#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0035AA10 */
typedef struct { f32 x, y, z, w; } V4_35AA10 __attribute__((aligned(16)));
typedef int Q_35AA10 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x18];
    u8 x18;
    u8 x19;
    u16 x1A;
    u8 pad1C[0x14];
} St_35AA10;
typedef struct {
    u8 pad0[0x18];
    u8 *x18;
    u8 pad1C[4];
    V4_35AA10 x20;
} G_35AA10;

extern G_35AA10 D_001EAA80_35AA10;

extern void func_004C76B8_35AA10(void);
extern void func_004C76F0_35AA10(void);
extern s32 func_003F8448_35AA10(V4_35AA10 *a, V4_35AA10 *b, s32 c, u8 *m, s32 e);
extern void func_0040BE90_35AA10(V4_35AA10 *a, V4_35AA10 *b, f32 s);
extern void func_00443628_35AA10(St_35AA10 *a, u8 *m, s32 b, V4_35AA10 *c, f32 d);
extern void func_003FB1D0_35AA10(V4_35AA10 *a, s32 b, u8 *m, St_35AA10 *c, f32 d);
extern void func_0032FE90(V4_35AA10 *a, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3,
                          s32 s0, s32 s1, s32 s2, s32 s3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8, s32 s9,
                          s32 s10, s32 s11, s32 s12, s32 s13, s32 s14, s32 s15, s32 s16, s32 s17,
                          f32 f12, f32 f13, f32 f14, f32 f15);
extern void func_00441FB8_35AA10(u8 *m, s32 a, s32 b);
extern s32 func_00452EC8_35AA10(u8 *m);
extern void func_00436220_35AA10(u8 *m);
extern s32 func_004562A0_35AA10(V4_35AA10 *a, s32 b, f32 c);
extern void func_004026A0_35AA10(void *fn, u8 *m);
extern void func_0035AE00_35AA10(void);
extern void func_0035AF18_35AA10(u8 *m, V4_35AA10 *a, V4_35AA10 *b);

void func_0035AA10(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    s32 state = m[0x20];
    V4_35AA10 pos;
    V4_35AA10 tmp;
    s32 saved;
    V4_35AA10 *pp;
    V4_35AA10 *mp;
    V4_35AA10 *gv;

    switch (state) {
    case 1:
        pp = &pos;
        mp = (V4_35AA10 *)(m + 0x10);
        *pp = *mp;
        {
            Q_35AA10 a, b;
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*mp));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_35AA10 *)v));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(b) : "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(*mp) : "j"(b));
        }
        if (*(f32 *)(m + 0x10) < 2.0f || 1021.0f < *(f32 *)(m + 0x10) ||
            *(f32 *)(m + 0x14) < 2.0f || 1021.0f < *(f32 *)(m + 0x14) ||
            *(f32 *)(m + 0x18) < 2.0f || 1021.0f < *(f32 *)(m + 0x18)) {
            goto die;
        }
        *(s32 *)(v + 0x14) += 1;
        saved = *(s32 *)(*(u8 **)(v + 0x1C) + 0x98);
        *(s32 *)(*(u8 **)(v + 0x1C) + 0x98) = 0;
        func_004C76B8_35AA10();
        if (func_003F8448_35AA10(pp, mp, 0, m, 0) != 0) {
            G_35AA10 *g = &D_001EAA80_35AA10;
            if (g->x18 == 0 || g->x18 != *(u8 **)(v + 0x1C)) {
                St_35AA10 st;
                *(V4_35AA10 *)(m + 0x10) = g->x20;
                m[0x20] = 2;
                gv = &g->x20;
                tmp = *(V4_35AA10 *)v;
                func_0040BE90_35AA10(&tmp, &tmp, 3.0f);
                tmp.w = 5627.92480f;
                func_00443628_35AA10(&st, m, *(s32 *)(v + 0x28), &tmp, *(f32 *)(v + 0x24));
                st.x19 = state;
                st.x1A = *(u16 *)(m + 0xAA);
                st.x18 = 0;
                if (g->x18 != 0) {
                    if (g->x18 != *(u8 **)(v + 0x1C)) {
                        func_003FB1D0_35AA10(gv, 0, m, &st, 1.0f);
                    }
                } else {
                    func_003FB1D0_35AA10(gv, 0, m, &st, 0.6f);
                }
            }
        }
        func_004C76F0_35AA10();
        *(s32 *)(*(u8 **)(v + 0x1C) + 0x98) = saved;
        if (*(s32 *)(v + 0x14) < 0xB5) {
            break;
        }
        goto die;
    case 2:
        func_0032FE90((V4_35AA10 *)(m + 0x10), 0, 5, 2, 2, 2, 0, 0,
                      0, 1, 0, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                      0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0,
                      0.25f, 1.0f, 0.0f, 2.0f);
        func_00441FB8_35AA10(m, 4, -1);
        break;
    case 4:
        if (func_00452EC8_35AA10(m) != 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) |= 1;
            m[0x31] = 0;
        }
        if (*(u16 *)(m + 0x96) >= 11) {
        die:
            func_00436220_35AA10(m);
            return;
        }
        *(u16 *)(m + 0x96) += 1;
        break;
    }
    tmp = *(V4_35AA10 *)(m + 0x10);
    tmp.w = 0.5f;
    if (func_004562A0_35AA10(&tmp, 0, 96.0f) > 0) {
        V4_35AA10 s;
        func_004026A0_35AA10(func_0035AE00_35AA10, m);
        s = *(V4_35AA10 *)(m + 0x10);
        func_0035AF18_35AA10(m, &s, &pos);
    }
}
/* localdecomp:end func_0035AA10 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0035AE00);

/* localdecomp:start func_0035AF18 */
typedef int Q_35AF18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35AF18;
typedef struct { char p0[2]; u8 b2; u8 b3; char p4[0x28]; f32 f2c; } P_35AF18;
typedef struct { char p0[0x10]; V4_35AF18 v10; char p20[0x48]; void *p68; } A_35AF18;
extern u8 *D_00221118_35AF18[];
extern f32 func_0040BF38_35AF18(void *);
extern void func_0040C0F0_35AF18(V4_35AF18 *, V4_35AF18 *, f32);
extern void func_0044DF40_35AF18(V4_35AF18 *, V4_35AF18 *, s32);
extern f32 func_00440918_35AF18(f32, f32);
extern f32 func_004408C0_35AF18(f32, f32);
extern void func_0040BE90_35AF18(V4_35AF18 *, void *, f32);
extern s32 func_00440878_35AF18(s32, s32);
extern s32 func_0013D3E0_35AF18(void);
extern P_35AF18 *func_00466F98_35AF18(V4_35AF18 *, V4_35AF18 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00440848_35AF18(s32);
extern void func_00448CD0_35AF18(V4_35AF18 *, f32);
extern P_35AF18 *func_00462190_35AF18(V4_35AF18 *, V4_35AF18 *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_0035AF18(A_35AF18 *a, V4_35AF18 from, V4_35AF18 to) {
    void *s = a->p68;
    V4_35AF18 off;
    V4_35AF18 pos;
    V4_35AF18 step;
    V4_35AF18 v60;
    V4_35AF18 v70;
    f32 len, f;
    s32 n, i, r, x, c, col, col2;
    P_35AF18 *p;
    P_35AF18 *q;

    len = func_0040BF38_35AF18(s);
    n = len / 0.1f;
    pos = to;
    {
        Q_35AF18 v1, v2, r1;
        __asm__("lqc2 %0, %1" : "=j"(v1) : "m"(from));
        __asm__("lqc2 %0, %1" : "=j"(v2) : "m"(to));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(v1), "j"(v2));
        __asm__("sqc2 %1, %0" : "=m"(step) : "j"(r1));
    }
    func_0040C0F0_35AF18(&step, &step, len / n);
    func_0044DF40_35AF18(&a->v10, &v60, 1);
    for (i = 0; i < n / 2; i++) {
        r = func_00440918_35AF18(1.0f, 3.0f);
        f = func_004408C0_35AF18(0.1f, 0.2f) * 0.01666666753590107f;
        func_0040BE90_35AF18(&off, &v60, -f);
        x = func_00440878_35AF18(3, 6);
        if (func_0013D3E0_35AF18() & 2) {
            c = 0x40;
            col = 0x407FFF;
        } else {
            c = 0x60;
            col = 0x4040FF;
        }
        p = func_00466F98_35AF18(&pos, &off, x, c, col, r, 63000.00390625f, 10000.0f, 1.0f, 0.0f, 0.0f);
        {
            Q_35AF18 v1, v2, r1;
            __asm__("lqc2 %0, %1" : "=j"(v1) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(v2) : "m"(step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(v1), "j"(v2));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(r1));
        }
        if (p) {
            p->b2 = *D_00221118_35AF18[23];
            if (c == 0x40) p->b3 = 0x48;
            else p->b3 = 0x44;
        }
    }
    if (func_00440848_35AF18(2)) {
        func_0040BE90_35AF18(&v70, s, -0.03333333507180214f);
        func_00448CD0_35AF18(&v70, 0.10000000894069672f);
        v70.z += 0.05000000447034836f;
        col2 = func_00440848_35AF18(2) ? 0x7F407FFF : 0x7F80DFFF;
        q = func_00462190_35AF18(&a->v10, &v70, col2, 0xFF, func_00440878_35AF18(10, 20), 0, -1, -1, 0, 94500.0f);
        if (q) {
            q->f2c = 0.0016666667070239782f;
            q->b2 = *D_00221118_35AF18[53];
        }
    }
}
/* localdecomp:end func_0035AF18 */

