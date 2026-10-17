#include "common.h"

typedef struct {
    u8 pad0[32];
    u8 state;
} Ent3F13B0;

typedef struct {
    u8 pad0[764];
    s32 count;
    u8 pad1[16];
    Ent3F13B0 *list[1];
} Vars3F13B0;

void func_003F13B0(u8 *self) {
    Vars3F13B0 *v = *(Vars3F13B0 **)(self + 104);
    s32 i;
    s32 j;

    for (i = 0; i < v->count; i++) {
        u8 s = v->list[i]->state;
        if ((u8)(s + 3) < 2 || s == 37) {
            for (j = i + 1; j < v->count; j++) {
                v->list[j - 1] = v->list[j];
            }
            v->count--;
        }
    }
}
