#include "common.h"

/* localdecomp:start func_004CFA88 */
extern void func_0011F0A0();
extern s32 func_0011F1E0();
extern s32 func_0011F1C0();
extern void func_0013D180();
void func_004CFA88(u8 *o, s32 a, s32 b, s32 c) {
    s32 s[4];
    s32 h;
    func_0011F0A0(0);
    s[0] = a;
    s[1] = *(s32 *)(o + 0x48);
    s[2] = b;
    s[3] = 0;
    do {
        h = func_0011F1E0(s, 1);
    } while (h == 0);
    do {
    } while (func_0011F1C0(h) >= 0);
    func_0013D180(b, c);
}
/* localdecomp:end func_004CFA88 */
