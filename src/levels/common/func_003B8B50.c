#include "common.h"

extern void func_00418A60(s32);
extern s32 D_00142C34[];
extern s32 D_001D545C;

void func_003B8B50(s32 arg0) {
    if (D_001D545C == 8) {
        if (D_00142C34[0] & 0x200000) {
            func_00418A60(arg0);
        }
    }
}
