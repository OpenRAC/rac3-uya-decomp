#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003934E8(s32, s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003934E8);

LINKER_REMNANT("asm/remnants", func_00393550);

INCLUDE_ASM("asm/nonmatchings/text", func_00393580);

LINKER_REMNANT("asm/remnants", func_003936A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A8);

ASM_FUNC("asm/handwritten", func_003937C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393878);

INCLUDE_ASM("asm/nonmatchings/text", func_00393A18);

INCLUDE_ASM("asm/nonmatchings/text", func_00393C98);

LINKER_REMNANT("asm/remnants", func_00393DB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00393DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393E90);

INCLUDE_ASM("asm/nonmatchings/text", func_00394060);

/* localdecomp:start func_00394300 */
typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001D9F20;
void func_0039B760(u8 *, u32);
void func_00394300(s32 a, u32 b) {
    H_394300 *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50;
        func_0039B760((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001D9F20->arr[a] = 0;
}
/* localdecomp:end func_00394300 */

INCLUDE_ASM("asm/nonmatchings/text", func_00394368);

INCLUDE_ASM("asm/nonmatchings/text", func_00394660);

INCLUDE_ASM("asm/nonmatchings/text", func_003947B0);

INCLUDE_ASM("asm/nonmatchings/text", func_00394A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00394B38);

/* localdecomp:start func_00394C18 */
void func_00394C18(u8 *d, u8 *s) {
    d[4] = s[0];
    d[5] = s[1];
    d[6] = s[2];
    d[7] = s[3];
    *(u8 **)d = s + *(s32 *)(s + 4);
    *(u8 **)(d + 0x20) = s + *(s32 *)(s + 8);
}
/* localdecomp:end func_00394C18 */

INCLUDE_ASM("asm/nonmatchings/text", func_00394C58);

INCLUDE_ASM("asm/nonmatchings/text", func_00394F78);

LINKER_REMNANT("asm/remnants", func_00395088);

INCLUDE_ASM("asm/nonmatchings/text", func_00395090);

LINKER_REMNANT("asm/remnants", func_00395358);

/* localdecomp:start func_00395360 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_00395360;
extern u8 D_01FF7FF0[];
extern s32 func_0039D5F8();
s32 func_00395360(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    D_001D4B50_00395360 = p;
    *p = 0x60;
    func_0039D5F8((s32)D_001D4B50_00395360 + D_001D4B50_00395360[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_00395360 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003953E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003953F0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318170);

LINKER_REMNANT("asm/remnants", func_00395628);

INCLUDE_ASM("asm/nonmatchings/text", func_00395648);

/* localdecomp:start func_003958A0 */
typedef struct {
    u8 pad0[0x6C];
    u32 f6C;
    u8 pad1[0x20];
    u32 slots[1];
} T_958A0;

extern T_958A0 D_00225780[];
extern u32 D_00227610[];
extern u32 D_001DA0D8;
extern void func_00395648(void);

void func_003958A0(s32 a0) {
    u32 value = D_00225780[0].slots[a0];

    D_00225780[0].f6C = value;
    func_00395648();
    D_00225780[0].f6C = D_00227610[0] + D_001DA0D8;
}
/* localdecomp:end func_003958A0 */
