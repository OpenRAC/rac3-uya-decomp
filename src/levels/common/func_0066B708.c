#include "common.h"

/* localdecomp:start func_0066B708 */
extern u8 D_001A5E50[];
extern u8 *func_00619D10(s32);
extern s32 *func_00665D48(s32);
extern s32 *func_00669930(s32);
extern s32 func_0066B7F8(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_0066B708(u8 *self, s32 a, s32 b, s32 who, s32 c) {
    u8 *g = D_001A5E50;
    s32 id;
    u8 *pl;
    s32 *e;

    if (*(s32 *)(g + 8) < 0 || *(s32 *)(g + 0x170) != 0) {
        return -1;
    }
    id = 0;
    pl = func_00619D10(who);
    if (pl != 0) {
        id = *(s32 *)(*(u8 **)(*(u8 **)(pl + 0x2558) + 4) + 0x38);
    } else {
        e = func_00665D48(who);
        if (e != 0 || (e = func_00669930(who)) != 0) {
            id = *e;
        }
    }
    return func_0066B7F8(*(s32 *)(*(u8 **)(*(u8 **)(self + 0x2558) + 4) + 0x38), id, a, 1, 0, 0, b, c);
}
/* localdecomp:end func_0066B708 */
