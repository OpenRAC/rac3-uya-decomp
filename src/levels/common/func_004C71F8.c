#include "common.h"

typedef struct { s32 a[64]; s32 b[72]; s32 count; s32 flag; } S_4C71F8;

void func_004C71F8(S_4C71F8 *s, s32 i) {
    s->a[i] = 0;
    s->b[i] = 0;
    if (--s->count == 0) {
        s->flag = 0;
    }
}
