#include "common.h"

/* localdecomp:start func_003D08E0 */
extern s32 D_0016C580[];
extern void func_004373D8(s32, void *);

void func_003D08E0(s32 a0, u8 *a1) {
    if (*(s32 *)(a1 + 96)) {
        func_004373D8(D_0016C580[0], a1 + 112);
    }
}
/* localdecomp:end func_003D08E0 */
