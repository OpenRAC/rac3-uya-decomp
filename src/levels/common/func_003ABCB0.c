#include "common.h"

extern void func_003AC8B0(u8 *a);

void func_003ABCB0(u8 *a, u8 *b) {
    if (b[939] != 0) {
        a[149] = 0;
    } else {
        a[149] = 1;
    }
    b[943] = 0;
    func_003AC8B0(a);
}
