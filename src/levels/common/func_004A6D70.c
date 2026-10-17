#include "common.h"

typedef struct {
    u8 pad0[10];
    s16 f10;
    u8 pad12[16];
    s32 f28;
    u8 pad32[96];
} Ent_004A6D70;

extern Ent_004A6D70 D_001A3170[];
extern void func_004A6E88(s32);

void func_004A6D70(s32 arg0, s32 arg1)
{
    Ent_004A6D70 *p;
    s32 i;

    p = D_001A3170;
    for (i = 0; i < 52; i++, p++) {
        if ((arg1 == 0 || arg1 == p->f28) && arg0 == p->f10) {
            func_004A6E88(i);
        }
    }
}
