#include "common.h"

/* localdecomp:start func_004583C0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4583C0;
typedef struct {
    u8 pad0[16];
    V4_4583C0 v10;
} O_4583C0;
typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 fC;
    u8 pad10[64];
    V4_4583C0 v50;
    u8 pad60[40];
    s32 i88;
    s32 i8C;
    f32 f90;
    u8 pad94[68];
    s32 iD8;
} X_4583C0;
typedef struct {
    u8 pad0[0x49];
    u8 b49;
    u16 h4A;
} T_4583C0;
typedef struct {
    u8 pad0[0x18];
    s32 i18;
    s32 i1C;
    u8 pad20[8];
    f32 f28;
} G_4583C0;
extern G_4583C0 D_001EAA80;
extern V4_4583C0 D_001EAAC0;
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern s32 func_003FC730(void);
extern T_4583C0 *func_00445EB8(void *);
extern void func_0040C0F0(void *, void *, f32);
void func_004583C0(O_4583C0 *o, X_4583C0 *x, f32 h) {
    V4_4583C0 a;
    V4_4583C0 b;
    T_4583C0 *t;
    s32 r;
    s32 m;
    s32 m2;
    a = o->v10;
    a.z = a.z + (x->f8 + 0.1f);
    if (h != 0.0f) {
        b = o->v10;
        b.z = b.z - h;
    } else {
        b = o->v10;
        b.z = b.z - (x->fC + 0.1f);
    }
    if (func_003F8448(&a, &b, 2, o, 0) != 0) {
        x->f90 = D_001EAA80.f28;
        x->i88 = D_001EAA80.i18;
        x->i8C = D_001EAA80.i1C;
        r = func_003FC730();
        x->iD8 = r;
        if (r != -1) {
            t = func_00445EB8(o);
            if (t != 0 && t->b49 != 0 && t->h4A != 0 && ((t->h4A >> x->iD8) & 1) != 0) {
                if (o->v10.z - x->f90 > 0.3f) {
                    x->iD8 = -1;
                    x->f90 = 0.0f;
                    x->i88 = 0;
                    x->i8C = 0;
                }
            } else if (x->iD8 == 0 || x->iD8 == 3) {
                m = 0x20;
                __asm__("ori %0, %1, 2" : "=&r"(m2) : "r"(m));
                if (func_003F8448(&a, &b, m2, o, 0) != 0) {
                    x->f90 = D_001EAA80.f28;
                    x->i88 = D_001EAA80.i18;
                    x->i8C = D_001EAA80.i1C;
                    x->iD8 = func_003FC730();
                } else {
                    x->f90 = 0.0f;
                    x->iD8 = -1;
                    __asm__("sq $0,%0" : "=m"(x->v50));
                    x->i88 = 0;
                    x->i8C = 0;
                }
            }
        }
        func_0040C0F0(&x->v50, &D_001EAAC0, 1.0f);
    } else {
        x->f90 = 0.0f;
        x->iD8 = -1;
        __asm__("sq $0,%0" : "=m"(x->v50));
        x->i8C = 0;
        x->i88 = 0;
    }
}
/* localdecomp:end func_004583C0 */
