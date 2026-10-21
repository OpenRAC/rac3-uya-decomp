#include "common.h"

/* localdecomp:start func_004BEB00 */
typedef struct VObj_4BEB00 VObj_4BEB00;
typedef struct { u8 p0[12]; void (*f)(VObj_4BEB00 *); } VT_4BEB00;
struct VObj_4BEB00 { s32 p0; VT_4BEB00 *vt; };
extern s32 func_00494DD0(s32);
extern void func_00495180(s32);
extern void func_00513928(s32);
extern VObj_4BEB00 *func_00490968(s32);
extern void func_0045CA60(s32);
void func_004BEB00(void) {
    VObj_4BEB00 *o;
    func_00495180(func_00494DD0(0));
    func_00513928(27);
    o = func_00490968(0);
    o->vt->f(o);
    o = func_00490968(1);
    o->vt->f(o);
    func_0045CA60(1);
}
/* localdecomp:end func_004BEB00 */
