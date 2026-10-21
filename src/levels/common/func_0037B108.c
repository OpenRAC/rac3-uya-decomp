#include "common.h"

/* localdecomp:start func_0037B108 */
extern f32 func_0040CEC8(f32, f32);
extern void func_004082B0(u8 *, s32, u32, s32, f32, f32, f32);
extern f32 func_00440978(void);

void func_0037B108(u8 *arg0) {
    u8 *sub;

    sub = *(u8 **)(arg0 + 104);
    *(f32 *)(sub + 16) = func_0040CEC8(*(f32 *)(sub + 16), 0.017453292f);
    func_004082B0(arg0 + 16, 57, 0x40505050, 1, 0.5f, 0.08f, func_0040CEC8(*(f32 *)(sub + 16) * 2.5f, 0.0f));
    func_004082B0(arg0 + 16, 42, 0x207F2040, 1, 0.5f, 0.08f, func_0040CEC8(-*(f32 *)(sub + 16) * 1.5f, 0.0f));
    func_004082B0(arg0 + 16, 44, 0x207F2040, 1, 0.5f, 0.08f, func_0040CEC8(*(f32 *)(sub + 16), 0.0f));
    func_004082B0(arg0 + 16, 49, 0x20FF7F00, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * 0.5f);
    func_004082B0(arg0 + 16, 49, 0x0020FF7F, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * -0.5f);
    func_004082B0(arg0 + 16, 47, 0x507F7F7F, 1, 0.11f, 0.08f, func_00440978());
}
/* localdecomp:end func_0037B108 */
