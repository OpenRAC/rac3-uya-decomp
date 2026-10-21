#include "common.h"

/* localdecomp:start func_00301710 */
typedef int Q_301710 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_301710;
typedef struct Z_301710 {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
} Z_301710;
typedef struct Y_301710 {
    u8 pad0[0xC];
    Z_301710 *pC;
    V_301710 v10;
    u8 pad20[0x30];
    f32 f50;
    u8 pad54[0x24];
    f32 f78;
} Y_301710;
typedef struct X_301710 {
    u8 pad0[0x10];
    V_301710 v;
    u8 pad20[0x48];
    Y_301710 *p68;
    u8 pad6C[0x50];
    u8 fBC;
} X_301710;
typedef struct G_301710 {
    u8 pad0[0x18];
    Z_301710 *p18;
    u8 pad1C[0xC];
    f32 f28;
} G_301710;
extern G_301710 D_001EAA80;
extern f32 D_001EAAA0[];
extern s32 func_00448E90(V_301710 *);
extern void func_00441FB8(X_301710 *, s32, s32);
extern void func_00449720(X_301710 *, Z_301710 *, void *, V_301710 *, V_301710 *, V_301710 *);
extern void func_0044E088(V_301710 *, V_301710 *, V_301710 *, f32);
extern s32 func_003F8448(V_301710 *, V_301710 *, s32, X_301710 *, s32);
extern s32 func_00447CA0(Z_301710 *);
extern s32 func_00449388(Z_301710 *);
extern void func_004498A0(X_301710 *, Z_301710 *, V_301710 *, void *, void *, V_301710 *);
void func_00301710(X_301710 *x) {
    V_301710 a;
    V_301710 b;
    V_301710 c;
    Y_301710 *y = x->p68;
    s32 flag = 0;
    f32 f20;
    f32 t;
    f32 r;
    G_301710 *g;
    Z_301710 *z;
    if (func_00448E90(&x->v) == 0) {
        func_00441FB8(x, 5, -1);
        return;
    }
    if (y->pC != 0) {
        __asm__("sq $0,%0" : "=m"(c));
        func_00449720(x, y->pC, (u8 *)y + 0x70, &c, &x->v, &c);
    }
    *(Q_301710 *)&a = *(Q_301710 *)&x->v;
    func_0044E088(&x->v, &a, &a, -0.5f);
    *(Q_301710 *)&b = *(Q_301710 *)&a;
    func_0044E088(&x->v, &b, &b, 1.5f);
    if (func_003F8448(&a, &b, 2, x, 0) != 0) {
        flag = 1;
        f20 = D_001EAAA0[2];
    } else {
        f20 = b.z;
    }
    if (flag != 0) {
        g = &D_001EAA80;
        if (g->p18 != 0) {
            if (func_00447CA0(g->p18) != 0) {
                x->v.x = y->v10.x = g->p18->f10;
                x->v.y = y->v10.y = g->p18->f14;
                x->v.z = g->f28;
                *(Q_301710 *)&y->v10 = *(Q_301710 *)&x->v;
                func_0044E088(&x->v, &y->v10, &y->v10, -0.5f);
            } else if (y->pC == 0) {
                if (func_00449388(g->p18) != 0) {
                    z = g->p18;
                    y->pC = z;
                    func_004498A0(x, z, &x->v, (u8 *)x + 0xF0, (u8 *)y + 0x70, &c);
                }
            }
        }
    }
    if (x->v.z <= f20) {
        x->v.z = f20;
        x->fBC = 0;
        y->f50 = 0.0f;
    } else {
        x->fBC = 1;
        if (y->pC != 0) {
            y->f78 = y->f78 - y->f50;
        } else {
            x->v.z = x->v.z - y->f50;
        }
        y->f50 += 0.0027222223f;
        r = (y->f50 > 0.3f) ? 0.3f : y->f50;
        y->f50 = r;
    }
}
/* localdecomp:end func_00301710 */
