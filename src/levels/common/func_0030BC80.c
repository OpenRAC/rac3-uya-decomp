#include "common.h"

/* localdecomp:start func_0030BC80 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_30BC80;

typedef struct {
    u8 pad0[9];
    u8 b9;
} Part_30BC80;

extern f32 func_004408C0(f32 lo, f32 hi);
extern s32 func_00440848(s32 n);
extern void func_0040C638(void *m, Vec_30BC80 *rot);
extern void func_0040C2D0(Vec_30BC80 *out, void *in, void *m);
extern void func_0040C0F0(Vec_30BC80 *out, Vec_30BC80 *in, f32 s);
extern f32 func_00440918(f32 lo, f32 hi);
extern s32 func_0013D3E0(void);
extern Part_30BC80 *func_00467DA8(f32 a, Vec_30BC80 *pos, s32 type, f32 b, f32 c, u32 col, s32 d, s32 dir, Vec_30BC80 *vel, s32 e);

void func_0030BC80(Vec_30BC80 *pos, void *dir_in, s32 n, u32 col) {
    Vec_30BC80 vel;
    Vec_30BC80 old;
    Vec_30BC80 rot;
    f32 mtx[12];
    f32 scale;
    s32 dir;
    s32 i;
    Part_30BC80 *p;

    for (i = 0; i < n; i++) {
        scale = func_004408C0(1.75f, 2.0f);
        dir = func_00440848(2);
        if (dir == 0) {
            dir--;
        }
        rot.w = 0.0f;
        rot.y = func_004408C0(-1.5707964f, 1.5707964f);
        rot.x = func_004408C0(-1.5707964f, 1.5707964f);
        rot.z = func_004408C0(-1.5707964f, 1.5707964f);
        func_0040C638(mtx, &rot);
        func_0040C2D0(&vel, dir_in, mtx);
        func_0040C0F0(&vel, &vel, 0.05f);
        vel.z += 0.05f;
        *(s128 *)&old = *(s128 *)pos;
        pos->x += func_00440918(0.0f, 0.15f);
        pos->y += func_00440918(0.0f, 0.15f);
        pos->z += func_00440918(0.0f, 0.15f);
        if (func_0013D3E0() & 1) {
            p = func_00467DA8(scale * 0.1f, pos, 60, scale, 0.002f, col | 0x4F000000, 0, dir, &vel, 1);
            if (p) {
                p->b9 = 116;
            }
            p = func_00467DA8(scale * 0.07f, pos, 60, scale * 0.7f, 0.002f, 0x7FFFFFFF, 1, -dir, &vel, 1);
            if (p) {
                p->b9 = 116;
            }
        } else {
            p = func_00467DA8(scale * 0.1f, pos, 60, scale, 0.002f, col | 0x4F000000, 0, dir, &vel, 1);
            if (p) {
                p->b9 = 116;
            }
            p = func_00467DA8(scale * 0.07f, pos, 60, scale * 0.7f, 0.002f, 0x7FFFFFFF, 1, -dir, &vel, 1);
            if (p) {
                p->b9 = 116;
            }
        }
    }
}
/* localdecomp:end func_0030BC80 */
