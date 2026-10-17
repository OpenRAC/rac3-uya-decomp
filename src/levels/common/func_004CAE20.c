#include "common.h"

typedef struct { f32 x, y; } V2_003A7690;
typedef struct { s32 a, b, c, d, e, f; } T6_003A7690;
typedef struct {
    f32 *pos;        /* 0x000 */
    u8 pad4[4];
    u32 *color;      /* 0x008 */
    u32 *font;       /* 0x00C */
    u8 sub10[0x3C];  /* 0x010 */
    u8 sub4C[0x13C]; /* 0x04C */
    s32 w;           /* 0x188 */
    s32 h;           /* 0x18C */
    s32 count;       /* 0x190 */
    u8 pad194[8];
    s32 xoff;        /* 0x19C */
    u8 pad1A0[4];
    s32 mode;        /* 0x1A4 */
    u8 pad1A8[8];
    f32 f1B0;        /* 0x1B0 */
    u8 pad1B4[4];
    s32 text[1];     /* 0x1B8 */
} O_003A7690;
extern V2_003A7690 D_001DB4A0[];
extern V2_003A7690 D_001DB4A8[];
extern f32 D_001DB4B0;
extern T6_003A7690 D_001DB4B8[];
extern T6_003A7690 D_001DB4D0[];
extern s32 D_001D55E8;
extern void func_00404D78_003A7690(s32, s32, s32, s32, s32, u32 *);
extern void func_004C8AF8(void *, f32, f32, f32, f32);
extern void func_004C8C20(void *, f32, f32, f32, f32);
extern void func_004C8FC0(void *);
extern void func_0040D548(s32);
extern void func_0040DBE0_003A7690(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_004CAE20(void *arg0) {
    O_003A7690 *o = arg0;
    u32 cols[4];
    V2_003A7690 a, b;
    T6_003A7690 t1, t2;
    f32 s;
    u32 c, alpha;
    s32 ix, iy, i, lh;

    alpha = *o->color >> 24;
    if ((s32)alpha > 0x60) alpha = 0x60;
    c = *o->color & 0xFFFFFF;
    c |= alpha << 24;
    cols[0] = c;
    cols[1] = c;
    cols[2] = c;
    cols[3] = c;
    func_00404D78_003A7690(o->pos[0] - o->w, o->pos[1] - o->h, o->pos[0] + o->w + 2.0f, o->pos[1] + o->h, 0xFFFFF0, cols);
    a = D_001DB4A0[0];
    b = D_001DB4A8[0];
    s = 1.0f;
    if (o->mode == 0) s = D_001DB4B0;
    lh = 16;
    i = 0;
    func_004C8AF8(o->sub10, o->pos[0] - o->w - a.x, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_004C8C20(o->sub10, -s, s, 0.0f, 0.0f);
    func_004C8FC0(o->sub10);
    func_004C8AF8(o->sub10, o->pos[0] + o->w + a.x + 1.0f, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_004C8C20(o->sub10, s, s, 0.0f, 0.0f);
    func_004C8FC0(o->sub10);
    func_004C8AF8(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_004C8C20(o->sub4C, s, s, 0.0f, 0.0f);
    func_004C8FC0(o->sub4C);
    func_004C8AF8(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_004C8C20(o->sub4C, -s, s, 0.0f, 0.0f);
    func_004C8FC0(o->sub4C);
    func_004C8AF8(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_004C8C20(o->sub4C, s, -s, 0.0f, 0.0f);
    func_004C8FC0(o->sub4C);
    func_004C8AF8(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_004C8C20(o->sub4C, -s, -s, 0.0f, 0.0f);
    func_004C8FC0(o->sub4C);
    ix = o->pos[0] - o->w + o->xoff;
    iy = o->pos[1] - o->h;
    t1 = D_001DB4B8[0];
    t2 = D_001DB4D0[0];
    switch (o->mode) {
    case 0:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                s32 old = D_001D55E8;
                func_0040D548(1);
                func_0040DBE0_003A7690(*o->font, o->text[i], -1, ix + t2.c, iy + t2.d + i * lh, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
                func_0040D548(old);
            }
        }
        break;
    case 1:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                func_0040D548(1);
                func_0040DBE0_003A7690(*o->font, o->text[i], -1, ix + t1.c, iy + t1.d + i * lh + 2, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
            }
        }
        break;
    case 2:
        break;
    }
}
