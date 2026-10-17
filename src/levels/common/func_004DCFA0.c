#include "common.h"

extern s32 D_001A6634[];
extern void func_004DF4A0(void);

void func_004DCFA0(void) {
    if (D_001A6634[0]) {
        func_004DF4A0();
    }
}
