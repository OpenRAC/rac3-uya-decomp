#include "common.h"

typedef struct {
    u8 pad0[0x108];
    f32 x;
    f32 y;
    u8 pad110[0x1A0 - 0x110];
    s32 mask;
    u8 pad1A4[0x1B0 - 0x1A4];
    s32 buttons;
    u8 pad1B4[0x1D4 - 0x1B4];
    s32 flag;
} S_65E9B0_Pad;

typedef struct {
    u8 pad0[0x110];
    f32 x;
    f32 y;
    u8 pad118[0x300 - 0x118];
    s32 c300;
    s32 c304;
    u8 pad308[0x338 - 0x308];
    s16 h338;
    u8 pad33A[0x2468 - 0x33A];
    f32 f2468;
    f32 f246C;
    u8 pad2470[0x248C - 0x2470];
    f32 f248C;
    u8 pad2490[0x2534 - 0x2490];
    S_65E9B0_Pad *pad;
    u8 pad2538[0x2544 - 0x2538];
    s32 port;
} S_65E9B0;

extern void func_006396F8(S_65E9B0 *);
extern s32 func_005C2098(s32, s32);
extern f32 func_00644D58(S_65E9B0 *, f32 *);
extern f32 func_0058F430(f32 *);
extern f32 func_0058F980(f32, f32);

void func_0065E9B0(S_65E9B0 *p) {
    S_65E9B0_Pad *q;
    s32 b;
    s32 t;
    s32 v;

    func_006396F8(p);
    if ((p->pad->mask & func_005C2098(4, p->port)) == 0) {
        p->h338 = 0;
    }
    if (p->pad->flag != 0) {
        p->c300 = 0;
        p->c304++;
    } else {
        p->c304 = 0;
        p->c300++;
    }
    p->x = p->pad->x;
    p->y = -p->pad->y;
    p->f248C = func_00644D58(p, &p->x);
    if (func_0058F430(&p->x) < 0.25f) {
        q = p->pad;
        t = ((q->buttons >> 13) & 1) - ((q->buttons >> 15) & 1);
        p->x = (f32)t;
        b = q->buttons;
        t = (b >> 14) & 1;
        if (b & 0x1000) {
            v = 1 - t;
        } else {
            v = -t;
        }
        p->y = (f32)v;
    }
    p->f2468 = func_00644D58(p, &p->x);
    p->f246C = func_0058F980(p->x, p->y);
}
