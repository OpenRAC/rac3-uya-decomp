#include "common.h"

typedef struct {
    s32 n;
    s32 id;
    s32 pad8[2];
    s32 arr[8];
} S_3F0680;

typedef struct {
    u8 pad0[104];
    S_3F0680 *p;
} O_3F0680;

extern O_3F0680 *D_002495D0[];

void func_003F0680(s32 a0, s32 a1) {
    s32 i;
    S_3F0680 *p;

    for (i = 0; i < 8; i++) {
        if (D_002495D0[i] != 0) {
            p = D_002495D0[i]->p;
            if (p->id == a1) {
                if (p->n < 8) {
                    p->arr[p->n] = a0;
                    p->n++;
                }
                return;
            }
        }
    }
}
