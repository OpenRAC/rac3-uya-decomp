#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A40C8();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_11F0A0();
extern void func_11F0A0(s32);
extern void func_003A40C8(void);
extern s32 D_001D4BB4;
void func_11F0A0(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D97C8 */
extern u32 *D_001DA0D0_003D97C8;
extern u32 *D_001DA7E0_003D97C8;
extern s32 D_001DA7E4_003D97C8;
extern s32 D_001D4BB0_003D97C8;
extern s32 func_003DB318(s32);
extern void func_003A40C8(void);
void func_003D97C8(void) {
    u32 *save = D_001DA0D0_003D97C8;
    s32 r;
    D_001DA0D0_003D97C8 += 4;
    D_001DA7E0_003D97C8[0] = 0x20000000;
    D_001DA7E0_003D97C8[1] = (u32)D_001DA0D0_003D97C8;
    D_001DA7E0_003D97C8[2] = 0;
    D_001DA7E0_003D97C8[3] = 0;
    r = func_003DB318(D_001D4BB0_003D97C8);
    func_003A40C8();
    if (D_001DA7E4_003D97C8 < r) { D_001DA7E4_003D97C8 = r; }
    D_001DA0D0_003D97C8[0] = 0x20000000;
    D_001DA0D0_003D97C8[1] = (u32)(D_001DA7E0_003D97C8 + 4);
    D_001DA0D0_003D97C8[2] = 0;
    D_001DA0D0_003D97C8[3] = 0;
    D_001DA0D0_003D97C8 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA0D0_003D97C8;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003D97C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D98D0);

/* localdecomp:start func_003D99D8 */
extern s32 D_001D4BB0_003D99D8;
extern s32 D_001D4BB4;
void func_00388648(s32 *, s32, s32);
void func_003D9A40();
void func_11F0A0(s32);
extern s32 D_001DA0D0_003D99D8;
extern s32 D_001DA7E0;
extern u8 D_00302540[];

void func_003D99D8(void) {
    s32 t = D_001DA0D0_003D99D8;
    D_001DA7E0 = t;
    t += 0x10;
    D_001D4BB0_003D99D8 = D_001D4BB4;
    D_001DA0D0_003D99D8 = t;
    func_11F0A0(0);
    func_003D9A40();
    func_00388648(D_00302540, 0x3200, 0x40);
    func_003D97C8();
}
/* localdecomp:end func_003D99D8 */
