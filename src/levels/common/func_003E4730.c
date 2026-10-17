#include "common.h"
extern u8 *D_001DF334;
void func_003E4730(void) {
    u8 *m;
    u8 *pv;
    for (m = D_001DF334; m != 0; m = *(u8 **)(pv + 100)) {
        pv = *(u8 **)(m + 104);
        if ((u32)(m[32] - 2) < 3 && pv[96] != 0) {
            s32 v = *(s32 *)(*(u8 **)(m + 36) + 16);
            *(s32 *)(m + 156) = 1;
            *(s32 *)(m + 152) = v;
        }
    }
}
