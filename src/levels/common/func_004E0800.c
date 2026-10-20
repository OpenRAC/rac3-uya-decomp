#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;

extern S_001A4BE0 D_001A4BE0;
extern void func_004DF000(void);
extern void func_004DF068(void);
extern void func_0040BCB8(void *, void *, s32);
extern void func_00439610(void *);
extern void func_0050D180(s128 *, s128 *, f32);
extern void func_004366B0(void *, s32, s128 *, f32, f32);
extern s32 func_004E5540(void);

void func_004E0800(void) {
    s128 v;
    u8 *o;
    f32 d;
    f32 f;

    D_001A4BE0.obj[168] = 255;
    *(s128 *)(D_001A4BE0.obj + 16) = D_001A4BE0.v128;
    func_004DF000();
    *(s128 *)(D_001A4BE0.obj + 240) = D_001A4BE0.v144;
    func_004DF068();
    func_0040BCB8(D_001A4BE0.obj + 192, &D_001A4BE0, 48);
    func_00439610(D_001A4BE0.obj);
    o = D_001A4BE0.obj;
    if (*(u8 **)(o + 36) != 0 && (*(u8 **)(o + 36))[6] != 0) {
        o[99] = 16;
    } else {
        D_001A4BE0.obj[99] = 16;
    }
    if (D_001A4BE0.h496 != 0) {
        return;
    }
    if (*(s32 *)(D_001A4BE0.obj + 152) == 0) {
        return;
    }
    v = D_001A4BE0.v128;
    func_0050D180(&v, &v, D_001A4BE0.f628);
    d = D_001A4BE0.f624 - D_001A4BE0.f628;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_004366B0(D_001A4BE0.obj, 0, &v, D_001A4BE0.f644, d);
    f = D_001A4BE0.f644 + 0.05f;
    if (D_001A4BE0.w9676 == 4) {
        f += 0.15f;
    }
    if (func_004E5540() != 0) {
        f = D_001A4BE0.f628;
    }
    v = D_001A4BE0.v128;
    func_0050D180(&v, &v, f);
    d = D_001A4BE0.f624 - f;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_004366B0(D_001A4BE0.obj, 1, &v, D_001A4BE0.f644, d);
}
