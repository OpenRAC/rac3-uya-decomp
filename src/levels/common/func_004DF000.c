#include "common.h"
typedef struct { u8 pad0[1848]; s32 a; s32 b; u8 pad1[7808]; s32 c; s32 d; } Obj_004DF000;
extern Obj_004DF000 D_001A4BE0[];
extern void func_0044B860(s32, s32 *, s32 *, f32, f32, f32);
void func_004DF000(void) {
    Obj_004DF000 *o = D_001A4BE0;
    if (o->d == 129 || o->d == 80) {
        func_0044B860(o->c, &o->a, &o->b, 0.3f, 0.1163552924990654f, -1.0f);
    }
}
