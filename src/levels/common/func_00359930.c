#include "common.h"
typedef struct { u8 pad[0x3EC]; void *x3EC; } V_359930;
typedef struct { u8 pad[0x68]; V_359930 *x68; } O_359930;
extern void func_0043A7B8(void *, s32, s32, s32);
void func_00359930(O_359930 *o, s32 a, s32 b, s32 c) {
    V_359930 *v = o->x68;
    func_0043A7B8(o, a, b, c);
    func_0043A7B8(v->x3EC, a, b, c);
}
