#include "common.h"
extern s32 D_001F4048[];
extern void func_0042E978(s32 a0, u8 *a1, s32 a2);
extern void func_0042DC68(s32 a0, u8 *a1, s32 a2);
extern void func_0042DE98(s32 a0, u8 *a1);
void func_0042DBF0(s32 a0, u8 *a1, s32 a2) {
    func_0042E978(a0, a1, a2);
    if (D_001F4048[0] != 0) {
        if (a1[0] & 1) {
            func_0042DC68(a0, a1, a2);
        } else {
            func_0042DE98(a0, a1);
        }
    }
}
