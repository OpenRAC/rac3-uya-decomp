#include "common.h"

extern void *func_00511690();

typedef struct { u32 key; void *val; } HE_400;
typedef struct { s32 f0; s32 n; HE_400 e[0x400]; } HT_400;
extern u8 D_001E24C8_003E1150[];
void *func_00511690(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != D_001E24C8_003E1150) return v;
    }
    return 0;
}
