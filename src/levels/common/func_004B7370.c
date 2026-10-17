#include "common.h"
extern u8 D_0014271E[];
extern u8 D_001427A8[];
s32 func_004B7370(u32 i) {
    if (i >= 8) {
        i -= 8;
        if (i < 8) {
            return (D_001427A8[0] >> i) & 1;
        }
        return 0;
    }
    return (D_0014271E[0] >> i) & 1;
}
