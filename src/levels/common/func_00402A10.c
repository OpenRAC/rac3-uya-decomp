#include "common.h"

extern u32 *D_001E10E8_g;
extern void func_004C1FE8(s32, unsigned long);
extern void func_00412CA8(void);
extern void func_00412D40(s32);
extern void func_004C1E50(s32);

extern u32 *D_001E10E8_00385B60;
extern u32 *D_001E10E8_g;
extern s32 D_001DF9C8_g;
extern s32 D_001DF9C8_00385B60;
extern u8 D_00141990[];
extern void func_004C1E50(s32);
extern s32 func_0012C908(s32);
extern void func_004C1C68(void);
extern void func_004C1D30(void);
extern void func_004C1CB0();
extern void func_00412CA8(void);
extern void func_00412D40(s32);
extern void func_00412DC0(void);
extern void func_004C1FE8(s32, unsigned long);
void func_00402A10(s32 arg0) {
    s32 i;
    s32 t;
    func_004C1E50(1);
    i = arg0 - 1;
    func_0012C908(0);
    D_001DF9C8_g = D_001DF9C8_00385B60 + 1;
    func_004C1C68();
    while (i >= 0) {
        func_00412CA8();
        func_00412D40(1);
        func_00412DC0();
        func_004C1FE8(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_004C1FE8(1, (long)(0x80 - t) << 24);
        D_001E10E8_00385B60[0] = 0x30000014;
        D_001E10E8_00385B60[1] = (u32)D_00141990;
        D_001E10E8_00385B60[2] = 0;
        D_001E10E8_00385B60[3] = 0x50000014;
        D_001E10E8_g = D_001E10E8_00385B60 + 4;
        func_004C1E50(1);
        func_0012C908(0);
        D_001DF9C8_g = D_001DF9C8_00385B60 + 1;
        func_004C1D30();
        func_004C1CB0();
    }
    func_004C1E50(1);
    func_0012C908(0);
    D_001DF9C8_g = D_001DF9C8_00385B60 + 1;
    func_004C1C68();
    func_00412CA8();
    func_00412D40(1);
}
