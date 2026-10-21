#include "common.h"

/* localdecomp:start func_003378A0 */
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;

extern s32 D_001EAA98[];
extern Obj_003378A0 *func_00440728(s32);

s32 func_003378A0(void) {
    Obj_003378A0 *p = func_00440728(D_001EAA98[0]);
    if (p != 0 && (p->flags & 2)) return 1;
    return 0;
}
/* localdecomp:end func_003378A0 */
