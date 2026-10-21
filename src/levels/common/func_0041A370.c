#include "common.h"

/* localdecomp:start func_0041A370 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_002E6110[];
extern void func_0041A170();
s32 func_0041A370(s32 id) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_002E6110[i].id == id) break;
    }
    if (i < 13) {
        func_0041A170(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0041A370 */
