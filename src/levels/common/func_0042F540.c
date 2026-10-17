#include "common.h"

typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_00396538[];
extern s32 D_001D4CE8_00396538;
extern union { s32 i; S_396538 b; } D_001D4CEC_00396538;
void func_0042F540(void) {
    s32 *p = D_00142430_00396538;
    if (p[0x15C/4] == 2 && p[0x164/4] < 0) {
        p[0x164/4] = 7;
        p[4] = 0;
p[0x168/4] = 0;
        D_001D4CE8_00396538 = 0xD;
        D_001D4CEC_00396538.b.f11 = 0;
    }
}
