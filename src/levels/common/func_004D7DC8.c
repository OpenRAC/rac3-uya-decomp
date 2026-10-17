#include "common.h"

extern void func_004AD3F0();

extern void func_004A9D48(void *);
extern void func_004ACA98(void *);
extern void func_004AD3F0();
void func_004D7DC8(u8 *p) {
    if (p[0x95] < 11) return;
    func_004A9D48(p);
    func_004ACA98(p);
    func_004AD3F0();
}
