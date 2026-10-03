#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003CB5A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB5B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB748);

/* localdecomp:start func_003CB860 */
extern void func_003CB890();
extern void func_003CB748(void *);
void func_003CB860(void *p) {
    func_003CB890(p);
    func_003CB748(p);
}
/* localdecomp:end func_003CB860 */
