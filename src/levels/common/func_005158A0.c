#include "common.h"

/* localdecomp:start func_005158A0 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001E24CC;
void *func_005158A0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != (&D_001E24CC + 2)) return v;
    }
    return 0;
}
/* localdecomp:end func_005158A0 */
