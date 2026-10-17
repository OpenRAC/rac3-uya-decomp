#include "common.h"

typedef struct {
    f32 x, y, z, w;
} Vec4;

typedef struct {
    char pad0[0x10];
    Vec4 pos;
    char pad20[0x68 - 0x20];
    void *vars;
} Moby;

extern s32 func_00440848(s32);
extern f32 func_00443C08(Vec4 *, Vec4 *);
extern void func_0040BE90(Vec4 *, void *, f32);
extern f32 func_004408C0(f32, f32);
extern void func_00465020(Vec4 *, Vec4 *, u32, f32, f32);

void func_0032B970(Moby *m) {
    Vec4 v;
    void *vars = m->vars;
    f32 d;

    if (func_00440848(5) != 0) {
        return;
    }
    d = func_00443C08(&m->pos, &v);
    func_0040BE90(&v, vars, 0.25f);
    func_00465020(&m->pos, &v, 0x88A0A0A0, func_004408C0(0.05f, 0.1f) * 210000.0f, d);
}
