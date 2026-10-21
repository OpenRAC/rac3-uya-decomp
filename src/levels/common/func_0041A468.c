#include "common.h"

/* localdecomp:start func_0041A468 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_41A468;
extern S_41A468 D_002E6110[];

void func_0041A468(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_002E6110[i].id == id) break;
    }
    if (i < 13) {
        D_002E6110[i].f24 = v;
        if (!D_002E6110[i].f68) D_002E6110[i].f4 = v;
    }
}
/* localdecomp:end func_0041A468 */
