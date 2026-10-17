#include "common.h"
extern void func_005510E8(u8 *);
extern void func_005518A8(u8 *);
void func_00550D10(u8 *p) {
    if (p != 0 && p[32] != 254 && p[32] != 253) {
        func_005510E8(p);
        func_005518A8(p);
    }
}
