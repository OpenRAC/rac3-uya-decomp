#include "common.h"

/* localdecomp:start func_00366900 */
typedef int Q_366900 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_366900;
typedef struct {
    u8 pad[0x10];
    s32 f10;
} N_366900;
typedef struct {
    u8 pad[0x24];
    N_366900 *f24;
    u8 pad28[0x98 - 0x28];
    s32 f98;
} C_366900;
typedef struct {
    u8 pad[0x25C0];
    C_366900 *f25C0;
} G_366900;
extern G_366900 D_001A4BE0;
extern V_366900 D_001EAAA0;
extern s32 D_001D545C;
extern void func_0040BE90(f32, V_366900 *, V_366900 *);
extern void func_00409940(V_366900 *, V_366900 *);
extern void func_00439610(C_366900 *);
extern void func_003F15C8(s32);
extern void func_003F15F0(s32);
extern s32 func_003F8448(V_366900 *, V_366900 *, s32, s32, s32);
void func_00366900(V_366900 *o, V_366900 *b, V_366900 *out) {
    V_366900 a;
    Q_366900 x, y;
    f32 k = 40.0f;
    if (D_001D545C == 11) {
        k = 80.0f;
    }
    func_0040BE90(k, &a, b);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*o));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    func_00409940(o, &a);
    D_001A4BE0.f25C0->f98 = 0;
    func_00439610(D_001A4BE0.f25C0);
    func_003F15C8(0);
    if (func_003F8448(o, &a, 0, 0, 0) != 0) {
        *out = D_001EAAA0;
    } else {
        *out = a;
    }
    D_001A4BE0.f25C0->f98 = D_001A4BE0.f25C0->f24->f10;
    func_00439610(D_001A4BE0.f25C0);
    func_003F15F0(0);
}
/* localdecomp:end func_00366900 */
