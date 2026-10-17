#include "common.h"

extern void func_00447580();
extern void func_00447580(void *, void *);
extern void func_0040C8A0();

extern void func_0040C8A0(void *, void *);
extern void func_00447338(void *, void *);
extern void func_0040C8C0(void *, void *);
void func_00447580(void *a, void *b) {
    u8 m[0x40];
    func_0040C8A0(m, b);
    func_00447338(a, m);
    func_0040C8C0(b, m);
}
