#include "common.h"

extern s32 D_001D4CE8[];
extern s32 D_001D4CEC[];

extern void (*D_001D759C)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_0042FB10(void) {
    if (D_001D759C != 0) {
        D_001D759C();
        D_001D759C = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
