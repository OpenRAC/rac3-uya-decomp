#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void *D_001D52FC;
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_00389920(s32);
extern void func_003866E8();
extern s32 D_001D4CE8[];
extern s32 func_0039D6C8(s32);
extern s32 func_003B2AA0(void);
extern s32 func_003E3040();
extern void func_003B43B0(void);
extern s32 func_0037DCE8(void);
extern void func_003B43C0();
extern void *func_003AED40(s32);
extern s32 func_003E24B0(s32 arg0, s32 arg1);
extern s32 D_001D8A48;
extern s32 D_001D8A70_g;
extern s32 D_001D8AD8;
extern s32 D_001D8ACC;
extern void func_00399660(s32);
extern int D_001D8A70_g;
extern void func_003B3558(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B1518 */
extern void func_0038E728(s32);
extern void func_00399660(s32);
extern void func_003B5D10(s32);
extern s32 func_003B5EC8(s32);
extern s32 D_001D8AD0;
extern s32 D_001D8ACC;
extern s32 D_001D8ADC;
extern s32 D_001D8AE0;
extern s32 D_001D8AD4;
extern s32 D_001D8AD8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B1518[];
void func_003B1518(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D5BDC[0] != 0) {
        func_003B5D10(0);
    }
    temp_2 = func_003B5EC8(1);
    D_001D8AD0 = temp_2;
    D_001D8ACC = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D5BDC_003B1518[0] == 0) {
        temp_2_2 = func_003B5EC8(1);
        D_001D8ADC = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8AE0 = temp_3;
        func_0038E728(temp_3);
        temp_2_3 = func_003B5EC8(1);
        D_001D8AD4 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8AD8 = temp_3_2;
        func_00399660(temp_3_2);
    }
}
/* localdecomp:end func_003B1518 */

/* localdecomp:start func_003B15B8 */
extern void func_0039FF28(s32, s32, s32);
 
void func_003B15B8(void) {
    func_0039FF28(5, 0, 0);
}
/* localdecomp:end func_003B15B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B15E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B16B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B22C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B23F8);

/* localdecomp:start func_003B2640 */
extern void func_003B13A8(void);
extern void func_003B13D0(void);
extern void func_003B1400(void);
extern s32 D_001D8A48;
extern s8 D_001DA020_003B2640;
extern s32 D_001D8A70_003B2640;
extern s32 D_001D4CE8[];
void func_003B2640(void) {
    s32 t5 = D_001D8A48;
    s32 t4 = D_001D4CE8[0];
    D_001DA020_003B2640 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_003B13A8();
    } else if ((u32)(t4 - 6) < 2U) {
        func_003B13D0();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_003B1400();
    }
    D_001D8A70_003B2640 = 2;
}
/* localdecomp:end func_003B2640 */

/* localdecomp:start func_003B26E8 */
extern void func_003B15E0(s32);
extern void func_003B1EB0(void);
extern void func_003B23F8(s32);
void func_003B26E8(s32 a) {
    func_003B15E0(a);
    func_003B1EB0();
    func_003B23F8(a);
}
/* localdecomp:end func_003B26E8 */

