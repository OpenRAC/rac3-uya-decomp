#include "common.h"

typedef struct {
    u8 pad0[1388];
    s32 a;
    s32 b;
    u8 pad1[76];
} Elem00225900;

extern void func_001999A8(s32);
extern void func_001999B0(s32);
extern void func_00674BD0(void);
extern Elem00225900 D_00225900[8];

void func_00619C88(void) {
    Elem00225900 *p;
    func_001999A8(0);
    func_001999B0(0);
    func_00674BD0();
    p = D_00225900;
    do {
        p->a = 0;
        p->b = 0;
        p++;
    } while ((s32)p < (s32)(D_00225900 + 8));
}
