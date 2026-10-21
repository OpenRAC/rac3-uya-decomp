#include "common.h"

/* localdecomp:start func_004CE458 */
typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

extern f32 *func_004C8AD0(Obj_004CE458 *);
extern void func_004C9188(Obj_004CE458 *, s32, s32);
extern void func_004C91C8(Obj_004CE458 *, s32, s32);
extern void func_004C99C8(Obj_004CE458 *, s32);

void func_004CE458(Obj_004CE458 (*base)[26], s32 i, s32 j, s32 x, s32 y, s32 z) {
    Obj_004CE458 *o = &base[i][j];

    func_004C8AD0(o)[0] = x;
    func_004C8AD0(o)[1] = y;
    func_004C9188(o, z, z);
    func_004C91C8(o, z, z);
    func_004C99C8(o, z << 24);
    o->vt->fn8(o);
}
/* localdecomp:end func_004CE458 */
