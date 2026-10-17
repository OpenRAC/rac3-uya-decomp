#include "common.h"

extern u8 *func_004C8E40(u8 *);
u8 *func_004C9CB0(u8 *p) {
    func_004C8E40(p + 0x10);
    func_004C8E40(p + 0x4C);
    return p;
}
