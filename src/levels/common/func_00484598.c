#include "common.h"
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
extern s32 D_001D8708;
extern s32 D_001D8710;
extern void func_0047B7B8(s32 a0);
extern Obj_484598 *func_00490968(s32 a0);
extern void func_0045CA60(s32 a0);
extern void func_00513928(s32 a0);
void func_00484598(void) {
    Obj_484598 *o;
    func_0047B7B8(D_001D8708);
    func_0047B7B8(D_001D8710);
    o = func_00490968(0);
    o->vt->fn(o);
    o = func_00490968(1);
    o->vt->fn(o);
    func_0045CA60(1);
    func_00513928(16);
    func_00513928(19);
}
