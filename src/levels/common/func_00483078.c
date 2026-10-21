#include "common.h"

/* localdecomp:start func_00483078 */
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};

extern s32 D_001D8584;
extern Obj *func_00490968(s32);
extern void func_0047B7B8(s32);
extern void func_00513928(s32);
extern void func_0045CA60(s32);

void func_00483078(void) {
    Obj *o;
    func_0047B7B8(D_001D8584);
    func_00513928(16);
    func_00513928(17);
    func_00513928(19);
    o = func_00490968(0);
    o->vt->fn(o);
    func_0045CA60(1);
    func_0045CA60(1);
}
/* localdecomp:end func_00483078 */
