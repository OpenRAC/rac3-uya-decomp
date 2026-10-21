#include "common.h"

/* localdecomp:start func_00346D90 */
typedef int Q_00346D90 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00346D90;
typedef struct {
    V4_00346D90 pos;
    void *obj;
    s32 f14;
    u8 f18;
    u8 f19;
    u16 f1A;
    f32 f1C;
    s32 f20;
    u8 pad[0xC];
} Query_00346D90;
typedef struct {
    u8 pad0[0x28];
    s32 f28;
    u8 pad1[0x10];
    V4_00346D90 v40;
} Inner_00346D90;
typedef struct {
    u8 pad0[0x10];
    V4_00346D90 v10;
    u8 pad1[0x48 - 0x20];
    u8 pad2[0x20];
    Inner_00346D90 *p68;
    u8 pad3[0xAA - 0x6C];
    u16 hAA;
} Obj_00346D90;
typedef struct { u8 pad[0x6C]; f32 f6C; u8 pad2[0xF0 - 0x70]; } Ent_00346D90;
extern u8 D_0014262F[];
extern Ent_00346D90 D_002C5640[];
extern s32 D_001A71A0[];
extern V4_00346D90 D_001EAAA0;
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F8448(V4_00346D90 *, V4_00346D90 *, s32, s32, Query_00346D90 *);
extern void func_00346EF0(Obj_00346D90 *, V4_00346D90 *);
extern s32 func_004435E8(s32);
s32 func_00346D90(Obj_00346D90 *obj, V4_00346D90 *a1) {
    Query_00346D90 q;
    V4_00346D90 p30;
    V4_00346D90 v40;
    Inner_00346D90 *in;
    Q_00346D90 x, y, r;
    s32 d;
    V4_00346D90 *vp;
    in = obj->p68;
    q.obj = obj;
    q.f14 = 0x10000;
    q.f20 = 1;
    q.f1C = ((Ent_00346D90 *)((s32)D_002C5640 + D_0014262F[0] * 0xF0))->f6C;
    *(Q_00346D90 *)&q.pos = *(Q_00346D90 *)in;
    func_0040C0F0(&q, &q, 1.0f);
    q.f1A = obj->hAA;
    q.pos.w = 5627.9248f;
    q.f18 = 1;
    q.f19 = 1;
    if (in->f28 == 1) {
        *(Q_00346D90 *)&p30 = *(Q_00346D90 *)&in->v40;
    } else {
        *(Q_00346D90 *)&p30 = *(Q_00346D90 *)&obj->v10;
    }
    if (func_003F8448(a1, &p30, 0, D_001A71A0[0], &q) == 0) {
        return 0;
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p30));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a1));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v40) : "j"(y));
    func_0040C0F0(&v40, &v40, 0.25f);
    vp = &D_001EAAA0;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v40));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*vp));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v40) : "j"(r));
    func_00346EF0(obj, &v40);
    d = ((s32 *)vp)[-2];
    if (d == 0 || func_004435E8(d)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00346D90 */
