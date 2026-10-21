#include "common.h"

typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;
extern u8 D_001E1FB4;
void *func_00611278(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001E1FB4 + 2;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
