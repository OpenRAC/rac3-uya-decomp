#include "common.h"

/* localdecomp:start func_00365E58 */
typedef int Q_365E58 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_365E58;
typedef struct {
    u8 pad0[0xC0];
    V4_365E58 vC0;
    u8 pad_D0[0x20];
    V4_365E58 vF0;
} O_365E58;
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
} G_365E58;
extern s32 D_001E1CC0;
extern s32 D_001E1CD0;
extern V4_365E58 D_001A4C60;
extern void func_0040C638(void *, void *);
extern void func_00437600(void *, s32, void *);
extern f32 func_0040BFB0(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_00365E58(O_365E58 *o) {
    V4_365E58 sv[4];
    Q_365E58 x, y, z, x2, y2;
    G_365E58 *g;
    func_0040C638(&o->vC0, &o->vF0);
    func_00437600(o, 0, sv);
    *(Q_365E58 *)&D_001E1CC0 = *(Q_365E58 *)&sv[3];
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(sv[1]));
    __asm__("vsub.xyz %0, vf0, %1" : "=j"(x) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(D_001E1CD0) : "j"(x));
    if (func_0040BFB0(&D_001E1CC0, &D_001A4C60) > 5.0f) {
        g = (G_365E58 *)((u8 *)&D_001A4C60 - 0x80);
        func_0040BE90(&D_001E1CC0, g->p25C0 + 0xE0, 1.5f);
        __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(D_001E1CC0));
        __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(D_001A4C60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x2), "j"(y2));
        __asm__("sqc2 %1, %0" : "=m"(D_001E1CC0) : "j"(z));
        *(Q_365E58 *)&D_001E1CD0 = *(Q_365E58 *)(g->p25C0 + 0xC0);
    }
}
/* localdecomp:end func_00365E58 */
