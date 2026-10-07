#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008026F0(void);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008010A8);

LINKER_REMNANT("asm/i5bootn/remnants", func_008010E0);

ASM_FUNC("asm/i5bootn/handwritten", func_008010E8);

/* localdecomp:start func_008010F8 */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);

void func_008010F8(void) {
    if (func_00801080() == 0x2000000) {
        func_00801138();
    } else {
        func_00801090();
    }
}
/* localdecomp:end func_008010F8 */

ASM_FUNC("asm/i5bootn/handwritten", func_00801138);

ASM_FUNC("asm/i5bootn/handwritten", func_00801340);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008014A0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008014D8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00801510);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008015A0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00801778);
INCLUDE_RODATA("asm/i5bootn/nonmatchings/text/rodata", jtbl_00805AF0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802490);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008024B8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802508);

ASM_FUNC("asm/i5bootn/handwritten", func_00802588);

ASM_FUNC("asm/i5bootn/handwritten", func_008025D8);

LINKER_REMNANT("asm/i5bootn/remnants", func_008025F0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802640);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008026F0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802710);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802E00);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802EF0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00802F88);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008035F0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00803BC0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804100);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804230);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008042D0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804510);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804568);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008045D0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804878);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008049E0);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804AF8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804B48);

LINKER_REMNANT("asm/i5bootn/remnants", func_00804C00);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804C08);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804CA8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804CD8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804D30);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804E40);

LINKER_REMNANT("asm/i5bootn/remnants", func_00804ED0);

LINKER_REMNANT("asm/i5bootn/remnants", func_00804EF8);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804F00);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804F30);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_00804F70);
