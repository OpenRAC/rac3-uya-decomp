#include "common.h"

extern void func_00457288(s32, s32, s32, s32, s32);
extern void func_00412C70(s32, s32, s32);
extern s32 D_001D9764;
extern s32 D_001D9760;
extern s32 D_001DFA08[];
extern u8 *D_001E009C[];
extern u8 *D_001E00A4[];

void func_0049FC48(s32 a0, s32 a1) {
    u8 *p;
    u8 *end;
    func_00457288(7, 1, 0, 0, 0);
    D_001D9764 = a1;
    D_001D9760 = a0;
    D_001DFA08[0] = 0;
    func_00412C70(0, 0, 0);
    end = D_001E00A4[0];
    for (p = D_001E009C[0]; p < end; p += 256) {
        *(u16 *)(p + 52) |= 0x80;
    }
}
