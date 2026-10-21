#include "common.h"

/* localdecomp:start func_003D1598 */
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x10];
    s32 i44;
    u8 pad48[0xC8];
    f32 k[4];
    s32 a[4];
} S_3D1598;
extern s32 func_0040BA90(s32 *);
extern void func_003D0C28(void *, S_3D1598 *, s32);

void func_003D1598(void *obj, S_3D1598 *s) {
    f32 t;
    s32 i;

    if (s->i44 == 0) {
        if (s->f30 < s->k[0]) {
            return;
        }
        if (s->k[3] < s->f30) {
            return;
        }
    } else if (func_0040BA90(&s->i44) == 0) {
        return;
    }
    func_003D0C28(obj, s, 0);
    t = s->f30;
    for (i = 1; i < 4; i++) {
        if (t < s->k[i]) {
            s->i44 = (s32)((f32)(s->a[i] - s->a[i - 1]) * ((t - s->k[i - 1]) / (s->k[i] - s->k[i - 1]))) + s->a[i - 1];
            return;
        }
    }
}
/* localdecomp:end func_003D1598 */
