#include "common.h"

/* localdecomp:start func_004D7F38 */
typedef struct {
    char s0[16];
    char s16[16];
    char s32[16];
    s32 w48;
    s32 w52;
    s32 w56;
    s32 w60;
    s32 w64;
    s32 w68;
    s32 w72;
    s32 w76;
    s32 w80;
    u8 p54[0xC];
    u8 b96;
} D_4D7F38;

typedef struct {
    u8 p0[0x1AF8];
    s32 w6904;
    u8 p1AFC[0x18];
    s32 w6932;
    s32 w6936;
    s32 w6940;
} B_4D7F38;

extern D_4D7F38 D_00251410;
extern B_4D7F38 D_001A4BE0;
extern struct U_4D7F38 D_001D4B4C __attribute__((section(".sdata")));
extern s32 D_001DBCB8;
extern char *func_004181A0();
extern char *func_0011B754(char *dst, char *src);
extern void func_004D2370(s32 a, s32 b);
extern void func_004D2D70(s32 a, void *b);

s32 func_004D7F38(s32 a, s32 b) {
    func_0011B754(D_00251410.s0, func_004181A0(5701));
    func_0011B754(D_00251410.s16, func_004181A0(5702));
    func_0011B754(D_00251410.s32, func_004181A0(3847));
    D_00251410.w48 = 0;
    D_00251410.w52 = D_001A4BE0.w6932;
    D_00251410.w56 = D_001A4BE0.w6940;
    D_00251410.w60 = D_001A4BE0.w6936;
    D_00251410.w64 = b;
    if (b != 0 && D_001A4BE0.w6904 != 0) {
        D_00251410.w64 = 0;
    }
    D_00251410.w68 = a;
    D_00251410.b96 = 0;
    func_004D2370(0, 0);
    if (D_00251410.w64 == 0) {
        D_00251410.w72 = 0;
        D_00251410.w76 = 60;
        D_00251410.w80 = 0;
        *(volatile s32 *)&D_001D4B4C = 0;
    } else {
        D_00251410.w72 = 0;
        D_00251410.w76 = 60;
        func_004D2D70(3, &D_001DBCB8);
    }
    return 1;
}
/* localdecomp:end func_004D7F38 */
