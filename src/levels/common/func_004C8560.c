#include "common.h"

extern char D_001DB110[];
extern char D_001DB128[];
extern void func_00116F98(char *, s32, char *);
void func_004C8560(void *unused, f32 *out, f32 t) {
    if (!out) func_00116F98(D_001DB110, 0x3D, D_001DB128);
    out[0] = t;
    out[1] = t * 0.5f;
    out[2] = 1.0f - t;
    out[3] = (1.0f - t) * 0.5f;
}
