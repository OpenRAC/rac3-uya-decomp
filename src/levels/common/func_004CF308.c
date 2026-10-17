#include "common.h"

extern void func_0011F940(s32);
extern void func_004CF308();
extern void func_0012D4D8();

typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001E124C;
extern void *D_001E1238;
extern void *D_001E1278;
extern S_AAA00 *D_001E1264;
extern void *D_001E1268_003AAA00;
extern void *D_001E1260;
extern u8 D_0013D208[];
extern s32 func_004D0680();
extern s32 func_004D1FB0();
extern void func_0011EC70(void *);
extern void func_0011EC30(void *);
extern void func_0011EB50(s32, s32);
extern void func_0012D4D8(u8 *);
extern s32 func_004D1948();
extern s32 func_004CF468();
extern s32 func_004D0778();
void func_004CF308(void) {
    ((void (*)(void *))func_004D0680)(D_001E124C);
    ((void (*)(void *))func_004D1FB0)(D_001E1238);
    func_0011EC70(D_001E1278);
    func_0011EC30(D_001E1278);
    ((s32 (*)(s32))func_0011F940)(2);  /* s32 return matters: keeps $v0 live */
    func_0011EB50(2, D_001E1264->wB0);
    func_0012D4D8(D_0013D208);
    ((void (*)(void *))func_004D1948)(D_001E1264);
    ((void (*)(void *))func_004CF468)(D_001E1268_003AAA00);
    ((void (*)(void *))func_004D0778)(D_001E1260);
    *(u32 *)0x1000E000 &= ~2;
}
