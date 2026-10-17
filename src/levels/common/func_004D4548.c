#include "common.h"

extern void func_00429A70(s32);
extern void func_004D21B0(s32);
extern s32 func_004D3FB0(void);
extern void func_004D43A8(void);
extern s32 D_001DB90C;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_001E6E00_003B8700[];
s32 func_004D4548(void) {
    S_003B8700 *p = D_001E6E00_003B8700;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_004D21B0(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x60) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_00429A70(temp_4);
        }
        func_004D3FB0();
        func_004D43A8();
    } else {
        var_17 = 1;
        D_001DB90C = D_001DB90C + 1;
    }
    return var_17;
}
