#include "common.h"

/* localdecomp:start func_003F00C0 */
typedef struct { u8 a; u8 b; u8 pad[8]; s16 c; s16 d; u8 e; u8 pad2; } E_3F00C0;
extern E_3F00C0 D_001E2500[8][8];
void func_003F00C0(void) {
    s32 i, j;
    for (i = 0; i < 8; i++) {
        E_3F00C0 *e = D_001E2500[i];
        for (j = 0; j < 8; j++) {
            e[j].a = 0;
            e[j].b = 0;
            e[j].c = 0;
            e[j].d = 0;
            e[j].e = 0;
        }
    }
}
/* localdecomp:end func_003F00C0 */
