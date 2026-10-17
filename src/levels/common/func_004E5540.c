#include "common.h"

typedef struct {
    u8 pad[9668];
    s32 a;
    s32 pad2;
    s32 b;
} S_004E5540;
extern S_004E5540 D_001A4BE0;

int func_004E5540(void)
{
    S_004E5540 *p = &D_001A4BE0;
    if ((u32)(p->b - 17) < 2 || p->a == 108 || p->a == 132 || p->a == 120 || p->a == 119) {
        return 1;
    }
    return 0;
}
