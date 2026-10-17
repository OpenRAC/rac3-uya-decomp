#include "common.h"

typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;

extern s32 D_001D8BE8;
extern void func_0047B7B8(s32);
extern O_00489FA8 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_00513928(s32);

void func_00489FA8(void) {
    O_00489FA8 *o;
    func_0047B7B8(D_001D8BE8);
    o = func_00490968(0);
    o->vt->f12(o);
    func_0045CA60(1);
    func_00513928(15);
    func_00513928(16);
    func_00513928(17);
    func_00513928(18);
    func_00513928(19);
    func_00513928(20);
}
