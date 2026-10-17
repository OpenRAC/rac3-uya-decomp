#include "common.h"
extern s32 D_001D545C[];
extern void func_0047A2A8(s32 a0);
extern void func_004A7368(s32 a0, s32 a1, s32 a2);
extern s32 func_0047B380(void);
extern void func_00513758(s32 a0);
extern void func_005120B8(s32 a0);
void func_004871F8(s32 a0, s32 a1) {
    if (a1 < 2) {
        return;
    }
    if (a1 == D_001D545C[0]) {
        return;
    }
    if (a1 == 3 && D_001D545C[0] == 6) {
        return;
    }
    func_0047A2A8(a1);
    func_004A7368(20, 0, 0);
    func_00513758(func_0047B380());
    func_005120B8(a0);
}
