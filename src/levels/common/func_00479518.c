#include "common.h"

extern s32 D_001D81F4;
extern void func_004799C0(void);
extern void func_0042FF20();
extern void func_00479218();

extern void func_0042FF20();
extern void func_004799C0(void);
extern void func_004799C8();
extern void func_00479E38(void);
extern void func_0013D3C0(s32);
extern s32 D_001D81F4;
extern s32 D_001D81FC;
/* The 16-byte .sdata declarations look small to gcc (no %hi/%lo split) but
   not to the assembler, which reaches them through lui, as Ps2EeAs did for
   symbols it had no size for yet; the other small ones go through $gp. */
extern s32 D_001D4CE8[4] __attribute__((section(".sdata")));
void func_00479518(void) {
    s32 t;
    s32 v;
    switch (D_001D81F4) {
    case 0:
        func_0042FF20((void *)func_00479218, 0, 0);
        func_004799C8();
        D_001D81FC = 0x1E;
        D_001D81F4 = D_001D81F4 + 1;
        break;
    case 1:
        func_004799C8();
        v = D_001D81FC;
        if (v > 0) { v = v - 1; D_001D81FC = v; }
        D_001D81FC = v;
        if (v == 0) func_00479E38();
        break;
    case 2:
        t = D_001D4CE8[0];
        if (t == 1 || t == 0x12) func_0013D3C0(1);
        func_004799C0();
        break;
    }
}
