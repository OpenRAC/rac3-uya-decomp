#include "common.h"

extern s32 D_001FD200[];
extern s32 D_001EAA38[];
extern s32 D_001D4B60;
extern u8 *D_001A5E80[];
extern u8 D_00142660[];
extern void func_00422838(s32);
extern void func_00422AB8(s32);
extern void func_00424008(s32, s32);

void func_00422BD0(s32 a0)
{
    u8 *p;
    u8 *q;
    s32 v;

    func_00422838(a0);
    func_00422AB8(a0);
    func_00424008(D_001FD200[0], D_001EAA38[0]);
    D_001D4B60 = a0;
    p = D_001A5E80[0];
    if (p != 0) {
        q = D_00142660;
        v = p[126] & 0x8F;
        p[126] = v;
        if ((u32)(*(s32 *)(q + 120) - 1) < 3) {
            p[126] = v | ((*(s32 *)(q + 120) << 4) | 0x80);
        }
    }
}
