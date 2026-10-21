#include "common.h"

/* localdecomp:start func_00593620 */
typedef struct { u8 b[0x20]; } __attribute__((aligned(16))) T_593620;
extern s32 D_001D5D60;
extern void func_005908F8(s32);
extern void func_00592188(T_593620 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_005921C0(T_593620 *, s32, s32, s32, unsigned long, f32, f32);

s16 func_00593620(s32 x, s32 y, s32 w, s32 h, s32 c0, s32 c1, s32 c2) {
    T_593620 t;
    s32 saved = D_001D5D60;

    func_005908F8(1);
    func_00592188(&t, y, y + h, x, x + w, x, y, 16, 0);
    func_005921C0(&t, c0, c1, c2, 0x80000000UL, 1.0f, 1.0f);
    func_005908F8(saved);
    return *(s16 *)(t.b + 0xE);
}
/* localdecomp:end func_00593620 */
