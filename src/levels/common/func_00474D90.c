#include "common.h"

/* localdecomp:start func_00474D90 */
typedef struct { u8 pad[4648]; s32 w; u8 pad2[9700 - 4652]; u8 b; } S474;
extern S474 D_001A4BE0;
s32 func_00474D90(void) {
    S474 *p = &D_001A4BE0;
    s32 v = p->w;
    if (v == 9) v = 0;
    if (p->b) v = 0;
    return v;
}
/* localdecomp:end func_00474D90 */
