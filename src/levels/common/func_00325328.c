#include "common.h"

/* localdecomp:start func_00325328 */
typedef int Q_325328 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_325328;
typedef struct {
    u8 pad0[0x10];
    V4_325328 pos;
    u8 pad20[0x4C];
    s32 f6C;
} S_325328;
typedef struct {
    u8 pad0[0x80];
    Q_325328 f80;
    Q_325328 f90;
    u8 padA0[0x25E4 - 0xA0];
    u8 f25E4;
    u8 pad25E5[0xB];
    u8 f25F0;
} G_325328;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x44];
    s32 f6C;
    u8 pad70[6];
    s16 f76;
    u8 pad78[0x1C];
    s32 f94;
    s16 f98;
    u8 pad9A[4];
    s16 f9E;
} H_325328;
extern G_325328 D_001A4BE0;
extern H_325328 D_001CCFD0;
extern u8 D_001D5469;
extern s32 D_001DE35C;
extern f32 func_003E4B30(f32);
extern f32 func_003E4B48(f32);
extern f32 func_003E5630(f32, f32);
extern f32 func_003E5678(f32, f32);
extern void func_003DB8F0(s32);
extern void func_004BEAD0(s32);
extern void func_004C5F00(V4_325328 *, V4_325328 *, s32, s32);
extern void func_0047D488(s32, s32, void *);
extern void func_003C1828(s32, V4_325328 *, V4_325328 *, s32, s32, s32);
extern void func_003C1740(s32, V4_325328 *);
extern void func_003C17B0(s32, V4_325328 *);
extern void func_00419630(void *, s32, s32, s32);
extern void func_004DBE08(s32, s32, f32);
extern void func_00433678(s32, s32);
extern void func_00432180(void);
void func_00325328(u8 *o) {
    V4_325328 a;
    V4_325328 b;
    V4_325328 c;
    V4_325328 d;
    S_325328 *s = *(S_325328 **)(o + 0x68);
    G_325328 *g;
    f32 z;
    Q_325328 x, y;
    a.x = func_003E4B30(s->pos.w) * 2.5f;
    a.y = func_003E4B48(s->pos.w) * 2.5f;
    a.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->pos));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    __asm__("sq $0, %0" : "=m"(b));
    b.z = func_003E5630(s->pos.w, 3.1415927f);
    func_003DB8F0(10);
    g = &D_001A4BE0;
    if (g->f25E4 == 3) {
        func_004BEAD0(0);
    }
    func_004C5F00(&a, &b, 0x74, 0);
    func_0047D488(0, 0, o);
    c.x = func_003E4B30(s->pos.w) * 1.25f;
    c.y = func_003E4B48(s->pos.w) * 1.25f;
    c.z = 0.0f;
    c.x += func_003E4B30(func_003E5630(s->pos.w, 1.5707964f)) * 4.0f;
    c.y += func_003E4B48(func_003E5630(s->pos.w, 1.5707964f)) * 4.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s->pos));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
    z = c.z;
    __asm__("sq $0, %0" : "=m"(d));
    c.z = z + 1.0f;
    d.z = func_003E5678(s->pos.w, 1.5707964f);
    func_003C1828(0, &c, &d, 1, 0, 0);
    func_003C1740(0, &c);
    func_003C17B0(0, &d);
    *(Q_325328 *)(o + 0x10) = g->f80;
    *(Q_325328 *)(o + 0xF0) = g->f90;
    if (o[0x43] != 1) {
        func_00419630(o, 1, 0, 0);
    }
    func_004DBE08(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(o + 0x34) |= 0x8000;
    }
    g->f25F0 = 1;
    D_001DE35C = 1;
    o[0x20] = 2;
    s->f6C = 0x3C;
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
        func_00433678(0xEB8, 0);
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 7000) {
        func_00432180();
    }
}
/* localdecomp:end func_00325328 */
