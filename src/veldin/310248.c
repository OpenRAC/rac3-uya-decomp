#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00310248);

LINKER_REMNANT("asm/veldin/remnants", func_003104B8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003104D8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003106A8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00310730);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00310798);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00310948);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00310AC8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003110F8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00311140);

/* localdecomp:start func_003116E8 */
/* This file's small data (.sdata, targets/veldin/data_split.txt): reached
   through $gp because it is defined here; D_001E17B0, another file's, through
   lui (func_003116F0). */
s32 D_001DC6E8 = 0;
void func_003116E8(void) {
    D_001DC6E8 = 0;
}
/* localdecomp:end func_003116E8 */

/* localdecomp:start func_003116F0 */
extern u8 *D_001E17B0;
void func_003116F0(void) {
    D_001E17B0 = 0;
    D_001DC6E8 = 0;
}
/* localdecomp:end func_003116F0 */

