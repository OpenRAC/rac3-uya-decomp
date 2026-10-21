#include "common.h"

/* localdecomp:start func_00438760 */
typedef struct { s16 v[24]; } Ent_00438760;
extern Ent_00438760 D_0021E2E0[];
extern Ent_00438760 *D_0021DEA0[];
extern s32 D_001E00DC;
extern u8 *D_001E009C;
s32 func_00438760(s32 idx, u8 *obj) {
    Ent_00438760 *e;
    s32 key;
    s32 i;
    if (*(Ent_00438760 **)((u8 *)D_0021DEA0 + idx * 4) == 0) {
        return 0;
    }
    e = (Ent_00438760 *)((u8 *)D_0021E2E0 + (idx - D_001E00DC) * 48);
    key = (obj - D_001E009C) >> 8;
    for (i = 0; i < 24; i++) {
        if ((e->v[i] & 0x7FFF) == key) {
            obj[33] = 0xFF;
            if (e->v[i] & 0x8000) {
                if (i == 0) {
                    *(Ent_00438760 **)((u8 *)D_0021DEA0 + idx * 4) = 0;
                } else {
                    e->v[i - 1] |= 0x8000;
                }
            } else {
                for (; i < 23; i++) {
                    e->v[i] = e->v[i + 1];
                }
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_00438760 */
