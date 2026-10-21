#include "common.h"

/* localdecomp:start func_0047B9C0 */
extern u8 D_001D82F0;
extern s32 func_004181A0(s32);
extern s32 func_00494900(s32, s32, s32, s32, s32);
extern s32 func_004949B0(void);
extern s32 func_004948D0(void);
extern void *func_00438468(s32, s32);
extern s32 func_0047B380(void);
extern void func_00513758(s32);
extern s32 func_0047C5C8(void);
extern void func_005120B8(s32);
extern s32 func_00512D70(s32, s32);

s32 func_0047B9C0(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;
    void **p;

    switch (D_001D82F0) {
    case 0:
        return 0;
    case 1:
        a = func_004181A0(2274);
        b = func_004181A0(2271);
        c = func_004181A0(4145);
        func_00494900(0, a, b, c, 0);
        D_001D82F0 = 2;
        return 1;
    case 2:
        if (func_004949B0() != 0) {
            return 1;
        }
        r = func_004948D0();
        if (r == 1) {
            p = func_00438468(6747, 4);
            if (p != 0) {
                ((void (*)(void))*p)();
            }
            func_00513758(func_0047B380());
            func_005120B8(func_0047C5C8());
            D_001D82F0 = 0;
            func_00512D70(0xD000B, 1);
            func_00512D70(0xD0025, 1);
            return 1;
        }
        if (r == 2) {
            D_001D82F0 = 0;
            func_00512D70(0xD000B, 1);
            func_00512D70(0xD0025, 1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0047B9C0 */
