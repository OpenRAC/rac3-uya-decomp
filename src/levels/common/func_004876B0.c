#include "common.h"

/* localdecomp:start func_004876B0 */
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;

extern Ent4876B0 D_00233E58[];
extern s32 D_001D8A5C;
extern u8 *func_00435C80(s32);

void func_004876B0(void) {
    u8 *p = func_00435C80(-1);
    s32 id = *p - 1;
    s32 i;
    if (p == 0) return;
    for (i = 0; i < 60; i++) {
        if (D_00233E58[i].id != id) continue;
        if (!D_00233E58[i].flag) continue;
        D_001D8A5C = i;
        break;
    }
}
/* localdecomp:end func_004876B0 */
