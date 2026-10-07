#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00800488);

/* localdecomp:start func_00800698 */
extern void func_008026F0(void);
extern void func_00800488(void);

/* main(): built at -O0 (unfilled delay slots, $fp frame saved with sq), see
   docs/compiler_matrix_i5bootn.md. func_008026F0 is libgcc's __main. */
int func_00800698(void) {
    func_008026F0();
    func_00800488();
    return 0;
}
/* localdecomp:end func_00800698 */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008006E0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00800790);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008007C0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008007C8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008007F0);
TEXT_PADDING(2);
