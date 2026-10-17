#include "common.h"

typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

extern void func_00513928(s32);
extern s32 func_00494DD0(s32);
extern void func_00495180(s32);
extern O_490778 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_0047B7B8(s32);
extern s32 D_001D8EC0;

void func_00490778(void) {
    O_490778 *o;
    func_00513928(16);
    func_00513928(17);
    func_00513928(20);
    func_00495180(func_00494DD0(0));
    o = func_00490968(0);
    o->vt->fn(o);
    func_0045CA60(1);
    func_0047B7B8(D_001D8EC0);
}
