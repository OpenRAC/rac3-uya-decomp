#include "common.h"

extern s32 func_004D1948();

extern void func_00135C00(u8 *);
s32 func_004D1948(u8 *p) {
    func_004D1308(p + 0x48);
    func_00135C00(p);
    return 1;
}
