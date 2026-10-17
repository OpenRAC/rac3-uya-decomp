#include "common.h"

extern u8 *func_0061A728();

u8 *func_0061A7C8(void) {
    u8 *p = func_0061A728();
    if (p != 0 && (p[3] & 0xF) == 0) {
        return p;
    }
    return 0;
}
