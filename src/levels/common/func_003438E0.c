#include "common.h"
s32 func_003438E0(u8 *a0) {
    s16 v = *(s16 *)(a0 + 170);
    if (v == 5559 || v == 5957 || v == 6583 || v == 6585 || v == 6698 || v == 6893 || v == 6895 || v == 6934) {
        return 1;
    }
    return 0;
}
