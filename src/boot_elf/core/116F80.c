#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00116F80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00116F98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00116FCC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00116FD0);

/* localdecomp:start func_00117070 */
extern long func_0011BFD8(s32, s32, s32);
s32 func_00117070(s32 a) {
    return func_0011BFD8(a, 0, 10);
}
/* localdecomp:end func_00117070 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00117098);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001170B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011716C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001171C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001173F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011865C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118660);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011866C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011871C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118720);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118834);

/* localdecomp:start func_00118838 */
typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *read; void *write; void *seek; void *close; u8 pad[0x24]; void *data; } F_118838;
extern s32 func_0011B378();
extern s32 func_0011B3E0();
extern s32 func_0011B460();
extern s32 func_0011B4C8();
void func_00118838(F_118838 *ptr, s32 flags, s32 file, void *data) {
    ptr->p = 0;
    ptr->r = 0;
    ptr->w = 0;
    ptr->flags = flags;
    ptr->file = file;
    ptr->base = 0;
    ptr->size = 0;
    ptr->lbfsize = 0;
    ptr->cookie = ptr;
    ptr->read = func_0011B378;
    ptr->write = func_0011B3E0;
    ptr->seek = func_0011B460;
    ptr->close = func_0011B4C8;
    ptr->data = data;
}
/* localdecomp:end func_00118838 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118898);

LINKER_REMNANT("asm/boot_elf/remnants", func_001188B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001188C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011894C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118950);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001189A4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001189B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118CA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E14);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E74);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119258);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001192EC);

LINKER_REMNANT("asm/boot_elf/remnants", func_00119308);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119310);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011932C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119330);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119390);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001194E4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001194E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119540);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119588);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001197E0);

/* localdecomp:start func_00119F08 */
s32 func_00119F08(s32 r, s32 *pwc, u8 *s, u32 n) {
    s32 dummy;
    s32 ret = 0;
    if (pwc == 0) {
        pwc = &dummy;
    }
    if (s != 0) {
        ret = -1;
        if (n != 0) {
            *pwc = *s;
            ret = *s; ret = ret != 0;
        }
    }
    return ret;
}
/* localdecomp:end func_00119F08 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119F3C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A01C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A0B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A160);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A264);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A324);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3F4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3F8);

/* localdecomp:start func_0011A4A0 */
typedef struct N_11A4A0 { struct N_11A4A0 *next; s32 idx; } N_11A4A0;
typedef struct { u8 pad[0x4C]; N_11A4A0 **tab; } S_11A4A0;
void func_0011A4A0(S_11A4A0 *p, N_11A4A0 *n) {
    if (n != 0) {
        N_11A4A0 **f = p->tab;
        n->next = f[n->idx];
        f[n->idx] = n;
    }
}
/* localdecomp:end func_0011A4A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A4D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A5D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A658);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A750);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A960);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AA60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011ABB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AC20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011ADB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF38);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AF48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AFB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B018);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B060);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B09C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B0A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B0F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B168);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B240);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011B260);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B270);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B2D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B2E4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B2E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B378);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B3E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B460);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B4C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B4E4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B610);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B754);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B868);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B9A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BB58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD14);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD9C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BFD8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C004);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C008);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C050);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C108);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C180);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CD78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CDC0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CE78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CEF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E560);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E720);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E7FC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E858);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E860);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E8C0);

ASM_FUNC("asm/boot_elf/handwritten", func_0011E9CC);
