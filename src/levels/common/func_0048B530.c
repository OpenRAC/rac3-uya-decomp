#include "common.h"

typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};

extern s32 D_001D8CB8;
extern s32 D_001D8CBC;
extern s32 D_001D8CC0;
extern void func_00513928(s32);
extern Obj_0048B530 *func_00490968(s32);
extern void func_0045CA60(s32);
extern void func_0047B7B8(s32);

void func_0048B530(void)
{
    Obj_0048B530 *obj;

    func_00513928(16);
    func_00513928(17);
    func_00513928(18);
    obj = func_00490968(0);
    obj->vtbl->fn(obj);
    obj = func_00490968(1);
    obj->vtbl->fn(obj);
    func_0045CA60(1);
    func_0047B7B8(D_001D8CB8);
    func_0047B7B8(D_001D8CBC);
    func_0047B7B8(D_001D8CC0);
}
