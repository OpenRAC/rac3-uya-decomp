#include "common.h"

/* localdecomp:start func_0045D4D8 */
typedef struct {
    u8 pad0[256];
    s32 d[16];
    s32 e[16];
    u8 pad180[32];
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    s32 pad1AC;
    s32 f1B0;
    s32 f1B4;
    s32 f1B8;
    s32 pad1BC;
    s32 f1C0;
    s32 f1C4;
    s32 f1C8;
    s32 pad1CC;
    s32 f1D0;
    s32 f1D4;
    s32 f1D8;
    u8 pad1DC[368];
    s32 head;
    s32 count;
    s32 a[7];
    s32 b[7];
    s32 c[7][16];
} Obj_0045D4D8;
void func_0045D4D8(Obj_0045D4D8 *o) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < o->count; i++) {
        j = (o->head - i + 7) % 7;
        o->a[j] = 0;
        o->b[j] = 0;
        for (k = 15; k >= 0; k--) {
            o->c[j][k] = 0;
        }
    }
    o->f1B0 = 0;
    o->f1A0 = 0;
    o->f1A4 = 0;
    o->f1A8 = 0;
    o->f1D0 = 1;
    o->f1B4 = 0;
    o->f1B8 = 0;
    o->f1C0 = 0;
    o->f1C4 = 0;
    o->f1C8 = 0;
    o->f1D4 = 1;
    o->f1D8 = 0;
    for (k = 0; k < 16; k++) {
        o->d[k] = 0;
        o->e[k] = 0;
    }
}
/* localdecomp:end func_0045D4D8 */
