#include "common.h"

/* localdecomp:start func_003C4FE0 */
typedef struct {
    u8 pad[860];
    s32 f;
} G_003C4FE0;
extern G_003C4FE0 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 func_00440760(u8 *, s32, s32);
s32 func_003C4FE0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 *q = (s32 *)(p + 64);
    s32 i;
    G_003C4FE0 *g = D_001A4BE0;
    for (i = 0; i < 6; i++, q++) {
        if (*q != 0 && g->f == *q) {
            return 1;
        }
    }
    if (*(s32 *)(p + 204) != -1 && func_00440760(D_001A4C60, *(s32 *)(p + 204), 0) != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003C4FE0 */
