#include "common.h"

/* localdecomp:start func_004B4BB8 */
extern void func_004A7810(void);
extern u8 D_001A30B0[];
extern void func_0011F0A0(s32);
extern void func_00402A10(s32);
extern void func_0045BEC8(void);
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CF80();
extern s32 D_001E0F9C;
extern void func_004B4BB8(s32, s32, s32, s32, s32);

extern u8 D_001A30B0[];
extern s32 D_001E0F98;
extern s32 D_001E0F9C;
extern s32 D_001E0FA0;
extern s32 D_001E0FA4;
extern s32 D_001E0FA8;
extern s32 D_001E0FAC;
extern s16 D_001CD018[];
extern void func_0013CF80();
extern void func_0011F0A0();
extern void func_004A7810();
extern void func_0045BEC8();
extern void func_00402A10();
extern void func_00418028();
void func_004B4BB8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    D_001A30B0[0x43] |= 8;
    func_0013CF80(2, 0, 0, 0, 0);
    func_0011F0A0(0);
    func_004A7810();
    func_0045BEC8();
    D_001E0F98 = a;
    D_001E0FAC = D_001CD018[0];
    D_001E0F9C = b;
    D_001E0FA0 = c;
    D_001E0FA4 = d;
    D_001E0FA8 = e;
    func_00402A10(4);
    func_00418028();
}
/* localdecomp:end func_004B4BB8 */
