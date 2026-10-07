#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00124F20(s32);
extern void func_00125F70(s32, s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124988);

LINKER_REMNANT("asm/boot_elf/remnants", func_001249E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001249F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124A28);

ASM_FUNC("asm/boot_elf/handwritten", func_00124A68);

LINKER_REMNANT("asm/boot_elf/remnants", func_00124A78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124A80);

ASM_FUNC("asm/boot_elf/handwritten", func_00124B80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124B90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124BE4);

ASM_FUNC("asm/boot_elf/handwritten", func_00124BE8);

ASM_FUNC("asm/boot_elf/handwritten", func_00124BF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124C08);

ASM_FUNC("asm/boot_elf/handwritten", func_00124C40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124C50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124CB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124D64);

ASM_FUNC("asm/boot_elf/handwritten", func_00124D68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124D78);

ASM_FUNC("asm/boot_elf/handwritten", func_00124DA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124DB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124ED0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124ED8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F48);

ASM_FUNC("asm/boot_elf/handwritten", func_00124F50);

ASM_FUNC("asm/boot_elf/handwritten", func_00124F60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F70);

ASM_FUNC("asm/boot_elf/handwritten", func_00124FA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124FB8);

ASM_FUNC("asm/boot_elf/handwritten", func_0012508C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125100);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125110);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125120);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125130);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125288);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125290);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125320);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001254B8);

/* localdecomp:start func_00125540 */
typedef struct N_125540 { struct N_125540 *next; struct N_125540 *prev; } N_125540;
extern N_125540 *D_0013F2A0[];
N_125540 *func_00125540(N_125540 *p) {
    N_125540 *next = p->next;
    if (p->prev != 0) {
        p->prev->next = next;
    } else {
        D_0013F2A0[0] = next;
    }
    if (next != 0) {
        next->prev = p->prev;
    }
    p->prev = 0;
    return next;
}
/* localdecomp:end func_00125540 */

ASM_FUNC("asm/boot_elf/handwritten", func_00125578);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125820);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125870);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125878);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001258E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125930);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125938);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125940);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001259F0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125A40);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125A68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125A70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125B68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125BE8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125C60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125C68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125CB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125D18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125E48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125F38);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125F60);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125F68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125F70);

LINKER_REMNANT("asm/boot_elf/remnants", func_00126018);
