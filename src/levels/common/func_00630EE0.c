#include "common.h"
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;
extern void func_0058F5B0(void *, f32);
void func_00630EE0(S630 *p) {
    func_0058F5B0(p->sub, p->f);
}
