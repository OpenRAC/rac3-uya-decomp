#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 pad20[896 - 32];
    f32 c[3];
    f32 pad38C;
    f32 a[3];
    f32 pad39C;
    f32 b[3];
    f32 pad3AC;
    f32 m[3][4];
    u128_t pos2;
    u8 pad3F0[1064 - 1008];
    f32 fov;
    u8 pad42C[1081 - 1068];
    u8 mode;
    u8 pad43A[1120 - 1082];
} Cam_0057A0B8;

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 unk20[48];
} View_0057A0B8;

extern s32 *D_002412A0;
extern Cam_0057A0B8 D_0024DF80[];
extern View_0057A0B8 D_0024DF00;
extern f32 D_0025D870[];
extern f32 func_0058F8D0(f32);
extern f32 func_0058F8B8(f32);
extern void func_0058F250(void *, void *, s32);

void func_0057A0B8(s32 idx)
{
    Cam_0057A0B8 *e;
    f32 h;

    if (*D_002412A0 >= 2) {
        if (D_0024DF80[idx].mode == 1) {
            h = D_0024DF80[idx].fov * 0.5f;
            D_0025D870[0] = func_0058F8D0(h) / func_0058F8B8(h);
        } else {
            D_0025D870[0] = 0.62f;
        }
    }
    e = &D_0024DF80[idx];
    e->m[0][0] = -e->a[0];
    e->m[1][0] = -e->a[1];
    e->m[2][0] = -e->a[2];
    e->m[0][1] = -e->b[0];
    e->m[1][1] = -e->b[1];
    e->m[2][1] = -e->b[2];
    e->m[0][2] = e->c[0];
    e->m[1][2] = e->c[1];
    e->m[2][2] = e->c[2];
    e->pos2 = e->pos;
    D_0024DF00.pos = e->pos;
    D_0024DF00.unk10 = D_0024DF80[idx].unk10;
    func_0058F250(D_0024DF00.unk20, D_0024DF80[idx].c, 48);
}
