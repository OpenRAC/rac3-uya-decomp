#include "common.h"
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
extern S_0030CD20 *D_001E17A0;
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(S_0030CD20 *, S_0030CD20 *, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_0013D3E0(void);
void func_0030CD20(s32 a0) {
    S_0030CD20 *p;
    s32 i;
    s32 v;
    for (i = 0; i < 64; i++) {
        p = &D_001E17A0[i];
        if (p->w16 == 0) {
            p->v[0] = func_004408C0(-1.0f, 1.0f);
            p->v[1] = func_004408C0(-1.0f, 1.0f);
            p->v[2] = func_004408C0(-1.0f, 1.0f);
            func_0040C0F0(p, p, p->f20);
            v = func_00440878(20, 50);
            p->w24 = v;
            p->w28 = v;
            p->f32_ = func_004408C0(-1.0f, 1.0f);
            p->w16 = a0;
            p->w36 = 0;
            p->f40 = (func_0013D3E0() & 1) ? -1.0f : 1.0f;
            p->f44 = 1.0f;
            p->f20 = func_004408C0(0.7f, 0.9f);
            return;
        }
    }
}
