#include "common.h"

/* localdecomp:start func_004B4A10 */
extern void func_004B4A10(s32, s32, s32, s32);

extern s32 D_001DAB50;
extern s32 D_001DAB54;
extern s32 D_001DAB58;
extern s32 D_001DAB5C;
extern s32 D_001DAB60;
extern void func_0040BBF8(s32, s32);
void func_004B4A10(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001DAB58 = c;
    D_001DAB5C = d;
    D_001DAB50 = a;
    D_001DAB54 = b;
    D_001DAB60 = 0;
    func_0040BBF8(a, b);
    func_0040BBF8(D_001DAB58, D_001DAB5C);
}
/* localdecomp:end func_004B4A10 */
