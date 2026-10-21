#include "common.h"

/* localdecomp:start func_0048D088 */
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};

extern s32 D_001D8DA4;
extern s32 D_001D8DA8;
extern Obj *func_00490968(s32);
extern void func_0047B7B8(s32);

void func_0048D088(void) {
    Obj *o = func_00490968(1);
    o->vt->fn(o);
    func_0047B7B8(D_001D8DA4);
    func_0047B7B8(D_001D8DA8);
}
/* localdecomp:end func_0048D088 */
