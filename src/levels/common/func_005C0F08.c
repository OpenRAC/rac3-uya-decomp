#include "common.h"
typedef struct {
    u8 pad0[844];
    s32 idx;
    s32 pad350;
    s32 arr[7];
} T_5C0F08;
extern T_5C0F08 D_00225900;
s32 func_005C0F08(T_5C0F08 *a0) {
    if (a0 != 0) {
        return a0->arr[(a0->idx + 6) % 7];
    }
    return D_00225900.arr[(D_00225900.idx + 6) % 7];
}
