#include "common.h"

/* localdecomp:start func_003C1620 */
typedef int Q_3C1620 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C1620;
typedef struct {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    V4_3C1620 v180;
    V4_3C1620 v190;
    V4_3C1620 v1A0;
    V4_3C1620 v1B0;
    u8 pad1C0[0x1C4 - 0x1C0];
    f32 f1C4;
    u8 pad1C8[0x1D0 - 0x1C8];
    s32 i1D0;
} M_3C1620;
typedef struct {
    u8 pad0[0x10];
    V4_3C1620 pos;
    u8 pad20[0x68 - 0x20];
    M_3C1620 *m;
} O_3C1620;
typedef struct {
    u8 pad0[0x18];
    s32 i18;
} G_3C1620;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} R_3C1620;
extern u8 D_001A4BE0[];
extern G_3C1620 D_001EAA80;
extern V4_3C1620 D_001EAAA0;
extern R_3C1620 *func_00440728(s32);
extern f32 func_0040C018(V4_3C1620 *, V4_3C1620 *);
extern s32 func_003F8448(V4_3C1620 *, V4_3C1620 *, s32, O_3C1620 *, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BF68(V4_3C1620 *);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040BFE8(V4_3C1620 *, V4_3C1620 *);

void func_003C1620(O_3C1620 *obj, f32 minDist) {
    V4_3C1620 pos;
    V4_3C1620 tgt;
    V4_3C1620 off;
    V4_3C1620 diff;
    V4_3C1620 diff2;
    M_3C1620 *m;
    R_3C1620 *r;
    G_3C1620 *g;
    u8 *b;
    f32 angle, yaw, len, a, d2, t;
    Q_3C1620 va, vb;

    m = obj->m;
    *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&m->v190;
    *(Q_3C1620 *)&pos = *(Q_3C1620 *)&obj->pos;
    *(Q_3C1620 *)&tgt = *(Q_3C1620 *)&m->v190;
    pos.z += m->f38;
    tgt.z += m->f38;
    r = func_00440728(m->i1D0);
    b = D_001A4BE0;
    if (m->i1D0 == *(s32 *)(b + 0x25C0)) {
        *(Q_3C1620 *)&tgt = *(Q_3C1620 *)(b + 0xD0);
    } else if (r != 0) {
        tgt.z += r->f10;
    }
    if (func_0040C018(&pos, &tgt) >= 3600.0f) {
        return;
    }
    if (func_003F8448(&pos, &tgt, 16, obj, 0) == 0) {
        return;
    }
    g = &D_001EAA80;
    if (g->i18 != 0 && g->i18 == m->i1D0) {
        return;
    }
    for (angle = 10.0f; angle <= 160.0f; angle += 10.0f) {
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(tgt));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(pos));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(va) : "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(diff) : "j"(va));
        yaw = func_0040C490(diff.x, diff.y);
        len = func_0040BF68(&diff);
        if (len < minDist) {
            len = minDist;
        }

        a = angle * 0.017453292f;
        off.x = func_0040C3C8(func_0040CEC8(a, yaw)) * len;
        off.y = func_0040C3E0(func_0040CEC8(a, yaw)) * len;
        off.z = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(off));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(va) : "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(off) : "j"(va));
        if (off.x < 0.0f) {
            off.x = 0.5f;
        }
        if (off.y < 0.0f) {
            off.y = 0.5f;
        }
        if (off.z < 0.0f) {
            off.z = 0.5f;
        }
        if (func_003F8448(&pos, &off, 16, obj, 0) == 0) {
            *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&off;
            return;
        }
        if (D_001EAA80.i18 != 0 && D_001EAA80.i18 == m->i1D0) {
            *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&off;
        }
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(va) : "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(diff2) : "j"(va));
        d2 = func_0040BF68(&diff2);
        if (m->f1C4 < d2 && angle < 60.0f) {
            t = func_0040BFE8(&D_001EAAA0, &m->v190);
            if (t < func_0040BFE8(&m->v1B0, &m->v190)) {
                m->f1C4 = d2;
                *(Q_3C1620 *)&m->v1B0 = *(Q_3C1620 *)&D_001EAAA0;
            }
        }

        a = -(angle * 0.017453292f);
        off.x = func_0040C3C8(func_0040CEC8(a, yaw)) * len;
        off.y = func_0040C3E0(func_0040CEC8(a, yaw)) * len;
        off.z = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(off));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(va) : "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(off) : "j"(va));
        if (off.x < 0.0f) {
            off.x = 0.5f;
        }
        if (off.y < 0.0f) {
            off.y = 0.5f;
        }
        if (off.z < 0.0f) {
            off.z = 0.5f;
        }
        if (func_003F8448(&pos, &off, 16, obj, 0) == 0) {
            *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&off;
            return;
        }
        if (D_001EAA80.i18 != 0 && D_001EAA80.i18 == m->i1D0) {
            *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&off;
        }
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(va) : "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(diff2) : "j"(va));
        d2 = func_0040BF68(&diff2);
        if (m->f1C4 < d2 && angle < 60.0f) {
            m->f1C4 = d2;
            *(Q_3C1620 *)&m->v1B0 = *(Q_3C1620 *)&D_001EAAA0;
        }
    }
    *(Q_3C1620 *)&m->v180 = *(Q_3C1620 *)&m->v1B0;
}
/* localdecomp:end func_003C1620 */
