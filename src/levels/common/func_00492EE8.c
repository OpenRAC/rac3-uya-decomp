#include "common.h"

/* localdecomp:start func_00492EE8 */
typedef struct Obj_492EE8 Obj_492EE8;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_492EE8 *);
} Vt_492EE8;
struct Obj_492EE8 {
    s32 pad;
    Vt_492EE8 *vt;
};
extern s32 D_001D91C8;
extern void func_004943A0(void);
extern void func_004A7368(s32, s32, s32);
extern Obj_492EE8 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_0047B7B8(s32);
void func_00492EE8(void) {
    Obj_492EE8 *o;
    func_004943A0();
    func_004A7368(20, 0, 0);
    o = func_00490968(0);
    o->vt->fn(o);
    func_0045CA60(1);
    func_0047B7B8(D_001D91C8);
}
/* localdecomp:end func_00492EE8 */
