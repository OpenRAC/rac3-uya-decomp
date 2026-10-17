#include "common.h"

typedef struct {
    u8 pad[28];
    s32 id;
    u8 pad2[17];
    u8 active;
    u8 pad3[18];
} Ent_00669930;

extern Ent_00669930 D_0033ACA0[50];

Ent_00669930 *func_00669930(s32 id) {
    Ent_00669930 *p;

    p = D_0033ACA0;
    do {
        if (p->active == 1 && p->id == id) {
            return p;
        }
        p++;
    } while ((s32)p < (s32)&D_0033ACA0[50]);
    return 0;
}
