#include "common.h"

extern s32 D_001D4BC0;
extern u8 D_00251370_003BB730[];
extern void func_00401978();
extern void func_00410468(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00401AA8();
void func_004D7578(void) {
    func_00401978(1);
    func_00410468(D_001D4BC0 >> 1, 0xA0, 0x80FFFFFF, D_00251370_003BB730, -1, 1.2f);
    func_00401AA8();
}
