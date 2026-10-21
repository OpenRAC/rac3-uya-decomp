#include "common.h"

/* localdecomp:start func_0047D188 */
typedef struct Obj_0047D188 Obj_0047D188;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0047D188 *);
} ObjVtbl_0047D188;
struct Obj_0047D188 {
    s32 pad0;
    ObjVtbl_0047D188 *vtbl;
};

extern s32 D_001D8348;
extern s32 D_001D4BA0[];
extern u8 D_001D5475[];
extern void func_00513928(s32);
extern s32 func_00494DD0(s32);
extern void func_00495180(s32);
extern Obj_0047D188 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_0047B7B8(s32);
extern void func_00423238(s32);
extern void func_003EFF58(s32);

void func_0047D188(void)
{
    Obj_0047D188 *obj;

    func_00513928(16);
    func_00513928(17);
    func_00495180(func_00494DD0(0));
    obj = func_00490968(0);
    obj->vtbl->fn(obj);
    func_0045CA60(1);
    func_0047B7B8(D_001D8348);
    if (D_001D4BA0[0] != D_001D5475[0]) {
        func_00423238(D_001D5475[0]);
    }
    func_0045CA60(1);
    func_003EFF58(0);
}
/* localdecomp:end func_0047D188 */
