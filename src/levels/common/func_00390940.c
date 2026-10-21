#include "common.h"

/* localdecomp:start func_00390940 */
typedef int Q_390940 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_390940;
typedef struct {
    V4_390940 pos;
    V4_390940 vel;
    u8 pad20[8];
    f32 f28;
    f32 f2C;
    s32 i30;
    s32 i34;
    u8 pad38[4];
    s32 i3C;
    s32 i40;
    s32 i44;
    u8 pad48[8];
} E_390940;
typedef struct {
    s32 cnt;
    u8 pad4[0x14];
    u8 *f18;
} Q2_390940;
extern E_390940 D_0029F260[];
extern f32 func_0040CEC8(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_0040BA90(void *);

void func_00390940(u8 *owner) {
    V4_390940 tmp;
    Q_390940 qa, qb, qr, qc, qd, qs;
    s32 i;
    Q2_390940 *q = *(Q2_390940 **)(owner + 0x68);
    for (i = 0; i < 128; i++) {
        E_390940 *e = &D_0029F260[i];
        if (e->i44 == (s32)owner) {
            e->i34 = (s32)((f32)e->i30 * ((f32)e->i3C / (f32)e->i40));
            e->f2C = func_0040CEC8(e->f2C, e->f28);
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(e->pos));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(e->vel));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qa));
            __asm__("sqc2 %1, %0" : "=m"(e->pos) : "j"(qr));
            func_0040C0F0(&tmp, q->f18 + 0xD0, 1.0f);
            func_0040BE90(&tmp, &tmp, -0.0009f);
            __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(e->vel));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(tmp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qs) : "j"(qc), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(e->vel) : "j"(qs));
            if (func_0040BA90(&e->i3C) != 0) {
                if (e->i34 > 0) {
                    e->i34 = e->i34 - 1;
                } else {
                    e->i44 = 0;
                    q->cnt = q->cnt - 1;
                }
            }
        }
    }
}
/* localdecomp:end func_00390940 */
