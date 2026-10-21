#include "common.h"

/* localdecomp:start func_00518BE8 */
extern s32 func_00518BE8(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern void func_00519D20(u8 *, f32, f32, f32, f32);
extern s32 D_001DC190[];
s32 func_00518BE8(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001DC190[0]) != 0) {
        func_00519D20((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00518BE8 */
