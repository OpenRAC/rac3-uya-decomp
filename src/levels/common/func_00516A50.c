#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;

extern u8 D_001E24D0;
extern void *func_005159A0(HT_8 *, u32);
s32 func_00516A50(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_005159A0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001E24D0) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
