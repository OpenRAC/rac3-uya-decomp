#include "common.h"

typedef struct {
    s32 a, b, c, d;
} S_0046C990;

extern S_0046C990 D_00143230[];

void func_0046C990(s32 a0) {
    if (D_00143230[a0].d == 0) {
        D_00143230[a0].d = 1;
    }
}
