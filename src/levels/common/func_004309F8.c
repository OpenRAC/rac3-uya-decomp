#include "common.h"

extern u8 *func_0053ED70(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_00532320(u8 *a0, s32 a1, s32 a2);
extern u8 *func_0053EDD8(s32 a0, s32 a1, s32 a2);
extern void func_00531F68(u8 *a0);

void func_004309F8(s32 id, s32 value) {
    u8 *p;

    func_00532320(func_0053ED70(id, 0, 0, 250), value, 8);
    p = func_0053EDD8(id, 1, 0);
    if (p != 0 && p[85] != 0) {
        func_00531F68(p);
    }
}
