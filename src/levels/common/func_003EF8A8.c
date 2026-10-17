#include "common.h"
extern s32 D_001DB70C;
extern s32 func_0047EE90(s32 a0);
extern void func_0047F5C0(u8 *a0, s32 a1, s32 a2, s32 a3);
void func_003EF8A8(u8 *a0) {
    if (a0[66] < 2) {
        if (a0[96] & 2) {
            if (func_0047EE90(D_001DB70C - 1) == 0) {
                func_0047F5C0(a0, 1, 0, 20);
            } else if (a0[66] != 0) {
                func_0047F5C0(a0, 0, 0, 20);
            }
        }
    }
}
