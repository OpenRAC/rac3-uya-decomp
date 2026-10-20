#include "common.h"

extern s32 D_001D8E50;
extern u8 *D_001D52FC[];
extern u8 D_001D672C[];

extern s32 func_00494DD0(s32);
extern void func_00495868(s32, s32);
extern void func_0048E830(void);
extern void func_0048E670(void *, s32);
extern void func_0048EC60(void);
extern s32 func_004949B0(void);
extern s32 func_004948D0(void);
extern void func_00417DA0(s32, s32);
extern void func_0013D3C0(s32);
extern s32 func_0047A250(void);
extern void func_0047A268(void);
extern void func_005120B8(void *);
extern s32 func_0047B380(void);
extern void func_00513758(s32);

void func_0048E140(void *a0) {
    s32 f;

    switch (D_001D8E50) {
    case 0:
        f = *(s32 *)(D_001D52FC[0] + 452);
        func_00495868(func_00494DD0(0), f);
        func_0048E830();
        func_0048E670(a0, f);
        func_0048EC60();
        break;
    case 1:
        if (func_004949B0() == 0) {
            D_001D8E50 = 0;
            if (func_004948D0() == 1) {
                func_00417DA0(-1, 1);
                func_0013D3C0(8);
            }
        }
        break;
    }
    if (func_0047A250() != 0) {
        func_0047A268();
        func_005120B8(a0);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
