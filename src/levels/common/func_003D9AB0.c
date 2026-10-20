#include "common.h"
typedef struct {
    u8 pad[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 w20;
    f32 f24;
    u8 pad28[0x30 - 0x28];
} E_3D9AB0;
extern E_3D9AB0 D_002A2EC0[];
extern f32 func_004408C0(f32, f32);
void func_003D9AB0(void) {
    E_3D9AB0 *p;
    s32 i;
    for (i = 0; i < 64; i++) {
        p = &D_002A2EC0[i];
        if (p->w20 == 0) {
            p->w20 = 1;
            p->f10 = func_004408C0(-0.65f, 0.65f);
            p->f14 = func_004408C0(-0.65f, 0.65f);
            p->f18 = func_004408C0(0.3f, 1.0f);
            p->f1C = 1.0f;
            p->f24 = func_004408C0(0.08726647f, 0.15998852f);
            return;
        }
    }
}
