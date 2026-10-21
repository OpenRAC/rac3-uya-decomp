#include "common.h"

/* localdecomp:start func_003C1AB8 */
typedef int s128_3C1AB8 __attribute__((mode(TI)));
typedef union { s128_3C1AB8 q; f32 f[4]; } V_3C1AB8;
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    s128_3C1AB8 v180;
    s128_3C1AB8 v190;
    s128_3C1AB8 v1A0;
    u8 pad1B0[0x1D0 - 0x1B0];
    s32 w1D0;
} P_3C1AB8;
typedef struct {
    u8 pad[0x10];
    s128_3C1AB8 pos;
    u8 pad20[0x68 - 0x20];
    P_3C1AB8 *p68;
} M_3C1AB8;
extern s32 D_001EAA98[];
extern f32 func_0040C018(void *, void *);
extern s32 func_003F8448(void *, void *, s32, M_3C1AB8 *, s32);
void func_003C1AB8(M_3C1AB8 *m) {
    V_3C1AB8 a;
    V_3C1AB8 b;
    P_3C1AB8 *p;
    a.q = m->pos;
    p = m->p68;
    a.f[2] += 0.1f;
    b.q = p->v190;
    a.f[2] += p->f38;
    b.f[2] += p->f38;
    if (3600.0f <= func_0040C018(&a, &b)) {
        return;
    }
    if (func_003F8448(&a, &b, 16, m, 0) != 0) {
        if (D_001EAA98[0] == 0) {
            return;
        }
        if (D_001EAA98[0] != p->w1D0) {
            return;
        }
    }
    p->v180 = p->v190;
    p->v1A0 = p->v190;
}
/* localdecomp:end func_003C1AB8 */
