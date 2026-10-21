#include "common.h"

/* localdecomp:start func_0051BB08 */
extern s32 func_00519410();
extern void func_00519458();
extern s32 func_00519410(void *, s32);
extern f32 D_001DC128;
extern s32 func_0011A264(void *, s32, s32);

typedef struct { f32 x0, y0, x1, y1; } Rect_3EAC88;
typedef struct {
    u8 pad0[0x10];
    f32 x, y;       /* 0x10 */
    f32 w, h;       /* 0x18 */
    f32 ox, oy;     /* 0x20 */
    u8 pad28[0x14];
    s32 f3C;        /* 0x3C */
    u8 pad40[8];
    f32 f48, f4C;   /* 0x48 */
    u8 pad50[8];
    s32 state;      /* 0x58 */
    f32 cw, ch;     /* 0x5C */
} S_3EAC88;
extern f32 D_001DC128;
extern f32 D_001DC140;
extern void func_0040D548(s32);
extern s32 func_00410190(s32, s32, f32);
extern f32 func_0040FFE8(s32, s32, s32, f32);
extern void func_00512360(f32 *, f32 *);
extern s32 func_0011A264(void *, s32, s32);

void func_0051BB08(S_3EAC88 *p, Rect_3EAC88 *clip, Rect_3EAC88 *out, s32 align) {
    f32 scale, sx, sy, ax, ay, w, h;
    s32 ha, va;
    f32 s, a, b, x0, y0;
    Rect_3EAC88 r;

    switch (p->state) {
    case 1:
        func_0040D548(1);
        break;
    case 2:
        func_0040D548(0);
        break;
    case 0:
    default:
        func_0040D548(0);
        break;
    }
    if (p->f3C != 0) {
        scale = (f32)func_00410190(p->f3C, -1, 1.0f) / D_001DC128;
    } else {
        scale = 0.0f;
    }
    sy = 2.0f;
    ay = 0.0f;
    sx = 2.0f;
    ax = 0.0f;
    if (align) {
        ha = 0;
        va = 0;
        func_00519458(p, &ha, &va);
        if (ha != 3) {
            if (ha == 1) {
                ax = 1.0f;
            } else {
                sx = -2.0f;
                ax = 1.0f;
            }
        }
        if (va != 3) {
            if (va == 2) {
                sy = -2.0f;
                ay = 1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    }
    p->cw = p->w;
    p->ch = p->h;
    if (func_0051B8E8(p, 1)) {
        if (p->f3C != 0) {
            s = func_0040FFE8(p->f3C, -1, (s32)(p->f48 * D_001DC128), p->f4C);
        } else {
            s = 0.0f;
        }
        p->cw *= s;
        p->ch *= s;
    }
    if (func_00519410(p, 0x2000)) {
        a = 0.0f;
        b = a;
        func_00512360(&a, &b);
        p->cw *= a;
        p->ch *= b;
    }
    w = p->cw * scale / sx;
    h = p->ch * D_001DC140 / sy;
    out->x0 = p->x - w + w * ax;
    out->y0 = p->y - h + h * ay;
    out->x1 = p->x + w + w * ax;
    out->y1 = p->y + h + h * ay;
    if (clip->x0 == 0.0f && clip->x1 == 1.0f && clip->y0 == 0.0f && clip->y1 == 1.0f) {
        return;
    }
    x0 = out->x0;
    y0 = out->y0;
    out->x0 = (clip->x1 - clip->x0) * x0 + clip->x0;
    out->y0 = (clip->y1 - clip->y0) * y0 + clip->y0;
    out->x1 += out->x0 - x0;
    out->y1 += out->y0 - y0;
    if (func_00519410(p, 0x40)) {
        f32 dx = p->ox;
        f32 dy = p->oy;
        func_0011A264(&r, 0, 0x10);
        r = *out;
        r.x0 += dx;
        r.x1 += dx;
        r.y0 += dy;
        r.y1 += dy;
        out->x0 = r.x0 < out->x0 ? r.x0 : out->x0;
        out->x1 = out->x1 < r.x1 ? r.x1 : out->x1;
        out->y1 = out->y1 < r.y1 ? r.y1 : out->y1;
        out->y0 = r.y0 < out->y0 ? r.y0 : out->y0;
    }
}
/* localdecomp:end func_0051BB08 */
