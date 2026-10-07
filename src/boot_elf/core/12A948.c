#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A948);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A950);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A9F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AA78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AAE0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AB80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AB88);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AC40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AD28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012ADC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AE20);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AE98);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AEA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AEA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B000);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B098);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B138);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B1A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B300);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B5E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B800);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BA20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BC00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BC98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BD50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BE20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BE28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BEE4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BEE8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C078);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C084);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C088);

ASM_FUNC("asm/boot_elf/handwritten", func_0012C128);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C138);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C4AC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C4B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C56C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C570);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C638);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C81C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C820);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C908);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C99C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C9A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012CB84);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012CCC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012CE44);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D4D4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D4D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D578);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D5E8);

/* localdecomp:start func_0012D5F0 */
u32 func_0012D5F0(u32 a) {
    if ((a >> 28) == 7) {
        a &= 0x0FFFFFFF;
        a |= 0x80000000;
    }
    return a;
}
/* localdecomp:end func_0012D5F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D618);

/* localdecomp:start func_0012D650 */
extern s32 D_00141500[];
s32 func_0012D650(u32 i) {
    if (i >= 10) {
        return 0;
    }
    return D_00141500[i];
}
/* localdecomp:end func_0012D650 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D678);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D758);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D930);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D938);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D9A0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D9B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D9C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DA58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DA60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DC88);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012DC98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DCA0);

/* localdecomp:start func_0012DDC8 */
extern s32 func_0012DCA0(s32, s32, s32, s32);
extern s32 D_00141538[];
s32 func_0012DDC8(s32 a, s32 b, s32 c) {
    s32 r = func_0012DCA0(a, b, c, 0x40);
    if (r == 0) {
        D_00141538[0] = 0xB;
    }
    return r;
}
/* localdecomp:end func_0012DDC8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DE00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DEC0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DFA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E050);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E168);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E2E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E3A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E400);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E580);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E6D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E6D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E7A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E8C8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E8D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E8D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EA38);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012EB38);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EB40);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012EBB0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EBB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EC28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EC8C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EC90);

ASM_FUNC("asm/boot_elf/handwritten", func_0012EDD0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EE18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EF10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EFA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F0B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F2A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F3F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F470);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F4E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F4F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F5A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F600);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F608);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F720);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F728);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F860);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F918);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F9E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FAB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FB68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FC18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FC78);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FCD0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FCE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FCE8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FD50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FE78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FED8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF24);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FF28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF64);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF68);
