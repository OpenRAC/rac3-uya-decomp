#include "common.h"

/* localdecomp:start func_00390650 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_390650;
typedef int Q_390650 __attribute__((mode(TI)));
typedef struct {
    s32 n;
} T_390650;
typedef struct {
    V_390650 v0;
    f32 f10;
    f32 f14;
    T_390650 t18;
    u8 *owner;
    u8 pad20[0x10];
} E_390650;
typedef struct {
    u8 pad0[0x18];
    u8 *p18;
} U_390650;

extern E_390650 D_0029F020[];
extern void func_0040C0F0(void *, f32, void *);
extern void func_0040CCA0(void *, void *, void *, f32);
extern void func_003907A0(u8 *, void *, s32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_0040BA90(void *);

void func_00390650(u8 *o)
{
    E_390650 *e;
    s32 i;
    U_390650 *u;
    V_390650 tmp;
    V_390650 w;
    f32 f;
    Q_390650 qa, qb;

    u = *(U_390650 **)(o + 0x68);
    for (i = 0; i < 12; i++) {
        e = &D_0029F020[i];
        if (e->owner == o) {
            func_0040C0F0(&tmp, 1.0f, u->p18 + 0xD0);
            f = (f32)e->t18.n;
            func_0040CCA0(&w, e, &tmp, e->f10);
            f = f / 37.0f;
            func_003907A0(o, &w, (s32)(f * 128.0f));
            e->f10 = func_0040CEC8(e->f10, e->f14);
            func_0040C0F0(&tmp, 0.04f, &tmp);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(e->v0));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(tmp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(qa));
            if (func_0040BA90(&D_0029F020[i].t18) != 0) {
                e->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_00390650 */
