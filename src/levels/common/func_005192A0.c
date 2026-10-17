#include "common.h"

extern void func_005193E8(void *, s32, s32);
extern void func_00519420(void *, s32, s32);
extern void func_00519480(void *, f32, f32);
extern void func_005194A8(void *, f32, f32);
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };

typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001DC168[];
extern void **func_005121A8();
extern void func_005193E8(void *, s32, s32);
extern void func_00519420(void *, s32, s32);
extern void func_00519480(void *, f32, f32);
extern void func_005194A8(void *, f32, f32);
O_3E8420 *func_005192A0(O_3E8420 *p) {
    func_005121A8(p);
    p->f8 = D_001DC168;
    p->f28 = 0x80808080;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    func_005193E8(p, 1, 1);
    func_005193E8(p, 2, 0);
    func_005193E8(p, 4, 1);
    func_005193E8(p, 8, 1);
    func_005193E8(p, 0x20, 0);
    func_005193E8(p, 0x10, 0);
    func_005193E8(p, 0x40, 0);
    func_005193E8(p, 0x80, 0);
    func_005193E8(p, 0x100, 0);
    func_00519420(p, 3, 3);
    func_00519480(p, 0.5f, 0.5f);
    func_005194A8(p, 1.0f, 1.0f);
    p->f28 = 0x40000000;
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    return p;
}
