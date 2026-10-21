#include "common.h"

/* localdecomp:start func_003CA118 */
typedef struct O_3CA118 O_3CA118;
typedef struct { u8 pad[0x491]; u8 x491; u8 pad492[0x550 - 0x492]; O_3CA118 *x550; } V_3CA118;
struct O_3CA118 { u8 pad[0x10]; u8 x10[0x58]; V_3CA118 *x68; u8 pad6C[0xF0 - 0x6C]; u8 xF0[0x10]; };
extern void func_00407180(O_3CA118 *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_00441FB8(O_3CA118 *, s32, s32);
void func_003CA118(O_3CA118 *a0) {
    V_3CA118 *v = a0->x68;
    func_00407180(a0, a0->x10, a0->xF0, 1, 2, 3, 45, 45, 0xFF8040, 0x8F1010);
    func_00407180(v->x550, v->x550->x10, v->x550->xF0, 1, 2, 3, 45, 45, 0xFF8040, 0x8F1010);
    v->x491 = 1;
    func_00441FB8(a0, 3, -1);
}
/* localdecomp:end func_003CA118 */
