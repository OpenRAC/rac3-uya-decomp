#include "common.h"
typedef struct { u8 pad[0xF8]; f32 f; } S5DA;
extern f32 D_001D8198;
extern void func_00590318(f32, f32);
void func_005DADC8(S5DA *p) {
    func_00590318(p->f, D_001D8198);
}