/* localdecomp:start func_003B2720 */
extern s32 D_001D8A70_003B2720;
extern s32 D_001D4CE8[];
void func_003B2720(void) {
    s32 temp_3;

    if (D_001D8A70_003B2720 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_003E24B0(0x4C003C, 1);
            func_003E24B0(0xD000B, 1);
            return;
        default:
            func_003E24B0(0x4C003C, 0);
            func_003E24B0(0xD000B, 0);
            D_001D8A70_003B2720 = 1;
            break;
        }
    }
}
/* localdecomp:end func_003B2720 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B27A8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318840);

/* localdecomp:start func_003B2958 */
typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8AD0_003B2958;
extern s32 D_001D8AD4_003B2958;
extern s32 D_001D8ADC_003B2958;
extern s32 D_001D8B68_003B2958[2];
extern u8 D_001D5BDC_003B2958[];
void func_003B2958(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_003E3040(0x10);
    func_003E3040(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_003AED40(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_0039D6C8(1);
    func_003B5F88(D_001D8AD0_003B2958);
    for (j = 0; j < 4; j++) {
        func_003B5F88(D_001D8B68_003B2958[j]);
    }
    if (D_001D5BDC_003B2958[0] == 0) {
        func_003B5F88(D_001D8ADC_003B2958);
        func_003B5F88(D_001D8AD4_003B2958);
    }
    func_00389920(0);
    func_0038E728(0);
}
/* localdecomp:end func_003B2958 */

/* localdecomp:start func_003B2A28 */
extern u8 D_001D5BDC[];

void func_003B2A28(void) {
    if (D_001D5BDC[0] == 0) {
        func_0037DCE0();
    }
}
/* localdecomp:end func_003B2A28 */

/* localdecomp:start func_003B2A50 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A70_g;
extern void func_003866E8(s32, s32, s32, s32);
extern void func_003B2AF8(void);
void func_003B2A50(void) {
    if (D_001D5BDC[0] == 0) func_0037DCE8();
    if (D_001D8A70_g != 0) {
        func_003866E8(0, 0, 0, 0x30);
        func_003B2AF8();
    }
}
/* localdecomp:end func_003B2A50 */

/* localdecomp:start func_003B2AA0 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA220;
extern s32 D_001DA208[2];
extern void func_003B22C0();
extern void func_003B2958();
extern void func_003B27A8();
extern void func_003B2A28(void);
extern void func_003B2A50();
s32 func_003B2AA0(void) {
    if (D_001DA220 == 0) {
        func_003E1A50(D_001DA208, (s32)func_003B22C0, (s32)func_003B2958, (s32)func_003B27A8, (s32)func_003B2A28, (s32)func_003B2A50);
        D_001DA220 = 1;
    }
    return (s32)D_001DA208;
}
/* localdecomp:end func_003B2AA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B2AF8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318860);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2F50);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003188E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3558);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3DB8);

/* localdecomp:start func_003B41E8 */
extern s32 D_001D8BF0;
void func_003B41E8(void) {
    D_001D8BF0 = 0;
}
/* localdecomp:end func_003B41E8 */

/* localdecomp:start func_003B41F0 */
extern s32 D_001D8BF0;
s32 func_003B41F0(void) {
    return D_001D8BF0;
}
/* localdecomp:end func_003B41F0 */

/* localdecomp:start func_003B41F8 */
extern s32 D_001D8C04_003B41F8;
extern s32 D_001D8C08_003B41F8;
void func_003B41F8(s32 a0, s32 a1) {
    D_001D8C04_003B41F8 = 0x40;
    D_001D8C08_003B41F8 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D8C04_003B41F8 = a0;
    }
    D_001D8C08_003B41F8 = a1;
}
/* localdecomp:end func_003B41F8 */

/* localdecomp:start func_003B4220 */
extern void func_003B41E8(void);
extern void func_003B41F8(s32, s32);
extern void func_003B42C0(s32, s32);
extern s32 D_001D8BEC;
extern s32 D_001D8BE8;
extern s32 D_001D8BF4;
extern s32 D_001D8BF8;
extern s32 D_001D8BFC;
extern s8 D_001D8C00;
s32 func_003B4220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D8BEC != 1) {
        return 0;
    }
        D_001D8BEC = 0;
        func_003B41E8();
        D_001D8BE8 = arg0;
        D_001D8BF4 = arg1;
        D_001D8BF8 = arg2;
        D_001D8BFC = arg3;
        D_001D8C00 = arg4;
        func_003B42C0(0x60, 0x1A0);
        func_003B41F8(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_003B4220 */

extern s32 D_001D8C0C;
extern s32 D_001D8C10;
/* localdecomp:start func_003B42C0 */
extern s32 D_001D8C0C;
extern s32 D_001D8C10;
void func_003B42C0(s32 a, s32 b) { D_001D8C0C = a; D_001D8C10 = b; }
/* localdecomp:end func_003B42C0 */

/* localdecomp:start func_003B42D0 */
extern void func_0037E058(void);
extern void func_0039FF28(s32, s32, s32);
extern s32 D_001D8BEC;
extern s32 D_001D8BE8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B42D0[];
extern s32 D_001D8C04;
extern s32 D_001D8BF0;
extern s32 D_001D8C08;
s32 func_003B42D0(void) {
    s32 t;
    s32 m;
    if (D_001D8BEC == 1) {
        return 0;
    }
    func_0037E058();
    t = D_001D8BE8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D8C04) {
            D_001D8BF0 = 1;
            D_001D8BEC = 1;
            func_0039FF28(4, 0, 0);
        } else if (m & D_001D8C08) {
            D_001D8BEC = 1;
            D_001D8BF0 = 2;
            func_0039FF28(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B42D0[0] + 0x1C4) & D_001D8C04) {
            D_001D8BF0 = t;
            func_0039FF28(0x12, 0, 0);
            D_001D8BEC = t;
        }
        break;
    }
    return 1;
}
/* localdecomp:end func_003B42D0 */

/* localdecomp:start func_003B43B0 */
extern s32 D_001D8BF0;
extern s32 D_001D8BEC;
void func_003B43B0(void) {
    D_001D8BF0 = 0;
    D_001D8BEC = 1;
}
/* localdecomp:end func_003B43B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B43C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B45B0);
