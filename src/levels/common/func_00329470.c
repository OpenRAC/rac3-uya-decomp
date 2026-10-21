#include "common.h"

/* localdecomp:start func_00329470 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_329470;
typedef struct {
    V4_329470 v0;
    f32 f10;
    f32 f14;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    u32 w20;
    u32 w24;
    u32 w28;
    u32 w2C;
    s32 i30;
    s32 i34;
    s32 i38;
    s16 h3C;
    s16 h3E;
} P_329470;
typedef struct {
    u8 pad0[16];
    V4_329470 v10;
    u8 pad20[3];
    u8 b23;
    u8 pad24[8];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[52];
    P_329470 *p68;
    u8 pad6C[12];
    s32 i78;
} O_329470;
extern O_329470 *func_00435E70(s32, s32);
extern void func_0040BCB8(void *, void *, s32);
extern void func_00438908(O_329470 *, s32, s32, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440848(s32);
extern void func_00439610(O_329470 *);
O_329470 *func_00329470(V4_329470 *a, V4_329470 *b, s32 c, s32 d, s32 e, s32 f, void *g, s32 h, s16 i, s16 j, f32 m, f32 n) {
    O_329470 *o;
    P_329470 *p;
    o = func_00435E70(0x1A50, 0x80);
    if (o != 0) {
        p = o->p68;
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b31 = 1;
        o->b23 = 0x80;
        p->i34 = e;
        p->i38 = h;
        o->f2C = o->f2C * m;
        p->h3C = i;
        p->h3E = j;
        if (g != 0) {
            func_0040BCB8(&p->w20, g, 16);
        } else {
            p->w20 = 0x2FFFFFFF;
            p->w24 = 0x2F808080;
            p->w28 = 0x2FC0C0C0;
            p->w2C = 0x2F404040;
        }
        func_00438908(o, 0x7F, 0x7F, 0x7F);
        o->v10 = *a;
        p->v0 = *b;
        p->f10 = func_004408C0(0.10471976548433304f, 0.20943953096866608f);
        p->f14 = func_004408C0(0.10471976548433304f, 0.20943953096866608f);
        p->h18 = c;
        p->h1A = c;
        p->i30 = d;
        if (d == 3) {
            p->i30 = func_00440848(3);
        }
        p->h1C = (s16)(o->f2C * 128.0f);
        p->h1E = (s16)(n * 128.0f);
        o->i78 = f;
        func_00439610(o);
    }
    return o;
}
/* localdecomp:end func_00329470 */
