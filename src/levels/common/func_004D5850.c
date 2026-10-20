#include "common.h"

typedef struct {
    u8 p0[0x34];
    s32 w52;
    u8 p38[8];
    s16 h64;
} S_4D5850;

extern struct U_4D5850 D_001E1384 __attribute__((section(".sdata")));
extern struct U_4D5850 D_001E13B0 __attribute__((section(".sdata")));
extern s32 D_001E1380;
extern s32 D_001DB958;
extern s32 D_001DB970;
extern S_4D5850 D_001E6E00;
extern void func_004D30D0(void);
extern s32 func_004D4860(void);
extern void func_004D4AB8(void);
extern s32 func_004D4868(void);
extern void func_004D22D0(void);
extern s32 func_004D4688(void);
extern void func_004D47B0(s32 a);
extern void func_004D4E78();
extern void func_004D4C58(void *f);
extern void func_004D4890(void);
extern void func_00400228(void);
extern void func_004D48B0(s32 a, s32 b, s32 c, s32 d);

void func_004D5850(s32 flag) {
    s32 s;

    if (*(u8 *)&D_001E1384 != 0) {
        func_004D30D0();
        if (func_004D4860() == 1) {
            func_004D4AB8();
        }
        if (func_004D4860() > 0 && func_004D4868() != 0) {
            func_004D22D0();
        }
        if (*(volatile u8 *)&D_001E13B0 == 0) {
            s = 0;
            if (func_004D4860() > 0 && flag != 0) {
                switch (D_001E1380) {
                case 0:
                    s = D_001DB958;
                    break;
                case 1:
                    s = D_001DB970;
                    break;
                }
                *(volatile u8 *)&D_001E13B0 = 1;
            } else {
                s = func_004D4688();
            }
            func_004D47B0(s);
            func_004D4C58(func_004D4E78);
            func_004D4890();
            func_00400228();
        }
    }
    func_004D48B0(D_001E6E00.w52, D_001E6E00.h64, 15, 15);
}
