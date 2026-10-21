#include "common.h"

/* localdecomp:start func_003E8B30 */
typedef int Q_3E8B30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E8B30;
typedef struct {
    V4_3E8B30 v0;
    V4_3E8B30 v10;
    V4_3E8B30 v20;
    V4_3E8B30 v30;
    V4_3E8B30 v40;
    u8 pad50[0x94 - 0x50];
    s32 f94;
} O_3E8B30;
typedef struct {
    u8 pad0[0x40];
    V4_3E8B30 v40;
    u8 pad50[0xF0 - 0x50];
    u8 *fF0;
    u8 padF4[0x12B - 0xF4];
    u8 f12B;
    u8 pad12C[0x460 - 0x12C];
} A_3E8B30;
typedef struct {
    u8 pad0[0x54];
    s32 f54;
    u8 pad58[0x460 - 0x58];
} B_3E8B30;
extern A_3E8B30 D_001E2C10[];
extern B_3E8B30 D_001E2AC0[];
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
void func_003E8B30(O_3E8B30 *o) {
    A_3E8B30 *a;
    V4_3E8B30 v, w;
    V4_3E8B30 *q;
    void *p;
    Q_3E8B30 x, y, z;
    a = &D_001E2C10[o->f94];
    func_0040C0F0(&v, a->fF0 + 0xE0, 1.0f);
    if (a->f12B == 2) {
        func_0040BE90(&w, &v, 3.75f);
    } else if (a->f12B == 1) {
        func_0040BE90(&w, &v, 0.75f);
    } else {
        func_0040BE90(&w, &v, 1.6f);
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->v40));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v30) : "j"(z));
    q = &o->v10;
    p = (void *)((B_3E8B30 *)(o->f94 * 0x460 + (s32)D_001E2AC0))->f54;
    o->v20 = v;
    func_0040BF20(q, p, &v);
    func_0040C0F0(q, q, 1.0f);
    func_0040BF20(o, &v, q);
    o->v40 = o->v0;
}
/* localdecomp:end func_003E8B30 */
