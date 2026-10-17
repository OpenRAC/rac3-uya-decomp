#include "common.h"

typedef void (*fn_3A2780)(u8 *);

extern fn_3A2780 *func_00438468(s32, s32);
extern void func_003A30C8(u8 *);
extern void func_00436220(u8 *);

void func_003A2780(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3A2780 *tbl;
    if (*(s32 *)(pv + 576) != 0) {
        tbl = func_00438468(6625, 108);
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else if (*(s32 *)(pv + 1052) != 0) {
        func_003A30C8(a0);
    } else {
        func_00436220(a0);
    }
}
