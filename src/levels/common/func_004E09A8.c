#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
extern S_4E09A8 D_001A4BE0;
extern void func_0050CC50(void);
extern void func_0050CC88(void);
extern void func_0040BCB8(void *, void *, s32);
extern void func_00439610(Obj_4E09A8 *);
extern void func_0050D180(u128_t *, u128_t *, f32);
extern void func_004366B0(Obj_4E09A8 *, s32, u128_t *, f32, f32);
void func_004E09A8(void) {
    S_4E09A8 *p;
    u128_t v;
    f32 r;

    if (D_001A4BE0.b25E5 != 0) {
        func_0050CC50();
    } else {
        func_0050CC88();
    }
    p = &D_001A4BE0;
    p->f25C0->bA8 = 255;
    p->f25C0->q10 = p->q80;
    p->f25C0->qF0 = p->q90;
    func_0040BCB8(p->f25C0->fC0, p, 48);
    func_00439610(p->f25C0);
    if (p->h1F0 != 0) {
        return;
    }
    if (p->f25C0->f98 == 0) {
        return;
    }
    v = p->q80;
    func_0050D180(&v, &v, p->f274);
    func_004366B0(p->f25C0, 0, &v, p->f284, p->f270 - p->f274);
    r = p->f284 + 0.05f;
    v = p->q80;
    func_0050D180(&v, &v, r);
    func_004366B0(p->f25C0, 1, &v, p->f284, p->f270 - r);
    if (p->f25C4 == 163) {
        func_004366B0(p->f25C0, 0, &v, p->f284, p->f270 - r);
    }
}
