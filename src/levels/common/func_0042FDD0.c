#include "common.h"

typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 b6 : 7;
    u32 b13 : 1;
    u32 b14 : 18;
} Flags_42FDD0;

extern s32 D_00142438[];
extern s32 D_001D4CE8;
extern Flags_42FDD0 D_001D4CEC;

void func_0042FDD0(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8 = 4;
        return;
    }
    if (D_001D4CEC.b5 || D_001D4CEC.b13) {
        D_001D4CE8 = 14;
        D_001D4CEC.b5 = 0;
        D_001D4CEC.b13 = 0;
    }
}
