#include "common.h"
typedef struct { u8 pad[0x50]; s32 x50; } R_664930;
typedef struct { u8 pad[0x324]; s32 x324; u8 pad328[8]; s32 x330; } O_664930;
extern s32 func_0065FDA0(O_664930 *, s32, s32);
extern R_664930 *func_0065FCD0(O_664930 *, s32, s32, s32);
extern void func_006601C8(R_664930 *, void *, s32);
void func_00664930(O_664930 *a0, s32 a1, u16 a2, s32 a3) {
    s32 buf[4];
    R_664930 *r;
    if (a2 == 6 || a2 == 14) {
        if (a0->x324 != 0) {
            return;
        }
        a0->x324 = 1;
    }
    if (func_0065FDA0(a0, a2, 0) != 0) {
        return;
    }
    r = func_0065FCD0(a0, a2, 0, -1);
    buf[0] = a1;
    func_006601C8(r, buf, 4);
    r->x50 = a3;
    a0->x330 = 0;
}
