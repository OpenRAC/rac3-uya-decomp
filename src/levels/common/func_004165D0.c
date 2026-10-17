#include "common.h"

typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_001EA740;
 
void func_004165D0(void) {
    S_302D80 *s = &D_001EA740;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
