#include "common.h"
typedef struct {
    u8 pad0[80];
    u8 b;
    u8 pad51[47];
} E_5F09E0;
typedef struct {
    u8 pad0[128];
    E_5F09E0 e[52];
} T_5F09E0;
extern T_5F09E0 D_001FE1A0;
s32 func_005F09E0(s32 a0) {
    s32 n = a0 == 0 ? 42 : 52;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_001FE1A0.e[i].b == 0) {
            break;
        }
    }
    return i == n ? -1 : i;
}
