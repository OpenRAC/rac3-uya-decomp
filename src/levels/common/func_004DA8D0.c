#include "common.h"

/* localdecomp:start func_004DA8D0 */
/* Retail reaches these with lui, except D_001D5620 from a delay slot. In
   .sdata gcc emits bare references, which the assembler expands with lui
   because the size is unknown; the sized alias gets the $gp one. */
extern s32 D_001D5608[] __attribute__((section(".sdata")));
extern s32 D_001D561C[] __attribute__((section(".sdata")));
extern s32 D_001D5620[] __attribute__((section(".sdata")));
extern s32 D_001D55F4[] __attribute__((section(".sdata")));
extern s32 D_001D5620_g;
extern s32 D_001DBCF8;
extern u8 D_001D2A50[];
extern void func_004D9680(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_004D9C20();
extern void func_004D8F90(u8 **, s32, s32, s32, s32, s32, s32);
void func_004DA8D0(void) {
    u8 *p = D_001D2A50;
    func_004D9680(&p, D_001D5608[0], 0x40, 0x40, D_001D5620[0], 0x80, 0x80);
    func_004D9680(&p, D_001D5620[0], 0x80, 0x80, D_001D561C[0], 0x100, 0x100);
    func_004D9C20(&p, D_001D561C[0], D_001D5620_g);
    func_004D8F90(&p, D_001D561C[0], 0x100, 0x100, 1, 0, D_001DBCF8);
    D_001D55F4[0] = p - D_001D2A50;
}
/* localdecomp:end func_004DA8D0 */
