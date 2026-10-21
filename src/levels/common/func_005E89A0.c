#include "common.h"

/* localdecomp:start func_005E89A0 */
extern s32 func_0060F870(void);
extern s32 func_005E9830(void);
extern void func_005E9580(s32);
extern void func_005E7A30(s32);
extern void func_005F0E48(s32, s32, s32);
extern void func_00619968(s32, s32);
extern void func_005D3EF8(s32, s32);
extern void func_0060DE20(s32);
extern s32 func_005E3CB8(s32);
extern void func_0060F998(s32);

void func_005E89A0(s32 a) {
    s32 id = func_0060F870();
    s32 f = func_005E9830();
    func_005E9580(f);
    if (f & 0xA040) {
        func_005E7A30(a);
    } else if (f & 0x900) {
        func_005F0E48(4, 0, 0);
        func_00619968(func_0060F870(), 0);
        func_005D3EF8(func_0060F870(), 0);
        func_0060DE20(a);
    } else if (f & 0x910) {
        func_005F0E48(4, 0, 0);
        func_0060F998(func_005E3CB8(id));
        func_0060DE20(a);
    }
}
/* localdecomp:end func_005E89A0 */
