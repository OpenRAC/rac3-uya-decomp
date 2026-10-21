#include "common.h"

/* localdecomp:start func_0035D738 */
extern s32 func_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004C4AB8(s32);
extern void func_0035D700(u8 *);
extern void func_00436220(u8 *);

void func_0035D738(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);

    if (*(s32 *)(pv + 0x24) == 0) {
        func_0032FE90(m + 16, 0, 0, 0, 0, 30, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    }
    func_004C4AB8(*(s32 *)(pv + 0x2C));
    func_0035D700(m);
    func_00436220(m);
}
/* localdecomp:end func_0035D738 */
