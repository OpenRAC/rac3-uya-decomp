#include "common.h"

/* localdecomp:start func_00438670 */
typedef struct { s16 v[24]; } Ent_00438670;
extern Ent_00438670 D_0021E2E0[];
extern Ent_00438670 *D_0021DEA0[];
extern s32 D_001E00DC;
extern u8 *D_001E009C;
s32 func_00438670(s32 idx, u8 *obj) {
    Ent_00438670 **slot;
    Ent_00438670 *e;
    Ent_00438670 *n;
    s32 i;
    slot = (Ent_00438670 **)((u8 *)D_0021DEA0 + idx * 4);
    if (*slot == 0) {
        n = (Ent_00438670 *)((u8 *)D_0021E2E0 + (idx - D_001E00DC) * 48);
        *slot = n;
        n->v[0] = ((obj - D_001E009C) >> 8) | 0x8000;
        obj[33] = idx;
        return 1;
    }
    e = (Ent_00438670 *)((u8 *)D_0021E2E0 + (idx - D_001E00DC) * 48);
    for (i = 0; i < 23; i++) {
        if (e->v[i] & 0x8000) {
            e->v[i] &= 0x7FFF;
            i++;
            *(s16 *)((u8 *)e + i * 2) = ((obj - D_001E009C) >> 8) | 0x8000;
            obj[33] = idx;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_00438670 */
