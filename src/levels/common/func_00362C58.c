#include "common.h"

/* localdecomp:start func_00362C58 */
typedef int Q_00362C58 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00362C58;

extern s32 func_0041C368(void *);
extern f32 func_0041C8C0(void *, void *);
extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern f32 func_0041CDA8(f32, f32);
extern s32 func_0044FC98(s32, s32);
extern f32 func_0044FCE0(f32, f32);
extern f32 func_0044FD98(void);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern void func_00454CC0(void *, void *, f32, f32, f32, f32, s32);
extern s32 func_00462650(void *);
extern s32 func_00462998(void *, s32);
extern void func_00466D38(void *, void *, f32);
extern void func_00468218(void *, f32, f32, f32, f32);

static __inline__ void pick_00362C58(u8 *v, u8 *p) {
    f32 a = func_0044FD98();
    f32 r = func_0044FCE0(2.0f, 6.0f);
    Q_00362C58 x, y;
    __asm__("sq $0, %0" : "=m"(*(V4_00362C58 *)(v + 0x340)));
    *(f32 *)(v + 0x340) = func_0041CCE0(a) * r;
    *(f32 *)(v + 0x344) = func_0041CCF8(a) * r;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_00362C58 *)(v + 0x340)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_00362C58 *)(v + 0x320)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_00362C58 *)(v + 0x340)) : "j"(x));
    if (*(s32 *)(v + 0x31C) != -1 && func_00462998(p, *(s32 *)(v + 0x31C)) == 0) {
        *(Q_00362C58 *)(v + 0x340) = *(Q_00362C58 *)(v + 0x320);
    }
}

s32 func_00362C58(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    V4_00362C58 *p;
    f32 *rot;
    f32 t;

    if (func_00462650(o) != 0) {
        if (o[0x43] != 2) {
            func_00451098(o, 2, 0, 10);
        }
        pick_00362C58(v, v + 0x340);
        *(s32 *)(v + 0x360) = func_0044FC98(300, 530);
        func_00468218(o, 0.0016666667f, 0.033333335f, 0.0069813174f, 0.20943953f);
    }
    if (*(s32 *)(v + 0x4E4) == 0) {
        p = (V4_00362C58 *)(v + 0x340);
        rot = (f32 *)(o + 0xF8);
        func_00466D38(o, p, *rot);
        t = func_0041CDA8(*(f32 *)(v + 0x340) - *(f32 *)(o + 0x10), *(f32 *)(v + 0x344) - *(f32 *)(o + 0x14));
        func_00454CC0(rot, v + 0x370, t, 0.0012605157f, 0.0012605157f, 0.029088823f, 0);
        if (func_0041C8C0(o + 0x10, p) < 0.75f) {
            pick_00362C58(v, (u8 *)p);
        }
        if (func_0041C368(v + 0x360) == 0) {
            return 0;
        }
    }
    func_004513D8(o, 3, -1);
    return 1;
}
/* localdecomp:end func_00362C58 */
