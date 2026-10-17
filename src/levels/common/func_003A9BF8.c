#include "common.h"

typedef struct { f32 x; f32 y; f32 z; f32 w; } V4_3A9BF8;
typedef struct {
    u8 p0[0x10]; V4_3A9BF8 pos; u8 b20; u8 p21[0x47]; void *w68; u8 p6C[0x29]; u8 b95; u8 p96[0x14]; s16 hAA;
} M_3A9BF8;
typedef struct {
    u8 p0[0x5E]; u8 b5E; u8 p5F[0x1D1]; M_3A9BF8 *w230; s16 h234; u8 p236[0x22]; f32 f258; f32 f25C; s32 w260;
    u8 p264[0x1C]; f32 f280; f32 f284; f32 f288;
} V_3A9BF8;
extern void func_003A9D50(M_3A9BF8 *);
extern void func_00447B78(M_3A9BF8 *, s32);
extern s32 func_00443510(M_3A9BF8 *, s32, s32, s32);
extern void func_003A9EF0(M_3A9BF8 *);
extern f32 func_00436DD0(V4_3A9BF8 *, s32, f32, s32);
extern s32 func_00447470(V4_3A9BF8 *, s32);
extern void func_00447C40(M_3A9BF8 *, s32, f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_003A9BF8(M_3A9BF8 *m) {
    V_3A9BF8 *v = m->w68;
    s32 r;
    if (m->b20 == 0) {
        func_003A9D50(m);
    }
    func_00447B78(m, 1);
    func_00443510(m, 0, 0, 0);
    if (v->b5E != 0) {
        func_003A9EF0(m);
        return 1;
    }
    func_00447B78(m, 3);
    v->f280 = m->pos.x;
    v->f284 = m->pos.y;
    v->f288 = func_00436DD0(&m->pos, 0, 0.5f, 0);
    if (v->w230 != 0) {
        r = func_00447470(&v->w230->pos, v->w260);
    } else {
        if (m->b95 != 1) {
            return 0;
        }
        func_00447C40(m, -1, &v->f280, 0, 0, 1, 1, 0, 0, 0, v->f25C * 0.5f, v->f258, 1.0f);
        if (v->w230 != 0 && v->w230->hAA == 2404) {
            goto clear;
        }
        r = v->h234;
    }
    if (r == 0) {
clear:
        v->w230 = 0;
        v->h234 = 0;
    }
    return 0;
}
