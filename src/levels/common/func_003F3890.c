#include "common.h"

typedef int Q_3F3890 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_3F3890;
typedef struct {
    u8 pad0[0x80];
    V_3F3890 pos;
    V_3F3890 rot;
    u8 padA0[0x2544];
    u8 b25E4;
    u8 pad25E5[0xB];
    u8 b25F0;
} G_3F3890;
typedef struct {
    u8 pad0[0x24];
    s32 i24;
    u8 pad28[0x44];
    s32 i6C;
    u8 pad70[0x24];
    s32 i94;
} H_3F3890;

extern G_3F3890 D_001A4BE0;
extern H_3F3890 D_001CCFD0;
extern u8 D_001D5469;
extern s32 D_001DF7DC;
extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern f32 func_0041D7E0(f32, f32);
extern f32 func_0041D828(f32, f32);
extern void func_00413950(s32);
extern void func_004F8788(s32);
extern void func_004FF7F0(V_3F3890 *, V_3F3890 *, s32, s32);
extern void func_003FB8A8(s32, V_3F3890 *, V_3F3890 *, s32, s32, s32);
extern void func_003FB748(s32, V_3F3890 *);
extern void func_003FB7B8(s32, V_3F3890 *);
extern void func_00451098(u8 *, s32, s32, s32);
extern void func_005160A8(s32, s32, f32);
extern void func_0046C888(s32, s32);
extern void func_004513D8(u8 *, s32, s32);

void func_003F3890(u8 *o) {
    V_3F3890 *s;
    V_3F3890 a, b, c, d;
    Q_3F3890 x, y;
    G_3F3890 *g;

    s = *(V_3F3890 **)(o + 0x68);
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    a.x = func_0041CCE0(s[1].x) * 2.5f;
    a.y = func_0041CCF8(s[1].x) * 2.5f;
    a.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s[0]));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    __asm__("sq $0, %0" : "=m"(b));
    b.z = func_0041D7E0(s[1].x, 3.1415927f);
    func_00413950(10);
    g = &D_001A4BE0;
    if (g->b25E4 == 3) {
        func_004F8788(0);
    }
    func_004FF7F0(&a, &b, 0x74, 0);
    c.x = func_0041CCE0(s[1].x) * 1.25f;
    c.y = func_0041CCF8(s[1].x) * 1.25f;
    c.z = 0.0f;
    c.x += func_0041CCE0(func_0041D7E0(s[1].x, 1.5707964f)) * 4.0f;
    c.y += func_0041CCF8(func_0041D7E0(s[1].x, 1.5707964f)) * 4.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(s[0]));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
    {
        f32 z = c.z;
        __asm__("sq $0, %0" : "=m"(d));
        c.z = z + 1.0f;
    }
    d.z = func_0041D828(s[1].x, 1.5707964f);
    func_003FB8A8(0, &c, &d, 1, 0, 0);
    func_003FB748(0, &c);
    func_003FB7B8(0, &d);
    *(V_3F3890 *)(o + 0x10) = g->pos;
    *(V_3F3890 *)(o + 0xF0) = g->rot;
    if (o[0x43] != 1) {
        func_00451098(o, 1, 0, 0);
    }
    func_005160A8(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(o + 0x34) |= 0x8000;
    }
    g->b25F0 = 1;
    D_001DF7DC = 1;
    *(s16 *)((u8 *)s + 0x1C) = 0x3C;
    if (D_001CCFD0.i6C == 0 && D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
        func_0046C888(0xEB8, 0);
    }
    func_004513D8(o, 3, -1);
}
