#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/i5bootn/remnants", func_00800000);

ASM_FUNC("asm/i5bootn/handwritten", func_00800008);

/* localdecomp:start func_00800158 */
/* Sony 2.9-ee library code (sibling call): _exit() hands its status to func_008007C8. */
extern void func_008007C8(int);
void func_00800158(int code) {
    func_008007C8(code);
}
/* localdecomp:end func_00800158 */
