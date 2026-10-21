#include "common.h"

typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_00396C48[];
extern void (*D_001D7590)();
/* Retail reaches these through $gp only from branch delay slots, and with
   lui $at elsewhere: .sdata arrays get the bare references the assembler
   expands with lui, the sized aliases the $gp ones. */
extern s32 D_001D4CE8[] __attribute__((section(".sdata")));
extern s32 D_001D4CEC[] __attribute__((section(".sdata")));
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0042FC50(void) {
    S_00396C48 *p = D_00142430_00396C48;
    /* volatile keeps the flag load and its masking ahead of the p->f15C load,
       the order the single-symbol frontbin version gets from its store. */
    s32 v = *(volatile s32 *)D_001D4CEC & ~2;
    D_001D4CEC_g = v;
    if (*(volatile s32 *)&p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC[0] = v | 0x440;
                D_001D4CE8_g = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8[0] = 1;
            }
            if (D_001D7590 != 0) {
                D_001D7590();
                D_001D7590 = 0;
            }
        }
    }
}
