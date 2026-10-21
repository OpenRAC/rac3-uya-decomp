#include "common.h"

/* localdecomp:start func_00322E00 */
typedef struct { u8 pad[80]; s32 idx; } Sub_00322E00;
typedef struct { u8 pad[104]; Sub_00322E00 *sub; } Moby_00322E00;
extern u8 D_001A30B0[];
extern void func_004A6E88(s32);
void func_00322E00(Moby_00322E00 *m) {
    Sub_00322E00 *s = m->sub;
    s32 i = s->idx;
    if (i != -1) {
        u8 *e = D_001A30B0 + i * 128;
        if (*(Moby_00322E00 **)(e + 220) == m && e[208] != 0) func_004A6E88(i);
    }
    s->idx = -1;
}
/* localdecomp:end func_00322E00 */
