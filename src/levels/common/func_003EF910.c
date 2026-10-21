#include "common.h"

/* localdecomp:start func_003EF910 */
extern void (*D_001DFA40[])(void);
extern void (*D_001DFA50[])(void);
extern f32 D_001DF808[1];
extern f32 D_001DFBD0;
extern s32 D_001D52F0;
extern s32 D_001E00D4;
extern s32 D_00143950[];
extern void func_00400DF8(s32);
extern void func_004010D0(s32);
extern void func_004C1E50(s32);
extern void func_004C1D30(void);
extern void func_004C1CB0(void);
void func_003EF910(s32 a, s32 b, s32 c, s32 d) {
    f32 t;
    D_001D52F0 = a;
    if (D_001DFA40[a] != 0) {
        D_001DFA40[a]();
    }
    func_00400DF8(b);
    if (c == 0) {
        D_001E00D4 = 1;
    }
    t = (f32)*(volatile u32 *)0x10000800 / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_004010D0(a);
    D_001DF808[a] = D_001DFBD0 - t;
    if (d == 0) {
        func_004C1E50(1);
        func_004C1D30();
        func_004C1CB0();
    }
    if (D_001DFA50[a] != 0) {
        D_001DFA50[a]();
    }
}
/* localdecomp:end func_003EF910 */
