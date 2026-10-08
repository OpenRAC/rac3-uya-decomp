#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0011F2A0 */
extern s32 D_0013DBE8;
void func_0011F2A0(void) {
    D_0013DBE8 = 0;
}
/* localdecomp:end func_0011F2A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011F2B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011F340);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011F3E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011F468);

/* localdecomp:start func_0011F4E0 */
s32 func_0011F4E0(void) {
    return -1;
}
/* localdecomp:end func_0011F4E0 */

/* localdecomp:start func_0011F4E8 */
s32 func_0011F4E8(void) {
    return -1;
}
/* localdecomp:end func_0011F4E8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011F4F0);

/* localdecomp:start func_0011F5A0 */
s32 func_0011F5A0(void) {
    return 1;
}
/* localdecomp:end func_0011F5A0 */

/* localdecomp:start func_0011F5A8 */
typedef struct { s32 x0; s32 x4; u8 pad[0x40]; long x48; } S_11F5A8;
s32 func_0011F5A8(s32 a, S_11F5A8 *b) {
    b->x4 = 0x2000;
    b->x48 = 0;
    return 0;
}
/* localdecomp:end func_0011F5A8 */

/* localdecomp:start func_0011F5C0 */
s32 func_0011F5C0(void) {
    return 1;
}
/* localdecomp:end func_0011F5C0 */

/* localdecomp:start func_0011F5C8 */
extern void func_00124F20(s32);
s32 func_0011F5C8(s32 a, s32 b) {
    if (a == 1) {
        func_00124F20(b);
    }
    return 0;
}
/* localdecomp:end func_0011F5C8 */
