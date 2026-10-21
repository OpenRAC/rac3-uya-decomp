#include "common.h"

/* localdecomp:start func_00517B00 */
extern s32 func_00517B00();

typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001DC1F0_003E6C80;
extern void func_0051ABA0();
s32 func_00517B00(O_3E6C80 *a, s32 b) {
    if (a->vt->fn(a, D_001DC1F0_003E6C80) != 0) {
        func_0051ABA0(a, b, b, b, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00517B00 */
