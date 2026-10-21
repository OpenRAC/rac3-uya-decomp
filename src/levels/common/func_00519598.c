#include "common.h"

/* localdecomp:start func_00519598 */
extern s32 func_00519410();

extern void func_005122D8(void);
extern void func_005122F8(void);
extern s32 func_00519410(void *, s32);
void func_00519598(void *arg0, s32 arg1) {
    if (func_00519410(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_00519410(arg0, 0x4000) != 0) {
        func_005122F8();
        func_005122D8();
    }
}
/* localdecomp:end func_00519598 */
