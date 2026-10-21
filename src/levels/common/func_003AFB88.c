#include "common.h"

/* localdecomp:start func_003AFB88 */
typedef int Q_3AFB88 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AFB88;
typedef struct {
    u8 pad0[26];
    u16 h1A;
    u8 pad1C[20];
} __attribute__((aligned(16))) C_3AFB88;
typedef struct O_3AFB88 O_3AFB88;
typedef struct {
    V4_3AFB88 v0;
    V4_3AFB88 v10;
    V4_3AFB88 v20;
    u8 pad30[4];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[12];
    s32 i4C;
    s32 i50;
} P_3AFB88;
struct O_3AFB88 {
    u8 pad0[104];
    P_3AFB88 *p;
    u8 pad6C[62];
    s16 hAA;
    u8 padAC[12];
    O_3AFB88 *oB8;
};
typedef struct {
    u8 pad0[24];
    O_3AFB88 *o18;
    u8 pad1C[4];
    V4_3AFB88 v20;
} T_3AFB88;
extern int D_001D66B0;
extern T_3AFB88 D_001EAA80;
extern void func_003B0078();
extern f32 func_00440978(void);
extern void *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00443628(void *, void *, s32, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, void *);
extern s32 func_00452F60(void *);
extern void func_003B0540(void *, s32, s32);
extern void func_00452F40(void *, s32);
extern void func_00436220(void *);
extern void func_004026A0(void *, void *);
extern f32 func_0040BFE8(void *, void *);
extern void func_003B05E8(void *);
static __inline__ void vaddB_3AFB88(V4_3AFB88 *d, V4_3AFB88 *a, V4_3AFB88 *b) {
    Q_3AFB88 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
static __inline__ void vadd_3AFB88(V4_3AFB88 *d, V4_3AFB88 *a, V4_3AFB88 *b) {
    Q_3AFB88 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
void func_003AFB88(O_3AFB88 *obj) {
    V4_3AFB88 v;
    V4_3AFB88 a;
    C_3AFB88 c;
    V4_3AFB88 d;
    V4_3AFB88 e;
    P_3AFB88 *p;
    T_3AFB88 *t;
    V4_3AFB88 *u;
    f32 f, s, k;

    s32 n;
    p = obj->p;
    f = p->f38 + 1.0f;
    s = p->f3C;
    p->f38 = f;
    if (f > 84.0f) {
        s = s * (1.0f - (f - 84.0f) / 6.0f);
    }
    if (f > 2.0f) {
        v = p->v10;
    } else {
        v = p->v0;
    }
    n = func_00440978();
    func_00466F98(&p->v10, &D_001D66B0, 4, 96, p->i50, n, 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    if (p->f38 < 15.0f) {
        p->f34 += 0.33333334f;
        func_0040C0F0(&p->v10, &p->v20, p->f34);
        func_0040C0F0(&a, &p->v20, 0.06666667f);
        func_00443628(&c, obj, 0x10000, &a, s);
        c.h1A = obj->hAA;
        vaddB_3AFB88(&p->v10, &p->v0, &p->v10);
        func_0040C0F0(&d, &p->v20, -0.33333334f);
        vadd_3AFB88(&d, &d, &p->v10);
        if (func_003F8448(&p->v10, &v, 16, obj->oB8, &c) != 0) {
            t = &D_001EAA80;
            if (t->o18 != obj->oB8 && (t->o18 == 0 || t->o18->hAA != 7295)) {
                u = &t->v20;
                p->v10 = *u;
                if (func_00452F60(obj) == 0) {
                    func_003B0540(u, 20, p->i4C);
                    func_00452F40(obj, 1);
                }
                func_00436220(obj);
                return;
            }
        }
        func_0040C0F0(&e, &p->v20, 0.33333334f);
        vadd_3AFB88(&p->v0, &p->v0, &e);
        func_004026A0(func_003B0078, obj);
    } else if (p->f38 < 90.0f) {
        if (func_0040BFE8(p, &p->v10) > 0.33333334f) {
            k = p->f34 + 0.33333334f;
            p->f34 = k;
            func_0040C0F0(&p->v10, &p->v20, k);
            func_0040C0F0(&a, &p->v20, 0.06666667f);
            func_00443628(&c, obj, 0x10000, &a, s);
            c.h1A = obj->hAA;
            vaddB_3AFB88(&p->v10, &p->v0, &p->v10);
            func_0040C0F0(&d, &p->v20, -0.33333334f);
            vadd_3AFB88(&d, &d, &p->v10);
            if (func_003F8448(&p->v10, &v, 16, obj, &c) != 0) {
                t = &D_001EAA80;
                if (t->o18 != obj->oB8 && (t->o18 == 0 || t->o18->hAA != 5669)) {
                    u = &t->v20;
                p->v10 = *u;
                    if (func_00452F60(obj) == 0) {
                        func_003B0540(u, 20, p->i4C);
                        func_00452F40(obj, 1);
                    }
                    func_00436220(obj);
                    return;
                }
            }
            func_0040C0F0(&e, &p->v20, 0.83333337f);
            vadd_3AFB88(&p->v0, &p->v0, &e);
            func_004026A0(func_003B0078, obj);
        }
    } else {
        func_003B05E8(&p->v10);
        func_00436220(obj);
    }
}
/* localdecomp:end func_003AFB88 */
