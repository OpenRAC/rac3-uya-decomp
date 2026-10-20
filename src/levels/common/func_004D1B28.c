#include "common.h"

extern void func_004D0A58(u8 *);
extern void func_004D1FB8(u8 *);
extern void func_004D1B90(u8 *);
extern void func_004D1998(u8 *, s32);
extern u8 *D_001E1238;

void func_004D1B28(u8 *a) {
    func_004D0A58(a + 72);
    func_004D1FB8(D_001E1238);
    func_004D1B90(a);
    while (*(volatile s32 *)(D_001E1238 + 12) != 0) {
    }
    func_004D1998(a, 3);
}
