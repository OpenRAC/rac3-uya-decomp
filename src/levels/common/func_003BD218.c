#include "common.h"

/* localdecomp:start func_003BD218 */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003BD218;

extern s32 D_001D6740;
extern s16 D_001A4F48[];

s32 func_003BD218(Moby_003BD218 *m) {
    u8 *p = m->w68;
    if ((p != 0 && *(s32 *)(p + 264) == 2) || D_001D6740 != 0 || D_001A4F48[0] != 0) return 1;
    return 0;
}
/* localdecomp:end func_003BD218 */
