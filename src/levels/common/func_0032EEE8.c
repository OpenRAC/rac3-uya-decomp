#include "common.h"

/* localdecomp:start func_0032EEE8 */
typedef int Q_32EEE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_32EEE8;
typedef struct { V_32EEE8 m[3]; } M_32EEE8;
typedef struct {
    u8 pad[0x10];
    f32 f10;
} R_32EEE8;
typedef struct {
    u8 pad[0x10];
    V_32EEE8 v10;
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x20 - 0x16];
} T_32EEE8;
typedef struct {
    u8 pad[0x20];
    V_32EEE8 v20;
    u8 pad30[0x64 - 0x30];
} Dummy_32EEE8;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 pad21[0xC0 - 0x21];
    M_32EEE8 mC0;
} Dummy2_32EEE8;
typedef struct {
    u8 pad[0x10];
    V_32EEE8 v10;
    u8 b20;
    u8 pad21[0xC0 - 0x21];
    M_32EEE8 mC0;
    u8 pad_f[0x68 - 0x64];
} Dummy3_32EEE8;
typedef struct {
    u8 pad[0x10];
    V_32EEE8 v10;
    u8 pad20[0x20 - 0x20];
} Dummy4_32EEE8;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0xE0 - 0x36];
    M_32EEE8 mE0;
} Tg_32EEE8;
typedef struct {
    u8 pad0[0x64];
    Tg_32EEE8 *f64;
} E_32EEE8;
typedef struct {
    u8 pad0[0x10];
    V_32EEE8 v10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    E_32EEE8 *f68;
    u8 pad6C[0xC0 - 0x6C];
    M_32EEE8 mC0;
} O_32EEE8;
extern R_32EEE8 *func_00440728(Tg_32EEE8 *);
extern void func_004C41E8(V_32EEE8 *, V_32EEE8 *);
extern void func_0040BE90(f32, V_32EEE8 *, M_32EEE8 *);
extern void func_00437698(O_32EEE8 *, s32, V_32EEE8 *);
extern void func_0040C920(M_32EEE8 *, M_32EEE8 *);
extern void func_0040C2D0(void *, V_32EEE8 *, M_32EEE8 *);
void func_0032EEE8(O_32EEE8 *o) {
    E_32EEE8 *e = o->f68;
    R_32EEE8 *r;
    V_32EEE8 a, t10, t20, t30;
    M_32EEE8 t40;
    Q_32EEE8 x, y, z, w;
    r = func_00440728(e->f64);
    func_004C41E8(&o->v10, &t10);
    a = *(V_32EEE8 *)((u8 *)e->f64 + 0x10);
    if (r != 0) {
        func_0040BE90(r->f10, &t30, &e->f64->mE0);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t30));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    }
    if (e->f64 == 0 || e->f64->b20 == 0xFE || e->f64->b20 == 0xFD || (e->f64->h34 & 0x1000) == 0) {
        o->b20 = 3;
        e->f64 = 0;
    } else {
        func_00437698(o, 0, &t20);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t20));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t30) : "j"(x));
        func_0040C920(&t40, &o->mC0);
        func_0040C2D0((u8 *)e + 0x20, &t30, &t40);
    }
}
/* localdecomp:end func_0032EEE8 */
