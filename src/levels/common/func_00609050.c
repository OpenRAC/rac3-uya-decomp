#include "common.h"
typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_1A4560;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_2257E0;
typedef struct { u8 p0[0x10]; u32 f10; } S_25F840;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1FE1A0;
extern s32 D_0024BC6C;
extern s32 D_0024057C;
extern s32 D_001D4CEC;
extern s32 D_001D5BCC;
extern s32 D_0024BC40;
extern u8 D_0025F680[];
extern S_25F840 D_0025F840;
extern S_1FE1A0 D_001FE1A0;
extern S_1A4560 D_001A4560;
extern S_2257E0 D_002257E0;
extern void func_0058F0A0();
extern void func_005BD7D8(s32, s32, s32, s32, s32);
extern void func_005BD4E8();
extern void func_001264E0();
extern void func_00194CB8(s32, s32, s32, s32, s32);
extern void func_00194760(void);
extern s32 func_00193680();
extern void func_005F1248(void);
extern void func_005BFDC8(void);
extern void func_00193C70(s32);
extern void func_00193C40(void);
extern void func_005A43D8(void);
extern void func_005A33A0(void);
extern s32 func_00194C78(s32);
extern void func_005C0AC8(s32);
extern void func_00195AE8(void);
extern void func_00589460(s32);
extern void func_005A2130(void);
extern void func_00194B28(s32);
extern void func_005FAF60(void);
void func_00609050(void) {
    s32 i;
    func_0058F0A0(D_0025F680, -1, 0x80);
    func_005BD7D8(6, 2, 0, 0, 0);
    func_005BD4E8();
    D_0025F840.f10 |= 0x80000000;
    func_001264E0(0);
    func_00194CB8(2, 0, 0, 0, 0);
    func_00194760();
    func_00193680();
    func_005F1248();
    func_005BFDC8();
    D_002257E0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_001FE1A0.f90[i] != 0) {
            func_00193C70(D_001FE1A0.f90[i]);
            func_00193C40();
            D_0024BC6C = 0;
            D_001FE1A0.f90[i] = 0;
        }
    }
    while (D_001A4560.f15C >= 3 || D_001A4560.f164 >= 0) {
        func_005A43D8();
        func_005A33A0();
    }
    if (D_001A4560.f17C != 0) D_001A4560.f17C = 0;
    if (D_001A4560.f18 >= 0) D_001A4560.f18 = -1;
    D_001D4CEC = D_0024057C & ~0x200;
    func_00194C78(0);
    D_002257E0.f7 = 0;
    func_005C0AC8(1);
    while (func_00193680()) func_00195AE8();
    D_002257E0.f7 = 1;
    func_00589460(6);
    D_001D5BCC = D_0024BC40;
    func_005A2130();
    func_00194B28(0);
    D_002257E0.f7 = 0;
    func_005FAF60();
}
