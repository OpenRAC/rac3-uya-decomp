#include "common.h"

/* localdecomp:start func_0049CBD0 */
extern u8 *D_001D52FC[];
extern void func_0049D6C8(s32);
extern void func_0049C368(s32);
extern void func_004A7368(s32, s32, s32);
extern s32 func_0048DCD8(s32);
extern void func_00513758(s32);
extern void func_005120B8(s32);

void func_0049CBD0(s32 arg0)
{
    s32 flags;

    flags = *(s32 *)(D_001D52FC[0] + 452);
    func_0049D6C8(flags);
    if (flags & 0xA040) {
        func_0049C368(arg0);
    } else if (flags & 0x910) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0048DCD8(0));
        func_005120B8(arg0);
    }
}
/* localdecomp:end func_0049CBD0 */
