#include "common.h"

/* localdecomp:start func_0032D350 */
typedef int Q_32D350 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32D350;
typedef struct {
    V4_32D350 v[4];
    u32 c[4];
    u8 pad50[0x20];
    unsigned long tag[4];
} B_32D350;
typedef struct { V4_32D350 r[4]; } M_32D350;
typedef struct { u8 pad[0x140]; V4_32D350 pos; } S_1E2900;
typedef struct { u8 b0; u8 b1; u8 pad[238]; } S_2C5640;
extern void func_0032CA20(B_32D350 *);
extern long func_00401CD0(s32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFE8(V4_32D350 *, V4_32D350 *);
extern f32 func_00440978(void);
extern void func_0040C658(M_32D350 *, V4_32D350 *);
extern void func_0040C0F0(V4_32D350 *, V4_32D350 *, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(V4_32D350 *, V4_32D350 *, f32);
extern void func_00405A58(B_32D350 *, M_32D350 *, s32);
extern u8 D_001425D5[];
extern S_2C5640 D_002C5640[];
extern S_1E2900 D_001E2900;

void func_0032D350(s32 a0, V4_32D350 *pos) {
    B_32D350 buf;
    M_32D350 m;
    V4_32D350 rot;
    V4_32D350 d;
    Q_32D350 x, y;
    S_1E2900 *g;
    u32 c;
    s32 r;
    f32 half;
    f32 s;

    func_0032CA20(&buf);
    buf.tag[1] = func_00401CD0(11);
    buf.tag[2] = 0xFF9000000260;
    buf.tag[3] = 0x8000000048;
    buf.tag[0] = 0;
    r = func_00440878(48, 64);
    if ((D_001425D5[0] + D_002C5640)->b1 >= 2) {
        u32 k = (r << 24) + 0x806060;
        buf.c[3] = k;
        buf.c[2] = k;
        buf.c[1] = k;
        buf.c[0] = k;
    } else {
        c = (r << 24) + 0x80;
        buf.c[3] = c;
        buf.c[2] = c;
        buf.c[1] = c;
        buf.c[0] = c;
    }
    g = &D_001E2900;
    rot.w = 0;
    half = 0.5f;
    rot.z = func_0040C490(g->pos.x - pos->x, g->pos.y - pos->y);
    rot.y = -func_0040C490(func_0040BFE8(pos, &g->pos), g->pos.z - pos->z);
    rot.x = func_00440978();
    func_0040C658(&m, &rot);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(g->pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    func_0040C0F0(&d, &d, 0.25f);
    m.r[3].x = pos->x;
    m.r[3].y = pos->y;
    m.r[3].z = pos->z;
    m.r[3].w = 1.0f;
    s = func_004408C0(0.03f, 0.0625f);
    func_0040BE90(&buf.v[0], &buf.v[0], s);
    func_0040BE90(&buf.v[1], &buf.v[1], s);
    func_0040BE90(&buf.v[2], &buf.v[2], s);
    func_0040BE90(&buf.v[3], &buf.v[3], s);
    func_00405A58(&buf, &m, 0);
    func_0040BE90(&buf.v[0], &buf.v[0], half);
    func_0040BE90(&buf.v[1], &buf.v[1], half);
    func_0040BE90(&buf.v[2], &buf.v[2], half);
    func_0040BE90(&buf.v[3], &buf.v[3], half);
    c = (func_00440878(64, 127) << 24) + 0x1F1F1F;
    buf.c[3] = c;
    buf.c[2] = c;
    buf.c[1] = c;
    buf.c[0] = c;
    func_00405A58(&buf, &m, 0);
    func_0040BE90(&buf.v[0], &buf.v[0], half);
    func_0040BE90(&buf.v[1], &buf.v[1], half);
    func_0040BE90(&buf.v[2], &buf.v[2], half);
    func_0040BE90(&buf.v[3], &buf.v[3], half);
    c = (func_00440878(64, 127) << 24) + 0x7F7F7F;
    buf.c[3] = c;
    buf.c[2] = c;
    buf.c[1] = c;
    buf.c[0] = c;
    func_00405A58(&buf, &m, 0);
}
/* localdecomp:end func_0032D350 */
