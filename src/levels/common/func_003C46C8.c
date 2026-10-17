#include "common.h"

extern u8 D_001E2780[];
extern void func_00405140(void *p);
extern void func_00405170(void *p);
extern void func_004475E8(u8 *m, void *p, s32 a, s32 b, f32 f);
extern f32 func_004056F0(void *a, void *b);
extern void func_0043CE90(u8 *m);
extern f32 func_004065A0(f32 a, f32 b);
extern f32 func_00405AB8(f32 a);
extern s32 func_004066F8(s32 a, s32 b, f32 t);
extern void func_004442E8(u8 *m, void *p, s32 a, f32 b, f32 c);

void func_003C46C8(u8 *m) {
    u8 *v;
    f32 t;

    v = *(u8 **)(m + 104);
    func_00405140(v + 752);
    func_00405170(v + 756);
    if (*(u16 *)(m + 150) <= 0xFFFE) {
        *(u16 *)(m + 150) += 1;
    }
    func_004475E8(m, v + 608, 4, 1, 2.5f);
    if (m[49] != 0 && func_004056F0(D_001E2780, m + 16) < 1024.0f) {
        func_0043CE90(m);
        m[111] = 30;
    }
    t = func_004065A0(*(f32 *)(v + 1068), 0.058177646f);
    *(f32 *)(v + 1068) = t;
    *(s32 *)(m + 120) = func_004066F8(0x80A0A0A0, 0x60101010, (func_00405AB8(t) + 1.0f) * 0.5f);
    func_004442E8(m, v + 768, 0, 0.03f, 0.3f);
    func_004442E8(m, v + 896, 1, 0.03f, 0.3f);
}
