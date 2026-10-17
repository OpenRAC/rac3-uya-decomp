#include "common.h"

extern char *D_001E1150[];

void func_004C76F0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        char *p = D_001E1150[i];
        if (p != 0) {
            *(s32 *)(p + 152) = 0;
        }
    }
}
