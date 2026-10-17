#include "common.h"
typedef struct { s32 id; s32 a; s32 b; } E_5BEF30;
extern E_5BEF30 D_004B2300[];
s32 func_005BEF30(s32 a0) {
    s32 i;
    for (i = 0; D_004B2300[i].id != -1; i++) {
        if (D_004B2300[i].id == a0) return 1;
    }
    return 0;
}
