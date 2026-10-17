#include "common.h"

typedef struct {
    u8 pad[0];
    s32 id;
    u8 pad2[45];
    u8 active;
    u8 pad3[18];
} Ent_006698E8;

extern Ent_006698E8 D_0033ACA0[50];

Ent_006698E8 *func_006698E8(s32 id) {
    Ent_006698E8 *p;

    p = D_0033ACA0;
    do {
        if (p->active == 1 && p->id == id) {
            return p;
        }
        p++;
    } while ((s32)p < (s32)&D_0033ACA0[50]);
    return 0;
}
