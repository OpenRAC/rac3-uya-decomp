#include "common.h"

typedef struct { u8 p0[0x38]; long d38; } O_004C61D8;
typedef struct {
    u8 p0[0x44];
    s16 h44;
    u8 p46[0x1A0 - 0x46];
    O_004C61D8 *arr[8];
} G_004C61D8;

extern G_004C61D8 D_001E6C00[];
extern void func_004475C0(O_004C61D8 *);

void func_004C61D8(void) {
    G_004C61D8 *g = D_001E6C00;
    O_004C61D8 *o = g->arr[0];
    s32 i;
    func_004475C0(o);
    for (i = 1; i < D_001E6C00[0].h44; i++) {
        g->arr[i]->d38 = o->d38;
    }
}
