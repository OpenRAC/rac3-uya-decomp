#include "common.h"

extern s32 D_001DD330;
extern s32 D_001DD334[];
extern void func_0041AD58(s32, s32, s32);

void func_00350930(s32 a0, u8 *obj, s32 a2, s32 a3) {
    func_0041AD58(*(s32 *)(obj + 0x260), D_001DD330, a2);
    func_0041AD58(*(s32 *)(obj + 0x260), D_001DD334[0], a3);
}
