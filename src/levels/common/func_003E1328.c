#include "common.h"
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[2];
    u8 f23;
    u8 pad24[68];
    s32 *vars;
} Obj_003E1328;
extern u8 D_001D66B0[];
extern s32 func_0040BA90(s32 *);
extern void func_004A7200(s32, s32, Obj_003E1328 *);
extern void func_0044ED60(Obj_003E1328 *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_00436220(Obj_003E1328 *);
void func_003E1328(Obj_003E1328 *o) {
    s32 *v;
    v = o->vars;
    if (o->state == 0) {
        v[0]++;
        o->f23 = v[0] * 2;
        if (v[0] >= 30) {
            o->state = 1;
        }
    } else if (o->state == 1) {
        if (func_0040BA90(v) != 0) {
            func_004A7200(0, 0, o);
            func_0044ED60(o, 63, D_001D66B0, 255, 300, 0, 0, 35, 0, 3, 1.5f, 3.0f, 1.5f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_00436220(o);
        }
    }
}
