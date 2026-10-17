#include "common.h"

extern void func_004D7320(void *);

extern void func_004AD3F0();
extern s32 func_004D6198(void);
extern void func_004D67E8(void *);
extern void func_004D6CE0(void *);
void func_004D7320(void *p) {
    func_004AD3F0(p);
    if (func_004D6198()) func_004D67E8(p);
    func_004D6CE0(p);
}
