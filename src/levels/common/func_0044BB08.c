#include "common.h"

/* localdecomp:start func_0044BB08 */
typedef int Q_44BB08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_44BB08;
typedef struct { V_44BB08 r[4]; } M_44BB08;
typedef struct { V_44BB08 r[3]; } R_44BB08;
typedef struct {
    V_44BB08 pos;
    s32 f64;
    void *f68;
    u16 f72;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 f77;
    u8 f78;
    u8 f79;
} T_44BB08;
typedef struct {
    V_44BB08 r[3];
    T_44BB08 t;
} E_44BB08;
typedef struct {
    u8 pad0[16];
    V_44BB08 v16;
    u8 pad32[4];
    s32 f36;
    u8 pad40[12];
    u16 f52;
    u8 pad54[138];
    V_44BB08 v192;
    u8 pad208[32];
    V_44BB08 v240;
} S1_44BB08;
typedef struct {
    V_44BB08 v0;
    u8 pad16[32];
    V_44BB08 v48;
} S2_44BB08;
typedef struct {
    u8 pad0[28];
    s32 *f28;
} I_44BB08;
typedef struct {
    u8 pad0[36];
    I_44BB08 *f36;
    u8 pad40[9];
    u8 f49;
    u8 pad50[2];
    u16 f52;
} K_44BB08;
typedef struct {
    u8 pad0[16];
    V_44BB08 pos;
    u8 pad32[208];
    V_44BB08 rot;
} O_44BB08;
extern s32 D_001E00D8;
extern s16 *D_0021DEA0[];
extern S1_44BB08 *D_001E009C;
extern s32 D_001D6768;
extern s16 **D_001D6764;
extern S2_44BB08 *D_001E0F5C;
extern s32 D_001D6770;
extern s16 **D_001D676C;
extern S2_44BB08 *D_001E0E50;
extern void func_00437600(K_44BB08 *, s32, M_44BB08 *);
extern void func_0040C638(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C8C0(void *, void *);
extern u8 func_0044B9F8(K_44BB08 *, M_44BB08 *, s32, V_44BB08 *, V_44BB08 *, V_44BB08 *, R_44BB08 *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C960(void *, void *, void *);
extern s32 func_00440878(s32, s32);

void func_0044BB08(O_44BB08 *o, E_44BB08 *out, s32 max, s32 id1, s32 id2, s32 id3, s32 cyc, K_44BB08 *k) {
    M_44BB08 buf[40];
    R_44BB08 m;
    V_44BB08 v;
    V_44BB08 a;
    V_44BB08 b;
    M_44BB08 t;
    s32 n;
    s32 i;
    s32 cnt;
    s32 r;
    u8 c;
    s16 *list;
    s16 *list3;
    E_44BB08 *e;
    T_44BB08 *p;

    if (max <= 0) {
        out->t.f74 = 0;
        return;
    }
    if (id1 == -1 && id2 == id1 && id3 == id2) {
        out->t.f74 = 0;
        return;
    }
    n = 0;
    if (k != 0) {
        if (k->f36->f28 != 0) {
            n = *k->f36->f28;
        }
        if (n == 0) {
            return;
        }
        if (n > 40) {
            return;
        }
        for (i = 0; i < n; i++) {
            func_00437600(k, i, &buf[i]);
        }
        k->f49 = 0;
        k->f52 |= 1;
    }
    func_0040C638(&v, &o->rot);
    func_0040C8E0(&t, &v);
    func_0040C8C0(&m, &t);
    cnt = 0;
    v = o->pos;
    if (id1 != -1 && id1 < D_001E00D8 && D_0021DEA0[id1] != 0) {
        list = D_0021DEA0[id1];
        p = &out->t;
        e = out;
        do {
            S1_44BB08 *s;
            s32 idx;
            idx = *list & 0x7FFF;
            s = &D_001E009C[idx];
            if (cnt >= max) {
                goto end;
            }
            p->f72 = idx;
            p->f74 = 2;
            p->f76 = 0;
            p->f64 = 0;
            if (k != 0) {
                p->f68 = k;
                if (p->f75 == 255) {
                    a = s->v16;
                    b = s->v192;
                    p->f75 = func_0044B9F8(k, buf, n, &a, &b, &v, &m);
                }
            }
            {
                Q_44BB08 x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->v16));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(p->pos) : "j"(x));
            }
            func_0040C2D0(&p->pos, &p->pos, &m);
            if (s->f36 == 0) {
                func_0040C638(&s->v192, &s->v240);
            }
            func_0040C960(e, &m, &s->v192);
            p = (T_44BB08 *)((u8 *)p + sizeof(E_44BB08));
            e++;
            cnt++;
            s->f52 |= 0x104;
        } while (*list++ >= 0);
    }
    if (id2 != -1) {
        r = 0;
        if (cyc > 0) {
            r = func_00440878(0, cyc);
        }
        if (id2 < D_001D6768 && D_001D6764[id2] != 0) {
            list = D_001D6764[id2];
            do {
                S2_44BB08 *s;
                s32 idx;
                idx = *list & 0x7FFF;
                s = &D_001E0F5C[idx];
                if (cnt >= max) {
                    goto end;
                }
                out[cnt].t.f76 = 1;
                out[cnt].t.f72 = idx;
                out[cnt].t.f74 = 2;
                out[cnt].t.f64 = 0;
                if (k != 0) {
                    out[cnt].t.f68 = k;
                    if (out[cnt].t.f75 == 255) {
                        a = s->v48;
                        b = s->v0;
                        out[cnt].t.f75 = func_0044B9F8(k, buf, n, &a, &b, &v, &m);
                    }
                }
                if (cyc <= 0) {
                    if (cyc < 0) {
                        c = 255;
                        out[cnt].t.f78 = c;
                    } else {
                        out[cnt].t.f78 = 0;
                    }
                } else {
                    c = cyc + 1;
                    out[cnt].t.f78 = c;
                    out[cnt].t.f79 = r;
                    r = (r + 1) % out[cnt].t.f78;
                }
                {
                    Q_44BB08 x, y;
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->v48));
                    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(out[cnt].t.pos) : "j"(x));
                }
                func_0040C2D0(&out[cnt].t.pos, &out[cnt].t.pos, &m);
                func_0040C960(&out[cnt], &m, s);
                cnt++;
            } while (*list++ >= 0);
        }
    }
    if (id3 != -1 && id3 < D_001D6770 && D_001D676C[id3] != 0) {
        list3 = D_001D676C[id3];
        do {
            S2_44BB08 *s;
            s32 idx;
            T_44BB08 *p3 = &out[cnt].t;
            idx = *list3 & 0x7FFF;
            s = &D_001E0E50[idx];
            if (cnt >= max) {
                goto end;
            }
            p3->f72 = idx;
            p3->f76 = 2;
            p3->f74 = 2;
            p3->f64 = 0;
            {
                Q_44BB08 x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->v48));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(p3->pos) : "j"(x));
            }
            func_0040C2D0(&p3->pos, &p3->pos, &m);
            func_0040C960(&out[cnt], &m, s);
            cnt++;
        } while (*list3++ >= 0);
    }
end:
    if (cnt != 0) {
        out[cnt - 1].t.f74 = 1;
    } else {
        out->t.f74 = 0;
    }
}
/* localdecomp:end func_0044BB08 */
