#include "common.h"

/* localdecomp:start func_0031A108 */
typedef int Q_31A108 __attribute__((mode(TI)));
typedef union {
    Q_31A108 q;
    struct { f32 x, y, z, w; } f;
} __attribute__((aligned(16))) V4_31A108;
typedef struct {
    V4_31A108 v;
    u8 pad10[0x10];
} E_31A108;
typedef struct {
    u8 pad0[0x30];
    V4_31A108 pos;
} M_31A108;
typedef struct {
    s32 w0;
    u8 pad4[0x30 - 0x4];
    s32 w30;
    s32 w34;
    s32 w38;
    f32 f3C;
    f32 f40, f44, f48;
    f32 f4C;
    f32 f50, f54, f58;
    f32 f5C;
    f32 f60;
    u8 pad64[0x6C - 0x64];
    s32 w6C;
} P_31A108;
typedef struct {
    u8 pad0[0x68];
    P_31A108 *p68;
} O_31A108;

extern u16 **D_001D6764;
extern E_31A108 *D_001E0F54;
extern M_31A108 *D_001E0F5C;
extern V4_31A108 D_001E2A40;

extern s32 func_0040D0C0(void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern s32 func_00444338(s32, s32, f32);
extern void func_0031A0C0(void *, s32 *, void *, s32 *, s32 *);
extern void func_0044E7E8(s32, void *, s32 *, f32, f32);

void func_0031A108(O_31A108 *obj) {
    Q_31A108 buf[70];
    s32 ids[70];
    V4_31A108 bb;
    V4_31A108 pos;
    V4_31A108 off;
    s32 cnt;
    s32 h;
    P_31A108 *p;
    u16 *e;
    M_31A108 *m;

    p = obj->p68;
    cnt = 0;
    for (e = D_001D6764[p->w0]; e != 0; e++) {
        s32 idx;
        if ((s16)e[-1] < 0 && e != D_001D6764[p->w0]) {
            break;
        }
        idx = *e & 0x7FFF;
        m = &D_001E0F5C[idx];
        if (m == 0) {
            break;
        }
        {
            E_31A108 *x = &D_001E0F54[idx];
            bb = x->v;
        }
        bb.f.w += p->f4C;
        if (func_0040D0C0(&bb, p->f60) < 0) {
            continue;
        }
        pos = m->pos;
        {
            V4_31A108 t;
            t.q = 0;
            t.f.x = p->f50;
            t.f.y = p->f54;
            t.f.z = p->f58;
            off = t;
        }
        func_0040C2D0(&off, &off, m);
        {
            Q_31A108 a, b, r;
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(off));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(r));
        }
        if (p->w6C != 0) {
            func_0031A0C0(&pos, &p->w30, buf, ids, &cnt);
            continue;
        }
        {
            V4_31A108 dir;
            V4_31A108 n;
        {
            Q_31A108 a, b, r;
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001E2A40));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(b), "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(r));
        }
        func_0040C0F0(&dir, &dir, 1.0f);
        {
            V4_31A108 t;
            t.q = 0;
            t.f.x = p->f40;
            t.f.y = p->f44;
            t.f.z = p->f48;
            n = t;
        }
        func_0040C2D0(&n, &n, m);
        func_0040C0F0(&n, &n, 1.0f);
        {
            f32 d = func_0040BEF8(&dir, &n);
            if (p->f3C < d) {
                d = d * 0.5f + 0.5f;
                if (p->w38 != 0) {
                    d = d * d;
                }
                h = func_00444338(p->w34, p->w30, d);
                func_0031A0C0(&pos, &h, buf, ids, &cnt);
            }
        }
        }
    }
    func_0044E7E8(cnt, buf, ids, p->f4C, p->f5C);
}
/* localdecomp:end func_0031A108 */
