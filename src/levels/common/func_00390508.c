#include "common.h"

/* localdecomp:start func_00390508 */
typedef int Q_390508 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_390508;
typedef struct {
    u8 pad[0x10];
    f32 f10;
    f32 f14;
    s32 f18;
    void *f1C;
    f32 f20;
    u8 pad2[0xC];
} E_390508;
typedef struct {
    u8 pad[0x18];
    u8 *f18;
} B_390508;
typedef struct {
    u8 pad[0x10];
    V4_390508 v10;
    u8 pad2[0x48];
    B_390508 *f68;
} O_390508;
extern E_390508 D_0029F020[];
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
void func_00390508(O_390508 *obj) {
    E_390508 *p;
    s32 i;
    B_390508 *b;
    V4_390508 t0;
    V4_390508 t10;
    V4_390508 t20;
    Q_390508 q1, q2, q3;
    b = obj->f68;
    for (i = 0; i < 12; i++) {
        p = &D_0029F020[i];
        if (p->f1C == 0) {
            p->f1C = obj;
            p->f10 = func_00440978();
            p->f14 = func_00440918(1200.0f, 1400.0f) * 0.017453292f * 0.016666668f;
            p->f18 = 37;
            p->f20 = func_004408C0(0.3f, 0.4f);
            func_0040C0F0(&t0, b->f18 + 0xD0, 1.0f);
            t10 = obj->v10;
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(t10));
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(t0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(t20) : "j"(q3));
            func_0040BF20(&t10, &t10, &t20);
            func_0040C0F0(p, &t10, p->f20);
            return;
        }
    }
}
/* localdecomp:end func_00390508 */
