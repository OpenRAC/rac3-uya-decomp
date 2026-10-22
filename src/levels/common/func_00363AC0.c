#include "common.h"

/* localdecomp:start func_00363AC0 */
typedef int Q_363AC0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_363AC0;

extern s32 func_00462650(void);
extern void func_00468218(void *, f32, f32, f32, f32);
extern s32 func_0044FC98(s32, s32);
extern void func_00451098(void *, s32, s32, s32);
extern void func_0041CA08(void *, void *, f32);
extern void func_00469700(void *, void *);
extern f32 func_0041C8C0(void *, void *);
extern f32 func_0041CDA8(f32, f32);
extern f32 func_0041D8C8(f32, f32);
extern s32 func_0041C368(void *);
extern void func_004513D8(void *, s32, s32);
extern s32 D_001D545C;

s32 func_00363AC0(u8 *o) {
    u8 *v;
    u8 *pos;
    V4_363AC0 t;
    Q_363AC0 a, b, r;

    v = *(u8 **)(o + 0x68);
    if (func_00462650() != 0) {
        func_00468218(o, 0.00444444455f, 0.100000009f, 0.00698131742f, 0.209439531f);
        if (o[0x43] != 3) {
            func_00451098(o, 3, 0, func_0044FC98(8, 0xE));
        }
    }
    t = *(V4_363AC0 *)(o + 0xC0);
    func_0041CA08(&t, &t, 2.0f);
    pos = o + 0x10;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_363AC0 *)(o + 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
    func_00469700(o, &t);
    if (D_001D545C != 0x16 && func_0041C8C0(pos, v + 0x220) < 15.0f &&
        func_0041D8C8(*(f32 *)(o + 0xF8), func_0041CDA8(*(f32 *)(v + 0x220) - *(f32 *)(o + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(o + 0x14))) < 0.17453292f) {
        goto set;
    }
    if (func_0041C368(v + 0x4E8) == 0) {
        return 0;
    }
    *(s32 *)(v + 0x4E8) = 1;
    func_004513D8(o, 0xD, -1);
    return 1;
set:
    func_004513D8(o, 0xD, -1);
    return 1;
}
/* localdecomp:end func_00363AC0 */
