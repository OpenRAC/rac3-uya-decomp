#include "common.h"

typedef void (*fn_3C5D58)(u8 *);

extern fn_3C5D58 *func_004519E0(s32, s32);
extern void func_003C52C0(u8 *);
extern void func_0044F860(u8 *);
extern u8 *D_001A65C0[];

void func_003C5D58(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3C5D58 *tbl;
    if (*(s32 *)(pv + 464) != 0) {
        tbl = func_004519E0(6625, 108);
        if (a1 == 0 && D_001A65C0[0] == a0) {
            func_003C52C0(a0);
        }
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else {
        func_0044F860(a0);
    }
}
