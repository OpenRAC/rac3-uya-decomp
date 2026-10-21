#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;
extern int func_0044FCD0(A *, void *, int, int, int);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/veldin/handwritten", func_0044FCD0);

LINKER_REMNANT("asm/veldin/remnants", func_004503F0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_004503F8);

