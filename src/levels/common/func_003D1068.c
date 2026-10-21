#include "common.h"

/* localdecomp:start func_003D1068 */
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[4];
    s32 i38;
    u8 pad3C[0xB4];
    f32 k[4];
    s32 a[4];
} S_3D1068;
extern s32 D_001A71A0[];
extern s32 func_0040BA90(s32 *);
extern void func_003D0C28(void *, S_3D1068 *, s32);

void func_003D1068(void *obj, S_3D1068 *s) {
    f32 t;
    s32 i;

    if (s->i38 == 0) {
        if (s->f30 < s->k[0]) {
            return;
        }
        if (s->k[3] < s->f30) {
            return;
        }
    } else if (func_0040BA90(&s->i38) == 0) {
        return;
    }
    func_003D0C28(obj, s, D_001A71A0[0]);
    t = s->f30;
    for (i = 1; i < 4; i++) {
        if (t < s->k[i]) {
            s->i38 = (s32)((f32)(s->a[i] - s->a[i - 1]) * ((t - s->k[i - 1]) / (s->k[i] - s->k[i - 1]))) + s->a[i - 1];
            return;
        }
    }
}
/* localdecomp:end func_003D1068 */
