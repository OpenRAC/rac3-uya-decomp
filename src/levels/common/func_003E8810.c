#include "common.h"

/* localdecomp:start func_003E8810 */
typedef struct {
    u8 pad[588];
    s32 v;
    u8 pad2[1120 - 592];
} Unk003E8810;

extern Unk003E8810 D_001E2AC0[];

s32 func_003E8810(u8 *a0) {
    Unk003E8810 *p = &D_001E2AC0[*(s32 *)(a0 + 148)];
    switch (p->v) {
    case 4:
    case 81:
        return -1;
    }
    return 0;
}
/* localdecomp:end func_003E8810 */
