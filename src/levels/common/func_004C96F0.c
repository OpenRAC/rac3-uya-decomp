#include "common.h"

extern void func_004C8D90();
extern u8 D_001DB230[];

extern u8 D_001DB230[];
extern void func_004C8D90();
void func_004C96F0(u8 *p) {
    *(void **)(p + 0x24) = D_001DB230;
    func_004C8D90(p);
}
