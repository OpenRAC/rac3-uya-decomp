#include "common.h"

/* localdecomp:start func_0030CC18 */
extern u8 *D_001E17A4;
extern void func_0030DCE0(u8 *, u8 *);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern void func_0030D828(u8 *, s32, s32, s32, s32, f32, f32);

void func_0030CC18(u8 *m) {
    s32 off = 0;
    s32 i = 11;
    u8 *e;
    s32 a;

    do {
        e = (u8 *)(off + (s32)D_001E17A4);
        i--;
        off += 160;
        if (*(u8 **)(e + 140) == m) {
            func_0030DCE0(m, e);
            if (*(s32 *)(e + 148) == 0) {
                a = func_00440878(80, 96);
                func_0030D828(e + 48, 0x103080, a, 49, 2, 0.5f, func_00440978());
                a = func_00440878(80, 96);
                func_0030D828(e + 48, 0xFFFFFF, a, 49, 2, 0.3f, func_00440978());
            }
        }
    } while (i >= 0);
}
/* localdecomp:end func_0030CC18 */
