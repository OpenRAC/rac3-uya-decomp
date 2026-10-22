#include "common.h"

/* localdecomp:start func_005DACE8 */
typedef struct { u8 pad[0x40]; s32 a40[8]; s32 a60[18]; s32 aA8[8]; } T_5DACE8;
typedef struct { u8 pad[0x20C]; T_5DACE8 *f20C; } S_5DACE8;
typedef struct { u8 pad[0xC60]; s32 fC60; s32 fC64; } Q_5DACE8;
extern S_5DACE8 D_00352A40;
extern u8 *D_0024C05C;
extern s32 func_005DACB0(u8 *);
extern void func_005D9EF8(u8 *, s32, s32);

void func_005DACE8(u8 *p, s32 a1, s32 a2) {
    u8 *e;
    s32 k = (*(Q_5DACE8 **)(p + 0x2558))->fC64;

    if (k >= 0 && D_00352A40.f20C->aA8[k] == *(s32 *)(p + 0x2548)) {
        e = D_0024C05C + (D_00352A40.f20C->a60[k] << 8);
    } else {
        (*(Q_5DACE8 **)(p + 0x2558))->fC64 = -1;
        (*(Q_5DACE8 **)(p + 0x2558))->fC60 = func_005DACB0(p);
        e = D_0024C05C + (D_00352A40.f20C->a40[(*(Q_5DACE8 **)(p + 0x2558))->fC60] << 8);
    }
    func_005D9EF8(e, a1, a2);
}
/* localdecomp:end func_005DACE8 */
