#include "common.h"

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430[];
extern s32 D_001D6674;
extern s32 D_001DFBC4;
extern s32 D_001D545C[4] __attribute__((section(".sdata")));
extern s32 D_001D4CF0[4] __attribute__((section(".sdata")));
extern s32 D_001D4CEC[4] __attribute__((section(".sdata")));
extern void func_00417CF0(s32 *);
extern void func_00417EB8(void);
extern void func_00432CB0(s32, s32);
void func_00417DA0(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8 *p;
    func_00417CF0(&x);
    y = x;
    D_001D6674 = 1;
    D_001D4CF0[0] = D_001D545C[0];
    D_001DFBC4 = y;
    if (y == -1) {
        p = D_00142430;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC[0] &= ~0x200;
    }
    if (b != 0) {
        func_00417EB8();
        if (x != 0x18) func_00432CB0(0, D_001DFBC4);
        else func_00432CB0(0, D_001D4CF0[0]);
    }
}
