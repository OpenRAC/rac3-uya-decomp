#include "common.h"

extern void func_00429A70(s32);

typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_0016C580;
extern void func_004D3000(s32);
extern void func_00429A70(s32);
void func_004D4770(s32 a) {
    func_004D3000(a);
    D_0016C580.f64 = a;
    D_0016C580.f68 = 0;
    func_00429A70(0);
}
