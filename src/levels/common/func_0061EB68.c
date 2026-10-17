#include "common.h"
typedef int u128_61EB68 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[160]; u128_61EB68 cur; u8 pad1[7440]; u128_61EB68 hist[32]; u8 pad2[904]; s32 idx; s32 cnt;
} Obj_0061EB68;
void func_0061EB68(Obj_0061EB68 *o) {
    ((u128_61EB68 *)o)[o->idx + 476] = o->cur;
    o->idx = (o->idx + 1) % 32;
    o->cnt++;
    if (o->cnt > 32) o->cnt = 32;
}
