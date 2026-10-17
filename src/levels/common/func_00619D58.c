#include "common.h"
typedef struct { s32 w0; u8 pad[0x44C]; void *owner; } E_619D58;
typedef struct { u8 pad[0x90]; s32 w90; } M_619D58;
extern E_619D58 *D_0024CF20[];
void func_00619D58(M_619D58 *m, E_619D58 **out) {
    s32 i;
    for (i = 0; i < 8; i++) {
        E_619D58 *p = D_0024CF20[i];
        if (p != 0 && p->owner == m) {
            *out = p;
            m->w90 = p->w0;
            return;
        }
    }
    *out = 0;
}
