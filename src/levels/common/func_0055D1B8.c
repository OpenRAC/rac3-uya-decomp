#include "common.h"

typedef struct {
    u8 pad0[0x55];
    u8 b55;
} S_55D1B8;

extern void func_0066B3C0(s32 a0, s32 a1, s32 a2, s32 a3);
extern S_55D1B8 *func_0066B428(s32 a0, s32 a1, s32 a2);
extern void func_0065FE10(S_55D1B8 *p);

void func_0055D1B8(s32 a0) {
    S_55D1B8 *p;
    func_0066B3C0(a0, 1, 0, 250);
    p = func_0066B428(a0, 2, 0);
    if (p != 0 && p->b55 != 0) {
        func_0065FE10(p);
    }
}
