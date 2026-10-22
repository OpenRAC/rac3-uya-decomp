#include "common.h"

/* localdecomp:start func_005E6028 */
extern void func_005E5F58(u8 *);
extern void func_005E6118(u8 *);
extern void func_005E61E0(u8 *);
extern void func_005E62A0(u8 *);
extern void func_005E67B0(u8 *);
extern void func_005E5F60(u8 *);
extern void func_005E4F58(void);
extern void func_005E6430(u8 *, s32);
extern void func_0060E1F0(s32, f32, f32);
extern void func_0060F4A0(s32, f32, f32);
extern void func_0060ECA0(s32, s32);

void func_005E6028(u8 *s, s32 a) {
    func_005E5F58(s);
    func_005E6118(s);
    func_005E61E0(s);
    func_005E62A0(s);
    func_005E67B0(s);
    func_005E5F60(s);
    func_005E4F58();
    if (*(s32 *)(s + 0x1C) == 0) {
        func_005E6430(s, a);
    }
    func_0060E1F0(0x4F00A8, *(f32 *)(s + 0x7C), *(f32 *)(s + 0x80));
    func_0060F4A0(0x4F00A8, *(f32 *)(s + 0x84), *(f32 *)(s + 0x88));
    func_0060E1F0(0x4F00B3, *(f32 *)(s + 0x7C), *(f32 *)(s + 0x80));
    func_0060F4A0(0x4F00B3, *(f32 *)(s + 0x84), *(f32 *)(s + 0x88));
    func_0060ECA0(0x4F00B3, s[0xA9]);
    func_0060F4A0(0x4F00AF, *(f32 *)(s + 0x60), *(f32 *)(s + 0x64));
}
/* localdecomp:end func_005E6028 */
