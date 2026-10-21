#include "common.h"

/* localdecomp:start func_003B2C18 */
typedef int Q_3B2C18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3B2C18;
typedef struct { u8 pad0[0x20]; V_3B2C18 f20; u8 pad30[0x4C]; s32 f7C; } S_3B2C18;
typedef struct {
    u8 pad0[0x10];
    Q_3B2C18 f10;
    u8 f20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0xD];
    u8 f43;
    u8 pad44[0x24];
    S_3B2C18 *f68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x54];
    Q_3B2C18 fF0;
} O_3B2C18;
typedef struct {
    u8 pad0[0x80];
    Q_3B2C18 f80;
    Q_3B2C18 f90;
    u8 padA0[0x25E4 - 0xA0];
    u8 f25E4;
    u8 pad25E5[0xB];
    u8 f25F0;
} G_3B2C18;
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
} H_3B2C18;
extern G_3B2C18 D_001A4BE0;
extern H_3B2C18 D_001CCFD0;
extern u8 D_001D5469;
extern s32 D_001DE35C;
extern void func_00411078(O_3B2C18 *o);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern f32 func_003E5630(f32 a, f32 b);
extern f32 func_003E5678(f32 a, f32 b);
extern void func_003DB8F0(s32 a);
extern void func_004BEAD0(s32 a);
extern void func_004C5F00(V_3B2C18 *a, V_3B2C18 *b, s32 c, s32 d);
extern void func_0047D488(s32 a, s32 b, O_3B2C18 *o);
extern void func_003C1828(s32 a, V_3B2C18 *b, V_3B2C18 *c, s32 d, s32 e, s32 f);
extern void func_003C1740(s32 a, V_3B2C18 *b);
extern void func_003C17B0(s32 a, V_3B2C18 *b);
extern void func_00419630(O_3B2C18 *o, s32 a, s32 b, s32 c);
extern void func_004DBE08(s32 a, s32 b, f32 c);
extern void func_00433678(s32 a, s32 b);
extern void func_00432180(H_3B2C18 *h);

void func_003B2C18(O_3B2C18 *o) {
    V_3B2C18 a;
    V_3B2C18 b;
    V_3B2C18 c;
    V_3B2C18 d;
    Q_3B2C18 q1, q2;
    f32 z;
    S_3B2C18 *s;
    o->f98 = 0;
    s = o->f68;
    func_00411078(o);
    a.x = func_003E4B30(s->f20.w) * 2.5f;
    a.y = func_003E4B48(s->f20.w) * 2.5f;
    a.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(s->f20));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q1));
    __asm__("sq $0, %0" : "=m"(b));
    b.z = func_003E5630(s->f20.w, 3.1415927f);
    func_003DB8F0(10);
    if (D_001A4BE0.f25E4 == 3) {
        func_004BEAD0(0);
    }
    func_004C5F00(&a, &b, 0x74, 0);
    func_0047D488(0, 0, o);
    c.x = func_003E4B30(s->f20.w) * 1.25f;
    c.y = func_003E4B48(s->f20.w) * 1.25f;
    c.z = 0.0f;
    c.x += func_003E4B30(func_003E5630(s->f20.w, 1.5707964f)) * 4.0f;
    c.y += func_003E4B48(func_003E5630(s->f20.w, 1.5707964f)) * 4.0f;
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(c));
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(s->f20));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(q1));
    z = c.z;
    __asm__("sq $0, %0" : "=m"(d));
    c.z = z + 1.0f;
    d.z = func_003E5678(s->f20.w, 1.5707964f);
    func_003C1828(0, &c, &d, 1, 0, 0);
    func_003C1740(0, &c);
    func_003C17B0(0, &d);
    o->f10 = D_001A4BE0.f80;
    o->fF0 = D_001A4BE0.f90;
    if (o->f43 != 1) {
        func_00419630(o, 1, 0, 0);
    }
    func_004DBE08(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        o->f34 |= 0x8000;
    }
    D_001A4BE0.f25F0 = 1;
    D_001DE35C = 1;
    o->f20 = 2;
    s->f7C = 0x3C;
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
        func_00433678(0xEB8, 0);
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
        func_00432180(&D_001CCFD0);
    }
}
/* localdecomp:end func_003B2C18 */
