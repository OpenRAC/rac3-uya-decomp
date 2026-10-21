#include "common.h"

typedef int Q_318428 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_318428;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    s32 f18;
    s32 f1C;
    f32 f20;
    u8 pad24[0xC];
} S_318428;

extern S_318428 D_002725C0[];
extern u8 D_1A4BE0[];
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_004C41E8(void *, void *);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);

/* localdecomp:start func_00318428 */
void func_00318428(s32 a0) {
    S_318428 *e = D_002725C0;
    u8 *g = D_1A4BE0;
    V_318428 t;
    V_318428 t2;
    V_318428 t3;
    Q_318428 x, y;
    do {
        if (e->f1C == 0) {
            e->f1C = a0;
            e->f10 = func_00440978();
            e->f14 = func_00440918(1200.0f, 1400.0f) * 0.017453292f * 0.016666668f;
            e->f18 = 0x25;
            e->f20 = func_004408C0(0.3f, 0.4f);
            func_004C41E8(*(u8 **)(g + 0x25C0) + 0x10, &t);
            *(Q_318428 *)&t2 = *(Q_318428 *)(*(u8 **)(g + 0x25C0) + 0x10);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t2));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t3) : "j"(x));
            func_0040BF20(&t2, &t2, &t3);
            func_0040C0F0(e, &t2, e->f20);
            return;
        }
        e++;
    } while ((s32)e < (s32)(D_002725C0 + 12));
}
/* localdecomp:end func_00318428 */
