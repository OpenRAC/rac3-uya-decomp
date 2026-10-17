#include "common.h"

extern s32 D_001E0188_0037E368[2];
extern s32 D_001E0190_0037E368[2];
extern s32 D_001DFBC8_0037E368;
extern f32 func_0040C3C8(f32);
extern void func_0040D020(s32, s32, f32);
void func_00440BA8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 *cur = &D_001E0190_0037E368[a3];
    s32 *cnt = &D_001E0188_0037E368[a3];
    f32 v;
    s32 h;
    f32 s;
    if (*cur != D_001DFBC8_0037E368) {
        *cur = D_001DFBC8_0037E368;
        *cnt += 1;
    }
    if (a4 != 0) {
        *cnt = 0;
    }
    switch (a5) {
    case 0:
        h = *cnt % (a2 * 2);
        if (h >= a2) {
            v = 1.0f - ((f32)(h - a2) / (f32)a2);
        } else {
            v = (f32)h / (f32)a2;
        }
        break;
    case 1:
        s = func_0040C3C8(((f32)(*cnt % a2) / (f32)a2) * 3.1415925f);
        v = s * s;
        v = v * v;
        break;
    default:
        v = 0.5f;
        break;
    }
    func_0040D020(a1, a0, v);
}
