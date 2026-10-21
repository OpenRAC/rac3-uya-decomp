#include "common.h"

/* localdecomp:start func_003B51A0 */
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;

extern void func_00439610(Obj_003B51A0 *);

void func_003B51A0(void *a, void *b, Obj_003B51A0 *o) {
    o->fn64(o);
    if (o->w24) func_00439610(o);
}
/* localdecomp:end func_003B51A0 */
