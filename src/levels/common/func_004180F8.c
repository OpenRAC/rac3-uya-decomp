#include "common.h"
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S12_004180F8;
extern S12_004180F8 D_001A7E18[];
void func_004180F8(void) {
    s32 i;
    for (i = 0; i < 356; i++) {
        D_001A7E18[i].c &= 0x7FFFFFFF;
    }
}
