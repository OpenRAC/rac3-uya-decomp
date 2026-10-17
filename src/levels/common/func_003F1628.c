#include "common.h"

typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_002F7700[];
void func_003F1628(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_002F7700[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
