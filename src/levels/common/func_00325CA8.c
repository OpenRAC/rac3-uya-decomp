#include "common.h"

/* localdecomp:start func_00325CA8 */
typedef struct { u8 pad0[0x20]; f32 f20[4]; f32 f30[4]; s32 f40[4]; f32 f50[4]; } D_325CA8;
typedef struct { u8 pad0[0x68]; D_325CA8 *f68; } O_325CA8;
extern s32 func_004182B0(s32 n);

void func_00325CA8(O_325CA8 *o) {
    D_325CA8 *d = o->f68;
    s32 i;
    for (i = 0; i < 4; i++) {
        d->f20[i] = func_004182B0(0xFF);
    }
    d->f30[0] = -1.0f;
    d->f30[1] = -2.25f;
    d->f30[2] = 1.25f;
    d->f30[3] = 2.5f;
    for (i = 3; i >= 0; i--) {
        d->f40[i] = i * 0x40 + 0x3F;
    }
    d->f50[0] = 2.5f;
    d->f50[1] = 3.0f;
    d->f50[2] = 3.0f;
    d->f50[3] = 2.5f;
}
/* localdecomp:end func_00325CA8 */
