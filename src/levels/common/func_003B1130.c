#include "common.h"

/* localdecomp:start func_003B1130 */
extern void func_00441FB8(u8 *, s32, s32);

void func_003B1130(u8 *obj) {
    *(s32 *)(*(u8 **)(obj + 104) + 96) = 0;
    func_00441FB8(obj, 1, -1);
}
/* localdecomp:end func_003B1130 */
