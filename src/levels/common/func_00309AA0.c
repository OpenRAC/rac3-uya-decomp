#include "common.h"

/* localdecomp:start func_00309AA0 */
typedef int Q_309AA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_309AA0;
typedef struct {
    V4_309AA0 v0;
    u8 pad10[16];
    V4_309AA0 v20;
    u8 pad30[28];
    f32 f4C;
    s32 i50;
    u8 pad54[4];
    s32 i58;
    s32 i5C;
} P_309AA0;
typedef struct {
    u8 pad0[16];
    V4_309AA0 v10;
    u8 b20;
    u8 pad21[71];
    P_309AA0 *p68;
    u8 pad6C[84];
    V4_309AA0 vC0;
    u8 padD0[32];
    f32 fF0;
    f32 fF4;
    u8 padF8[4];
    s32 iFC;
} O_309AA0;
typedef struct {
    u8 pad0[52];
    u16 h34;
    u8 pad36[116];
    s16 hAA;
} M_309AA0;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 iC;
    V4_309AA0 v10;
} E_309AA0;
extern s32 D_001D673C;
extern M_309AA0 *D_001EAA98[];
extern M_309AA0 *D_001A71A0[];
extern u8 D_001EAAB0[];
extern E_309AA0 D_001F1BC0[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040CF10(f32, f32);
extern void func_0040C638(void *, void *);
extern void func_004C4AD8(s32, void *, s32);
extern s32 func_004C7670(void);
extern void func_004C6EC8(void *, void *);
extern void func_004C6FD8(void *, void *);
extern f32 func_0040BF38(void *);
extern void func_00449008(void *, void *, void *, s32, f32);
extern s32 func_003F9498(void *, s32, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C260(void *, void *, void *);
extern f32 func_0040BEF8(void *, void *);
extern void func_0030BC80(void *, void *, s32, s32);
extern void func_004A7200(s32, s32, void *);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_0030B160(void *, s32);
static __inline__ void vadd_309AA0(V4_309AA0 *d, V4_309AA0 *a, V4_309AA0 *b) {
    Q_309AA0 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
static __inline__ void vsubB_309AA0(V4_309AA0 *d, V4_309AA0 *a, V4_309AA0 *b) {
    Q_309AA0 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
M_309AA0 *func_00309AA0(O_309AA0 *obj) {
    V4_309AA0 v;
    V4_309AA0 a;
    V4_309AA0 b;
    V4_309AA0 c;
    P_309AA0 *p;
    M_309AA0 *m;
    M_309AA0 *ret;
    E_309AA0 *e;
    s32 i;
    f32 r;

    ret = 0;
    p = obj->p68;
    obj->fF0 = func_0040CEC8(obj->fF0, 0.052359883f);
    obj->fF4 = func_0040CF10(obj->fF4, 0.013089971f);
    obj->iFC = 0;
    func_0040C638(&obj->vC0, &obj->fF0);
    v = obj->v10;
    func_004C4AD8(p->i50, p, 0);
    vadd_309AA0(&obj->v10, &p->v0, &obj->v10);
    if (func_004C7670() != 0) {
        func_004C6EC8(&obj->v10, &obj->v10);
    }
    func_004C6FD8(p, p);
    if (D_001D673C == 0) {
        if (func_0040BF38(p) != 0.0f && func_0040BF38(&p->v20) != 0.0f) {
            func_00449008(p, p, &p->v20, 0, 0.075f);
        }
    }
    if (func_003F9498(&obj->v10, 0, obj, p->f4C) != 0) {
        m = D_001EAA98[0];
        if (m != 0 && m != D_001A71A0[0] && m->hAA != 1482) {
            ret = 0;
            if (m->h34 & 0x1000) {
                ret = m;
            }
        }
        obj->v10 = *(V4_309AA0 *)D_001EAAB0;
        func_0040BE90(&a, D_001EAAB0 + 16, 0.0009765625f);
        func_0040C0F0(&a, &a, 1.0f);
        func_0040C260(p, p, &a);
        r = func_0040BEF8(p, &a);
        func_0040BE90(&b, &a, r);
        vsubB_309AA0(&c, &p->v0, &b);
        func_0040BE90(p, &b, 0.85f);
        vadd_309AA0(&p->v0, &c, &p->v0);
        func_0040BE90(&p->v20, &p->v20, 0.95f);
        func_0030BC80(D_001EAAB0 - 16, &a, 6, 0x72FF);
        func_0030BC80(D_001EAAB0 - 16, &a, 6, 0xFF0000);
        func_004A7200(1, 0, obj);
    }
    i = p->i5C;
    if (i != -1) {
        e = &D_001F1BC0[i];
        e->v10 = obj->v10;
        e->v10.w = 4.0f;
        e->f0 = 0.25f;
        e->f4 = 0.14f;
        e->f8 = 1.0f;
        e->iC = 0;
        r = func_004408C0(-0.1f, 0.1f);
        e->f0 += r;
        e->f4 += r;
        e->f8 += r;
    }
    if (obj->v10.x < 2.0f || obj->v10.x > 1021.0f ||
        obj->v10.y < 2.0f || obj->v10.y > 1021.0f ||
        obj->v10.z < 2.0f || obj->v10.z > 1021.0f) {
        obj->b20 = 3;
        obj->v10 = v;
    }
    if (p->i58 < 8) {
        func_0030B160(obj, func_00440878(8, 20));
    }
    return ret;
}
/* localdecomp:end func_00309AA0 */
