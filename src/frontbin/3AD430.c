#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003AD430();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AD430 */
extern void func_11AF48(void *, s32);
extern u8 D_001D8878[];
 
s32 func_003AD430(s32 a0, void *p) {
    func_11AF48(D_001D8878, *(s32 *)((u8 *)p + 0x4));
    return 1;
}
/* localdecomp:end func_003AD430 */
