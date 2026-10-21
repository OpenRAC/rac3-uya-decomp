#include "common.h"

extern void func_00401978(s32);

extern s32 D_001DF9F4[4] __attribute__((section(".sdata")));
extern s32 D_001E10E8[4] __attribute__((section(".sdata")));
extern s32 D_001DFA00[4] __attribute__((section(".sdata")));
extern long D_001E7D00[];
extern s32 D_001DFD98[4] __attribute__((section(".sdata")));
extern s32 D_001DFDA4[4] __attribute__((section(".sdata")));
extern volatile s32 D_001DFDA8[4] __attribute__((section(".sdata")));
extern s32 D_001DF9FC;
extern s32 D_001D4BB4[4] __attribute__((section(".sdata")));
extern s32 D_001D4BB0[4] __attribute__((section(".sdata")));
extern unsigned long D_001D6180, D_001D6188;
extern s32 D_001D6190;
extern s32 D_001A1ED0[];
extern void func_0040D530(void);
void func_00401978(s32 a) {
    s32 n;
    s32 t;
    s32 u;
    s32 i;
    s32 c;
    s32 j;
    long *p;
    t = D_001E10E8[0];
    D_001DF9F4[0] = t;
    t += 0x10;
    D_001E10E8[0] = t;
    u = D_001D4BB4[0];
    n = D_001DFA00[0];
    D_001D4BB0[0] = u;
    D_001DF9FC = 0;
    if (n > 0) {
        p = D_001E7D00;
        for (c = n; c != 0; c--) {
            *p = 0;
            p += 2;
        }
    }
    D_001D6180 = 0;
    D_001D6188 = 0;
    D_001D6190 = 0;
    if (a == 0) {
        for (i = 0; i < *(s32 *)(D_001DFD98[0] + 0x44); i++) {
            u16 *h = (u16 *)((i << 3) + D_001DFDA4[0] + 4);
            if (*h >= (D_001A1ED0[1] >> 8)) {
                *h = 0;
            }
        }
        for (j = 0; j < *(s32 *)(D_001DFD98[0] + 0x24); j++) {
            *(u16 *)(D_001DFDA8[0] + j * 8 + 4) = 0;
        }
    }
    func_0040D530();
}
