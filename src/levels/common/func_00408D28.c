#include "common.h"

/* localdecomp:start func_00408D28 */
typedef struct {
    f32 value;
    s32 pad;
} Item_408D28;

extern u32 D_001DBCE0;
extern s32 D_001DFB10[];

extern s32 func_0040D020(u32 a, u32 b, f32 f);

void func_00408D28(u32 a, u32 b, Item_408D28 *items) {
    s32 i;
    if ((a & 0xFF000000) > 0x80000000 || (b & 0xFF000000) > 0x80000000) {
        D_001DBCE0 |= 1;
    }
    for (i = 0; i < 4; i++) {
        D_001DFB10[i] = func_0040D020(a, b, items[i].value);
    }
}
/* localdecomp:end func_00408D28 */
