#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 D_001D5C78;
extern void func_003AA0B8(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_11F940(s32);
extern f32 func_003A9CF8(f32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CF8);

LINKER_REMNANT("asm/remnants", func_003A9DE0);

/* localdecomp:start func_003A9E00 */
extern void func_003A9AC0(void *, s32);
void func_003A9E00(void) {
    s32 i;
    if (D_001D5C78 != 0) {
        for (i = 0; i < 1; i++) {
            func_003A9AC0((void *)(D_001D5C78 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_003A9E00 */

/* localdecomp:start func_003A9E60 */
extern void func_003A6C30();
__asm__(".extern D_001D5C78, 16");
void func_003A9E60(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u8 a9) {
    if (D_001D5C78 != 0) {
        func_003A6C30(D_001D5C78 + 0x1FCA8, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}
/* localdecomp:end func_003A9E60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A9EF0);

/* localdecomp:start func_003AA080 */
extern s32 D_001D5C78;
extern s32 D_001D52F0;
void func_003AA080(void) {
    if (D_001D5C78 != 0) {
        func_003A9AE8(D_001D5C78 + 0x1FCA8, D_001D52F0);
    }
}
/* localdecomp:end func_003AA080 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA0B8);

LINKER_REMNANT("asm/remnants", func_003AA278);

/* localdecomp:start func_003AA290 */
extern s32 D_001D5C78;
extern s32 D_00319090[];
extern void func_00391D08();
extern void func_003A9EF0();
void func_003AA290(void) {
    if (D_001D5C78 != 0 && D_00319090[0] == 0) {
        func_00391D08(1);
        func_003A9EF0();
    }
}
/* localdecomp:end func_003AA290 */

LINKER_REMNANT("asm/remnants", func_003AA2D0);

/* localdecomp:start func_003AA2E8 */
extern s32 D_001DA10C;
extern s32 D_001DA110;
extern s32 D_001DA114;
extern s32 D_001DA118;
extern s32 D_001DA120;
extern s32 D_001DA124;
extern s32 D_001DA128;
extern s32 D_001DA12C;
extern s32 D_001DA108_003AA2E8;
extern s32 D_001DA11C_003AA2E8;
extern s32 D_001DA130_003AA2E8;
extern s32 D_001DA134_003AA2E8;
extern s32 D_001DA138_003AA2E8;
extern s32 D_001DA140[];
extern s32 D_001D4D40;
extern void func_0038CC68();
extern s32 func_003AA4B0();
extern void func_003AAA00();
extern void func_003AA828();
s32 func_003AA2E8(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 c, s32 flag) {
    s32 i;
    s32 *p;
    s32 r;
    D_001DA10C = alloc(0x1A0000, 0x40);
    p = D_001DA140;
    D_001DA110 = alloc(0x4FC80, 0x40);
    D_001DA114 = alloc(0x1010, 0x40);
    D_001DA108_003AA2E8 = alloc(0x14, 0x40);
    D_001DA118 = alloc(0xEC800, 0x40);
    D_001DA11C_003AA2E8 = alloc(0x5000C, 0x40);
    D_001DA120 = alloc(0xC000, 0x40);
    D_001DA124 = alloc(0x80000, 0x40);
    D_001DA128 = alloc(0x4000, 0x40);
    D_001DA12C = alloc(0x3000, 0x40);
    D_001DA130_003AA2E8 = alloc(0xC, 0x40);
    D_001DA134_003AA2E8 = alloc(0xB8, 0x40);
    D_001DA138_003AA2E8 = alloc(0x68, 0x40);
    for (i = 1; i >= 0; i--) {
        *p++ = alloc(0x4000, 0x80);
    }
    func_0038CC68(flag != 0, flag != 0);
    func_003AA828(a, b, c);
    r = func_003AA4B0(D_001DA134_003AA2E8, D_001DA11C_003AA2E8, D_001DA130_003AA2E8);
    func_003AAA00();
    D_001D4D40 = D_001D4D40 & ~0x80;
    return r;
}
/* localdecomp:end func_003AA2E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA4B0);

/* localdecomp:start func_003AA7E0 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AA7E0(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AA7E0 */

/* localdecomp:start func_003AA800 */
extern s32 func_003AAE00();
extern s32 D_001DA138[];

void func_003AA800(void) {
    func_003AAE00(D_001DA138[0]);
}
/* localdecomp:end func_003AA800 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA828);

/* localdecomp:start func_003AAA00 */
typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001DA11C;
extern void *D_001DA108;
extern void *D_001DA148;
extern S_AAA00 *D_001DA134;
extern void *D_001DA138_003AAA00;
extern void *D_001DA130;
extern u8 D_0013D208[];
extern s32 func_003ABD78();
extern s32 func_003AD6A8();
extern void func_11EC70(void *);
extern void func_11EC30(void *);
extern void func_11EB50(s32, s32);
extern void func_12D4D8(u8 *);
extern s32 func_003AD040();
extern s32 func_003AAB60();
extern s32 func_003ABE70();
void func_003AAA00(void) {
    ((void (*)(void *))func_003ABD78)(D_001DA11C);
    ((void (*)(void *))func_003AD6A8)(D_001DA108);
    func_11EC70(D_001DA148);
    func_11EC30(D_001DA148);
    ((s32 (*)(s32))func_11F940)(2);  /* s32 return matters: keeps $v0 live */
    func_11EB50(2, D_001DA134->wB0);
    func_12D4D8(D_0013D208);
    ((void (*)(void *))func_003AD040)(D_001DA134);
    ((void (*)(void *))func_003AAB60)(D_001DA138_003AAA00);
    ((void (*)(void *))func_003ABE70)(D_001DA130);
    *(u32 *)0x1000E000 &= ~2;
}
/* localdecomp:end func_003AAA00 */

/* localdecomp:start func_003AAA98 */
s32 func_003AAA98(void) {
}
/* localdecomp:end func_003AAA98 */
