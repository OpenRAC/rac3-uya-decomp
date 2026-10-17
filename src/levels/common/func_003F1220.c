#include "common.h"

void func_0040BD58(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_001E2AC0[];
extern u8 D_001E5150[];
extern u8 D_001E5A90[];

void func_003F1220(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_001E5150;
    { S_00222500_0037E7D8 *p = &D_001E2AC0[arg0]; func_0040BD58(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_001E5A90;
    func_0040BD58(temp_s0, temp_s1 + (D_001E5A90 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
