#include "common.h"

extern void func_0011F0A0(s32);
extern void func_004C1D30();
extern void func_004C1CB0();
extern void func_004C1E50();
extern void func_004C1E50(s32);
extern void func_0011F0A0();
extern void func_004AF9A8();

/* Retail reaches these with lui except for the $gp store to D_001E10F8 from
   a delay slot: in .sdata gcc emits bare references, which the assembler
   expands with lui because the size is unknown. */
extern s32 D_001DAE90;
extern s32 D_001E10F8_g;
extern s32 D_001E10F8[] __attribute__((section(".sdata")));
extern s32 D_001E10F0[] __attribute__((section(".sdata")));
extern s32 D_001E10F4[] __attribute__((section(".sdata")));
extern s32 D_001E10E0[];
extern u32 *D_001E10E8[] __attribute__((section(".sdata")));
extern s32 *func_0012D650();
extern void func_0012D938();
extern void func_0011F0A0();
extern void func_004AF9A8();
extern void func_004C1CB0();
extern void func_004C1E50(s32);
void func_004C1D30(void) {
    s32 t;
    s32 flags;
    s32 lim;
    s32 c;
    s32 *r;
    t = (s32)D_001E10E8[0] - D_001E10E0[D_001E10F4[0]];
    flags = D_001DAE90 | 0x1F;
    lim = D_001E10F8[0];
    if (t >= lim) lim = t;
    D_001DAE90 = flags;
    c = D_001E10F0[0] < t;
    D_001E10F8_g = lim;
    if (c == 0 || D_001E10F4[0] == 0) {
        D_001E10E8[0][0] = 0x70000000;
        D_001E10E8[0][1] = 0;
        D_001E10E8[0][2] = 0;
        D_001E10E8[0][3] = 0;
        r = func_0012D650(1);
        *r |= 0xC0;
        func_0011F0A0(0);
        func_0012D938(r, D_001E10E0[D_001E10F4[0]]);
        if (c != 0) {
            func_004C1E50(1);
            func_004C1CB0();
        }
    } else {
        *(volatile s32 *)&D_001DAE90 = 0;
        func_004AF9A8();
    }
}
