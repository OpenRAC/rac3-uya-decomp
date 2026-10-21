#include "common.h"

typedef int Q_4076F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4076F8;
typedef struct { V_4076F8 m[4]; } M_4076F8;
typedef struct {
    V_4076F8 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} P_4076F8;
typedef struct {
    u8 pad0[0x140];
    V_4076F8 v140;
} D_4076F8;

/* localdecomp:start func_004076F8 */
extern D_4076F8 D_001E2900;

extern void func_004075A8(P_4076F8 *, s32, s32, s32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFE8(V_4076F8 *, V_4076F8 *);
extern f32 func_00440978(void);
extern void func_0040C658(M_4076F8 *, V_4076F8 *);
extern void func_0040C0F0(V_4076F8 *, V_4076F8 *, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(V_4076F8 *, V_4076F8 *, f32);
extern void func_00405A58(P_4076F8 *, M_4076F8 *, s32);

void func_004076F8(V_4076F8 *p, s32 col, s32 flag) {
    P_4076F8 q;
    M_4076F8 m;
    V_4076F8 rot;
    V_4076F8 dir;
    Q_4076F8 x, y;
    f32 s;
    u32 c;

    q.v[0].z = -2.0f;
    q.v[1].z = 2.0f;
    q.v[2].z = -2.0f;
    q.v[3].z = 2.0f;
    q.v[0].y = -2.0f;
    q.v[2].y = 2.0f;
    q.v[1].y = -2.0f;
    q.v[3].y = 2.0f;
    q.v[0].x = 0.0f;
    q.v[1].x = 0.0f;
    q.v[2].x = 0.0f;
    q.v[3].x = 0.0f;
    q.v[0].w = 1.0f;
    q.v[1].w = 1.0f;
    q.v[2].w = 1.0f;
    q.v[3].w = 1.0f;
    func_004075A8(&q, 0x2C, 1, 0x80);
    c = (func_00440878(0x30, 0x40) << 24) | ((col >> 17) << 16) | ((col >> 9) & 0xFF00) | ((col >> 1) & 0xFF);
    q.col[3] = c;
    q.col[2] = c;
    q.col[1] = c;
    q.col[0] = c;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    rot.w = 0.0f;
    rot.z = func_0040C490(D_001E2900.v140.x - p->x, D_001E2900.v140.y - p->y);
    rot.y = -func_0040C490(func_0040BFE8(p, &D_001E2900.v140), D_001E2900.v140.z - p->z);
    rot.x = func_00440978();
    func_0040C658(&m, &rot);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2900.v140));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(x));
    func_0040C0F0(&dir, &dir, 0.25f);
    m.m[3].x = p->x + dir.x;
    m.m[3].y = p->y + dir.y;
    m.m[3].z = p->z + dir.z;
    m.m[3].w = 1.0f;
    s = func_004408C0(0.3f, 0.4f);
    if (flag) {
        s += s;
    }
    func_0040BE90(&q.v[0], &q.v[0], s);
    func_0040BE90(&q.v[1], &q.v[1], s);
    func_0040BE90(&q.v[2], &q.v[2], s);
    func_0040BE90(&q.v[3], &q.v[3], s);
    func_00405A58(&q, &m, 0);
    func_0040BE90(&q.v[0], &q.v[0], 0.5f);
    func_0040BE90(&q.v[1], &q.v[1], 0.5f);
    func_0040BE90(&q.v[2], &q.v[2], 0.5f);
    func_0040BE90(&q.v[3], &q.v[3], 0.5f);
    c = col + (func_00440878(0x40, 0x7F) << 24);
    q.col[3] = c;
    q.col[2] = c;
    q.col[1] = c;
    q.col[0] = c;
    func_00405A58(&q, &m, 0);
    func_0040BE90(&q.v[0], &q.v[0], 0.5f);
    func_0040BE90(&q.v[1], &q.v[1], 0.5f);
    func_0040BE90(&q.v[2], &q.v[2], 0.5f);
    func_0040BE90(&q.v[3], &q.v[3], 0.5f);
    c = (func_00440878(0x40, 0x7F) << 24) + 0x7F7F7F;
    q.col[3] = c;
    q.col[2] = c;
    q.col[1] = c;
    q.col[0] = c;
    func_00405A58(&q, &m, 0);
}
/* localdecomp:end func_004076F8 */
