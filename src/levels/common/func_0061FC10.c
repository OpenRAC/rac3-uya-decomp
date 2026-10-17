#include "common.h"
typedef struct {
    u8 pad0[12];
    s16 h12;
    u8 pad1[33 - 14];
    s8 b33;
    u8 pad2[128 - 34];
} Ent_0061FC10;
extern Ent_0061FC10 D_0049C950[];
extern s32 func_00646268(u8 *, s32);
s32 func_0061FC10(u8 *p, s32 a) {
    s32 i;
    Ent_0061FC10 *e;
    if (a != 0) {
        if (p[6661] == 0) return 0;
        if (p[6664] != 0) return 0;
        i = -1;
        if (*(s32 *)(p + 1140) == 2) i = *(s32 *)(p + 1144);
        if (i == -1) return 0;
        if (func_00646268(p, i)) {
            e = &D_0049C950[D_0049C950[i].b33];
        } else {
            e = &D_0049C950[i];
        }
        return e->h12;
    }
    return 0;
}
