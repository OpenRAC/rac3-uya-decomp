#include "common.h"

/* localdecomp:start func_0035A8A0 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;

extern void func_00359E50(S_35A8A0 *);
extern long func_00401CD0(s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BF68(f32 *);
extern void func_0040C658(f32 *, f32 *);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_00405A58(S_35A8A0 *, f32 *, s32);

void func_0035A8A0(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale) {
    S_35A8A0 s;

    func_00359E50(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00401CD0(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0040C490(dir[0], dir[1]);
    s.rot[1] = -func_0040C490(func_0040BF68(dir), dir[2]);
    s.rot[0] = 0.0f;
    func_0040C658(s.r[0], s.rot);
    s.r[3][3] = 1.0f;
    s.r[3][0] = pos[0];
    s.r[3][1] = pos[1];
    s.r[3][2] = pos[2];
    func_0040BE90(s.m[0], s.m[0], scale);
    func_0040BE90(s.m[1], s.m[1], scale);
    func_0040BE90(s.m[2], s.m[2], scale);
    func_0040BE90(s.m[3], s.m[3], scale);
    func_00405A58(&s, s.r[0], 0);
}
/* localdecomp:end func_0035A8A0 */
