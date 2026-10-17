#include "common.h"

extern s32 func_00511710();
extern void *func_00511690();

extern void *func_00511690();
typedef struct { u32 key; void *val; } HE_3E11D0;
typedef struct { s32 f0; s32 n; HE_3E11D0 e[0x400]; } HT_3E11D0;
extern u8 D_001E24C8_003E11D0[];
s32 func_00511710(HT_3E11D0 *t, u32 key, void *val) {
    s32 i;
    s32 h;
    if (t->n >= 0x400) return 0;
    if (((void *(*)(void))func_00511690)()) return 0;
    for (i = 0; i < 0x400; i++) {
        h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        if (t->e[h].val == 0 || t->e[h].val == D_001E24C8_003E11D0) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
