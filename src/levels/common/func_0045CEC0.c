#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
} S_1CCFD0u;
extern S_1CCFD0u D_001CCFD0_0039DAE0;
extern s32 D_001D7E20_0039DAE0;
void func_0045CEC0(s32 a0, s32 a1) {
    if (D_001D7E20_0039DAE0 == 0) {
        D_001CCFD0_0039DAE0.f24 = a0;
        D_001CCFD0_0039DAE0.f28 = a1;
    }
}
