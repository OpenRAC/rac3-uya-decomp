#include "common.h"

/* localdecomp:start func_005168B0 */
typedef struct {
    u32 key;
    void *val;
} Ent_005168B0;

typedef struct {
    s32 unk0;
    s32 count;
    Ent_005168B0 e[8];
} Tbl_005168B0;

extern char D_001E24CC[4];

extern void *func_00515920();

s32 func_005168B0(Tbl_005168B0 *t, u32 key, void *val) {
    s32 i;
    u32 idx;
    void *v;

    if (t->count >= 8) {
        return 0;
    }
    if (func_00515920() != 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        idx = ((key & 7) + ((key % 7) * i + i)) & 7;
        v = t->e[idx].val;
        if (v == 0 || v == &D_001E24CC[3]) {
            t->e[idx].val = val;
            t->e[idx].key = key;
            t->count++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_005168B0 */
