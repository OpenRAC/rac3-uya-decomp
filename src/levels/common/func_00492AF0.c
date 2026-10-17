#include "common.h"

typedef struct S_492AF0 S_492AF0;
typedef struct { u8 pad[0xC]; void (*fC)(S_492AF0 *); } V_492AF0;
struct S_492AF0 { s32 f0; V_492AF0 *vt; };
extern s32 D_001D905C;
extern void func_00513928(s32);
extern S_492AF0 *func_00490968(s32);
extern s32 func_0045CA60(s32);
extern void func_0047B7B8(s32);

void func_00492AF0(void) {
    S_492AF0 *o;
    func_00513928(13);
    o = func_00490968(0);
    o->vt->fC(o);
    func_0045CA60(1);
    func_0047B7B8(D_001D905C);
}
