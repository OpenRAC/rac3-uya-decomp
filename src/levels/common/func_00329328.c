#include "common.h"
extern void func_003B2F18(s32);
s32 func_00329328(u8 *a0) {
    if (a0[32] == 7) {
        func_003B2F18(0);
        return 1;
    }
    return 0;
}
