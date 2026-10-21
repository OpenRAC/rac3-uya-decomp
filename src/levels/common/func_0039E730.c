#include "common.h"

/* localdecomp:start func_0039E730 */
typedef int Q_39E730 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_39E730;
typedef struct { f32 x, y, z; } P_39E730;
typedef struct { f32 u, v; } T_39E730;
typedef struct { u8 pad0[8]; f32 f8; f32 fC; f32 f10; u8 f14; u8 f15; u8 f16; } S_39E730;
typedef struct { u8 pad0[0x10]; V_39E730 f10; u8 pad20[0x48]; S_39E730 *f68; } O_39E730;
extern P_39E730 D_002A16D0[];
extern u32 D_002A1928[];
extern T_39E730 D_002A19F0[];
extern void func_003DE098(O_39E730 *o);
extern s32 func_003DABB0(s32 a);
extern void func_004980C0(s32 a, unsigned long b);
extern f32 func_003E56C0(f32 a);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern void func_003DF5BC(s32 n, P_39E730 *v, u32 *c, T_39E730 *t, s32 a);
extern void func_003E14D8(V_39E730 *v, s32 a, u32 c, s32 b, f32 x, f32 y, f32 z);

void func_0039E730(O_39E730 *o, s32 mode) {
    S_39E730 *s = o->f68;
    V_39E730 base;
    V_39E730 tmp;
    V_39E730 p;
    Q_39E730 q1, q2;
    f32 z, step, w, r0, dr, t, r, h, ang;
    s32 i, j, k, done;
    u32 col;
    func_003DE098(o);
    func_004980C0(6, func_003DABB0(0x17));
    func_004980C0(0x14, 0xFF9000000260UL);
    func_004980C0(8, 0);
    func_004980C0(0x42, 0x4000000044UL);
    base = o->f10;
    z = s->f8 - 0.5f;
    if (z < 0.0f) {
        z = 0.0f;
    }
    done = 0;
    i = 0;
    z *= 3.0f;
    base.z += z;
    step = 0.0500000007f;
    w = 0.200000003f;
    r0 = s->fC * -0.799999952f + 0.899999976f;
    t = -step;
    if (mode != 0) {
        w = 0.0400000028f;
    }
    dr = 0.100000001f - r0;
    for (;;) {
        t += step;
        if (s->f8 <= t) {
            t = s->f8;
            done = 1;
        }
        r = r0 + dr * t;
        h = t * 3.0f;
        ang = func_003E56C0(s->f10 + t * 25.1327419f);
        *(Q_39E730 *)&p = 0;
        p.x = func_003E4B30(ang) * r;
        p.y = func_003E4B48(ang) * r;
        p.z = h;
        tmp = p;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(base));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(p) : "j"(q1));
        D_002A16D0[i].z = p.z + w;
        D_002A16D0[i + 1].x = p.x;
        D_002A16D0[i + 1].y = p.y;
        D_002A16D0[i + 1].z = p.z - w;
        D_002A16D0[i].x = p.x;
        D_002A16D0[i].y = p.y;
        j = i + 1;
        if (mode != 0) {
            col = ((s32)(t / s->f8 * 127.0f) << 24) | 0xFFFFFF;
            D_002A1928[i + 1] = col;
            D_002A1928[i] = col;
        } else {
            col = ((s32)(t / s->f8 * 128.0f) << 24) | (s->f16 << 16) | (s->f15 << 8) | s->f14;
            D_002A1928[j] = col;
            D_002A1928[i] = col;
        }
        i += 2;
        if (done != 0 || i >= 0x28) {
            break;
        }
    }
    for (k = 0; k < i; k++) {
        D_002A19F0[k].u = k / 2;
        D_002A19F0[k].v = !(k & 1) ? 1.0f : 0.0f;
    }
    func_003DF5BC(i, D_002A16D0, D_002A1928, D_002A19F0, 1);
    *(Q_39E730 *)&p = 0;
    p.x = D_002A16D0[i - 1].x;
    p.y = D_002A16D0[i - 1].y;
    p.z = D_002A16D0[i - 1].z + w;
    tmp = p;
    if (mode != 0) {
        func_003E14D8(&tmp, 0x31, 0x7FFFFFFF, 1, 0.300000012f, 0.0799999982f, 0.785398185f);
    } else {
        func_003E14D8(&tmp, 0x31, 0x40000000 | (s->f16 << 16) | (s->f15 << 8) | s->f14, 1, 0.75f, 0.0799999982f, 0.0f);
    }
    func_004980C0(0x47, 0x5360B);
}
/* localdecomp:end func_0039E730 */
