#include "common.h"

typedef struct {
    u8 pad[0x4C];
    f32 hist[16];
} Hist_003491F0;

typedef struct {
    u8 pad[0x68];
    Hist_003491F0 *w68;
} Moby_003491F0;

extern s32 D_001DD0F0;

void func_003491F0(Moby_003491F0 *m, f32 value) {
    Hist_003491F0 *h;
    s32 i;
    h = m->w68;
    for (i = D_001DD0F0 - 1; i >= 0; i--) {
        h->hist[i + 1] = h->hist[i];
    }
    h->hist[1] = value;
}
