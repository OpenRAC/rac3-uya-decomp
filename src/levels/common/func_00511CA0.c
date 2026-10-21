#include "common.h"

/* localdecomp:start func_00511CA0 */
typedef struct {
    u8 pad[80];
    s32 items[4];
    s32 count;
} Unk00511CA0;

s32 func_00511CA0(Unk00511CA0 **a0, s32 a1) {
    Unk00511CA0 *p = a0[1];
    if (p->count >= 4) {
        return 0;
    }
    p->items[p->count] = a1;
    a0[1]->count++;
    return 1;
}
/* localdecomp:end func_00511CA0 */
