#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;

// Apply a single-zero address suffix identity here
extern S_1CCFD0 D_001CCFD0_0039CC78;

void func_0045BFD0(void) {
    // Route assignments to point directly to the single-zero alias target
    D_001CCFD0_0039CC78.f50 = 4;
    D_001CCFD0_0039CC78.fc8 = 4;
    D_001CCFD0_0039CC78.f78 = 4;
}
