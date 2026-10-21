#include "common.h"

/* localdecomp:start func_003A6B00 */
typedef int Q_3A6B00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A6B00;
typedef struct {
    u8 pad0[0x10];
    V4_3A6B00 pos;
    u8 pad20[0x8A];
    s16 hAA;
    u8 padAC[0x14];
    V4_3A6B00 mC0[3];
    V4_3A6B00 rot;
} M_3A6B00;
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    M_3A6B00 *mDC;
} E_3A6B00;
typedef struct {
    u8 pad0[8];
    s32 i8;
    u8 padC[4];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0xC];
    s32 i40;
    s32 i44;
    s32 i48;
    s32 i4C;
    s32 i50;
    s32 i54;
    s32 i58;
    u8 pad5C[4];
    f32 f60;
    u8 pad64[4];
    s32 i68;
    u8 pad6C[4];
    V4_3A6B00 q70;
    V4_3A6B00 q80;
    V4_3A6B00 m90;
    V4_3A6B00 mA0;
    V4_3A6B00 mB0;
    u8 padC0[0x10];
    s32 iD0;
} D_3A6B00;
extern M_3A6B00 *D_001E009C;
extern u8 D_001A30B0[];
extern void func_003A68C0(M_3A6B00 *, D_3A6B00 *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BF38(void *);
extern void func_004459B0(void *, f32, f32, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_0040CEC8(f32, f32);
extern void func_0040C638(void *, void *);
extern f32 func_0040C018(void *, void *);
extern s32 func_004A7200(s32, s32, M_3A6B00 *);
extern s32 func_004A6D20(M_3A6B00 *, s32);
extern void func_004A6E88(s32);
extern void func_00439610(M_3A6B00 *);
#define KILL_3A6B00(fld) { \
    s32 k = (fld); \
    if (k != -1) { \
        E_3A6B00 *e = (E_3A6B00 *)(D_001A30B0 + (k << 7)); \
        if (e->mDC == m && e->bD0 != 0) func_004A6E88(k); \
    } \
    (fld) = -1; \
}
void func_003A6B00(M_3A6B00 *obj, D_3A6B00 *d) {
    V4_3A6B00 save0;
    V4_3A6B00 save1;
    V4_3A6B00 t20;
    V4_3A6B00 t30;
    V4_3A6B00 t40;
    Q_3A6B00 x, y;
    M_3A6B00 *m;
    s32 rot;
    s32 changed;
    f32 len;
    f32 f;
    V4_3A6B00 *tgt;
    V4_3A6B00 *pos;

    save0 = obj->pos;
    save1 = obj->rot;
    func_003A68C0(obj, d);
    m = &D_001E009C[d->i8];
    if (d->f10 != 0.0f || d->f14 != 0.0f || d->f18 != 0.0f) {
        if (d->f28 != 0.0f || d->f2C != 0.0f || d->f30 != 0.0f) rot = 1; else rot = 0;
        tgt = &d->q70;
        t20 = *tgt;
        if (d->i68 != 0) {
            func_0040BE90(&t40, &d->m90, d->f10);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t40));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t20));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(t20) : "j"(y));
            func_0040BE90(&t40, &d->mA0, d->f14);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t40));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t20));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(t20) : "j"(y));
            func_0040BE90(&t40, &d->mB0, d->f18);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t20));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t40));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(t20) : "j"(y));
        }
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t20));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(t40) : "j"(y));
        pos = &obj->pos;
        len = func_0040BF38(&t40);
        func_004459B0(&d->f60, len, d->f20 * 0.00027777778f, d->f24 * 0.00027777778f, d->f1C * 0.016666668f);
        func_0040C0F0(&t40, &t40, d->f60);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t40));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(y));
        if (rot) {
            t40.x = d->f10;
            t40.y = d->f14;
            t40.z = d->f18;
            len = func_0040BF38(&t40);
            f = func_0040BFB0(pos, tgt) / len;
            obj->rot.x = func_0040CEC8(d->q80.x, d->f28 * f * 0.017453292f);
            obj->rot.y = func_0040CEC8(d->q80.y, d->f2C * f * 0.017453292f);
            obj->rot.z = func_0040CEC8(d->q80.z, d->f30 * f * 0.017453292f);
            func_0040C638(obj->mC0, &obj->rot);
        }
    } else {
        rot = 1;
        t30 = d->q80;
        if (d->i68 != 0) {
            t30.x += d->f28;
            t30.y += d->f2C;
            t30.z += d->f30;
        }
    }
    changed = 0;
    if ((rot && func_0040C018(&save1, &obj->rot) > 3.0461741573617473e-08f)
        || func_0040C018(&save0, &obj->pos) > 1.0000001111620804e-06f) {
        changed = 1;
    }
    if (changed) {
        if (m->hAA == 0x1C28 && d->i58 == 0) {
            s32 k = d->iD0;
            E_3A6B00 *e;
            if (k == -1 || (e = (E_3A6B00 *)(D_001A30B0 + (k << 7)), e->mDC != m) || e->bD0 == 0) {
                d->iD0 = func_004A7200(0, 4, m);
            }
        }
        m->pos = obj->pos;
        if (rot) {
            m->rot = obj->rot;
            func_0040C638(m->mC0, &m->rot);
        }
        func_00439610(m);
        if (*(long *)&d->i48 == 0) {
            return;
        }
        if (d->i68 != 0) {
            if (d->i40 >= 0 && d->i48 != 0 && func_004A6D20(m, d->i50) == 0) {
                d->i50 = func_004A7200(d->i40, 4, m);
            }
            KILL_3A6B00(d->i54);
        } else {
            if (d->i44 >= 0 && d->i4C != 0 && func_004A6D20(m, d->i54) == 0) {
                d->i54 = func_004A7200(d->i44, 4, m);
            }
            KILL_3A6B00(d->i50);
        }
    } else {
        KILL_3A6B00(d->i54);
        KILL_3A6B00(d->i50);
        KILL_3A6B00(d->iD0);
    }
}
/* localdecomp:end func_003A6B00 */
