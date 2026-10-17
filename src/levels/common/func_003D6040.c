#include "common.h"
typedef struct { s32 id; s32 pad[5]; } Ent_003D6040;
extern Ent_003D6040 D_003A10E0[];
Ent_003D6040 *func_003D6040(s32 id) {
    Ent_003D6040 *r = 0;
    s32 i;
    for (i = 0; D_003A10E0[i].id != -1; i++) {
        if (D_003A10E0[i].id == id) {
            r = &D_003A10E0[i];
            break;
        }
    }
    return r;
}
