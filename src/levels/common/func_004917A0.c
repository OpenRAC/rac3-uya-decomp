#include "common.h"

/* localdecomp:start func_004917A0 */
typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};
extern s32 D_001D8FC0;
extern void func_00513928(s32);
extern Obj_4917A0 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_0047B7B8(s32);
void func_004917A0(void) {
    Obj_4917A0 *o;
    func_00513928(13);
    func_00513928(14);
    func_00513928(20);
    o = func_00490968(0);
    o->vt->fn(o);
    func_0045CA60(1);
    func_0047B7B8(D_001D8FC0);
}
/* localdecomp:end func_004917A0 */
