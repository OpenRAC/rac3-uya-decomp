#include "common.h"

/* localdecomp:start func_00518DF0 */
typedef struct {
    u32 key;
    u8 *val;
} Ent_00518DF0;
typedef struct {
    s32 pad0;
    s32 count;
    Ent_00518DF0 e[8];
} Tab_00518DF0;
extern u8 D_001E24D8[4];
extern s32 func_00515EA8(Tab_00518DF0 *);
s32 func_00518DF0(Tab_00518DF0 *t, u32 key, u8 *val) {
    s32 i;
    u32 idx;
    if (t->count < 8 && func_00515EA8(t) == 0) {
        for (i = 0; i < 8; i++) {
            idx = ((key & 7) + ((key % 7) * i + i)) & 7;
            if (t->e[idx].val == 0 || t->e[idx].val == &D_001E24D8[2]) {
                t->e[idx].val = val;
                t->e[idx].key = key;
                t->count = t->count + 1;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00518DF0 */
