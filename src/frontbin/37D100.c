#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0037D100 */
extern void func_003934E8(s32, s32);

void func_0037D100(void) {
    func_003934E8(0, 0);
}
/* localdecomp:end func_0037D100 */

/* localdecomp:start func_0037D120 */
extern void func_003B62D0(s32);
extern void func_003ADC80(void *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern u8 D_001E2340[];

void func_0037D120(void) {
    func_003B62D0(1);
    func_003ADC80(D_001E2340);
    func_0039BEC0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_0037D120 */

/* localdecomp:start func_0037D160 */
extern void func_003B62D0(s32);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);

void func_0037D160(void) {
    func_003B62D0(1);
    func_0039BEC0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_0037D160 */

/* localdecomp:start func_0037D198 */
s32 func_0037D198(void) {
}
/* localdecomp:end func_0037D198 */

LINKER_REMNANT("asm/remnants", func_0037D1A0);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003ECDC0(s32, s32);
extern void * func_003A9B10();
extern s32 D_001D5C78;

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227600;
/* localdecomp:start func_0037D1A8 */
extern s32 D_00227600_0037D1A8[];
extern s32 D_001D5C78_0037D1A8[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003ECDC0(s32, s32);
extern void * func_003A9B10();
void func_0037D1A8(void) {
    s32 *p = D_00227600_0037D1A8;
    func_11A264(p[0x84/4], 0xCD, 0x40000);
    D_001D5C78_0037D1A8[0] = func_003A9B10(func_003ECDC0(0x24F10, p[0x84/4]), 0x40000);
}
/* localdecomp:end func_0037D1A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037D200);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00317FE0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318000);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318050);

/* localdecomp:start func_0037DC30 */
s32 func_0037DC30(void) {
    return 0;
}
/* localdecomp:end func_0037DC30 */

/* localdecomp:start func_0037DC38 */
s32 func_0037DC38(void) {
}
/* localdecomp:end func_0037DC38 */

/* localdecomp:start func_0037DC40 */
s32 func_0037DC40(void) {
}
/* localdecomp:end func_0037DC40 */

/* localdecomp:start func_0037DC48 */
s32 func_0037DC48(void) {
}
/* localdecomp:end func_0037DC48 */

/* localdecomp:start func_0037DC50 */
s32 func_0037DC50(void) {
}
/* localdecomp:end func_0037DC50 */

/* localdecomp:start func_0037DC58 */
extern u8 D_001427AB[];
u8 func_0037DC58(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_0037DC58 */

extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
/* localdecomp:start func_0037DC68 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9918;
extern s32 D_001D9900[2];
s32 *func_0037DC68(void) {
    if (D_001D9918 == 0) {
        func_003E1A50(D_001D9900, 0, 0, 0, 0, 0);
        D_001D9918 = 1;
    }
    return D_001D9900;
}
/* localdecomp:end func_0037DC68 */

/* localdecomp:start func_0037DCB0 */
extern s32 * func_0037DC68();
void func_0037DCB0(void) {
    func_0037DC68();
}
/* localdecomp:end func_0037DCB0 */

LINKER_REMNANT("asm/remnants", func_0037DCD0);

/* localdecomp:start func_0037DCD8 */
s32 func_0037DCD8(void) {
}
/* localdecomp:end func_0037DCD8 */

/* localdecomp:start func_0037DCE0 */
s32 func_0037DCE0(void) {
}
/* localdecomp:end func_0037DCE0 */

/* localdecomp:start func_0037DCE8 */
s32 func_0037DCE8(void) {
}
/* localdecomp:end func_0037DCE8 */

/* localdecomp:start func_0037DCF0 */
s32 func_0037DCF0(void) {
    return 0;
}
/* localdecomp:end func_0037DCF0 */

/* localdecomp:start func_0037DCF8 */
s32 func_0037DCF8(void) {
    return 0;
}
/* localdecomp:end func_0037DCF8 */

/* localdecomp:start func_0037DD00 */
s32 func_0037DD00(void) {
}
/* localdecomp:end func_0037DD00 */

/* localdecomp:start func_0037DD08 */
s32 func_0037DD08(void) {
}
/* localdecomp:end func_0037DD08 */

/* localdecomp:start func_0037DD10 */
s32 func_0037DD10(void) {
}
/* localdecomp:end func_0037DD10 */

/* localdecomp:start func_0037DD18 */
s32 func_0037DD18(void) {
}
/* localdecomp:end func_0037DD18 */

/* localdecomp:start func_0037DD20 */
s32 func_0037DD20(void) {
    return 0;
}
/* localdecomp:end func_0037DD20 */

/* localdecomp:start func_0037DD28 */
s32 func_0037DD28(void) {
    return 1;
}
/* localdecomp:end func_0037DD28 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DD30);

LINKER_REMNANT("asm/remnants", func_0037DF20);

/* localdecomp:start func_0037DF28 */
extern void *D_001D9A20;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_00318CC0[];

s32 func_0037DF28(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = -1;
    var_a1 = 0;
    if (D_00318CC0->f2C > 0) {
        if ((*(s32 *)((u8 *)(D_001D9A20) + 4)) == arg0) {
            var_a2 = 0;
        } else {
loop_4:
            var_a1 += 1;
            if (var_a1 < D_00318CC0->f2C) {
                if ((*(s32 *)((u8 *)(((var_a1 * 0x10) + D_001D9A20)) + 4)) == arg0) {
                    var_a2 = var_a1;
                } else {
                    goto loop_4;
                }
            }
        }
    }
    return var_a2;
}
/* localdecomp:end func_0037DF28 */

/* localdecomp:start func_0037DF98 */
extern s32 func_0037DF28(s32);

s32 func_0037DF98(s32 id) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_0037DF28(id);
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_0037DF98 */

/* localdecomp:start func_0037DFD8 */
__asm__(".extern D_001D9A20, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_0037DFD8(fallback)
s32 fallback;
{
    s32 index = func_0037DF28(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D9A20 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_0037DFD8 */

/* localdecomp:start func_0037E030 */
extern s32 func_0037DFD8();
void func_0037E030(void) {
    func_0037DF98(func_0037DFD8());
}
/* localdecomp:end func_0037E030 */

/* localdecomp:start func_0037E058 */
extern s32 D_001D5688;
void func_0037E058(void) { D_001D5688 = 0; }
/* localdecomp:end func_0037E058 */

extern s32 D_001D5680;
/* localdecomp:start func_0037E060 */
extern s32 D_001D5680;
void func_0037E060(void) { D_001D5680 = 10; }
/* localdecomp:end func_0037E060 */

/* localdecomp:start func_0037E070 */
extern void func_00393460();
extern u8 D_001D5790[];
 
void func_0037E070(void) {
    func_00393460(D_001D5790, 0, 0);
}
/* localdecomp:end func_0037E070 */

LINKER_REMNANT("asm/remnants", func_0037E098);

/* localdecomp:start func_0037E0B8 */
s32 func_0037E0B8(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_0037E0B8 */
