#include "common.h"

/* localdecomp:start func_00400DF8 */
typedef struct {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C;
    s32 f20;
    f32 f24;
} E_400DF8;
typedef struct {
    u8 pad0[176];
    f32 f176;
    u8 pad180[416 - 180];
    f32 f416;
    f32 f420;
    u8 pad424[528 - 424];
    f32 f528;
    f32 f532;
    f32 f536;
    f32 f540;
    u8 pad544[576 - 544];
    s32 f576;
    s32 f580;
    s32 f584;
    s32 f588;
    u8 pad592[616 - 592];
    s32 f616;
} G_400DF8;

extern E_400DF8 D_002C50B0[];
extern s16 D_001CFEC0[];
extern G_400DF8 D_001E7600;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BC8;
extern s32 D_001D4BCC;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D4BD8;
extern s32 D_001D4BDC;
extern s32 D_001D52F0;
extern s32 D_001D7B80;
extern s32 D_001D7B88[2];
extern void func_005155F0(f32, f32);
extern void func_004C20A8(s32, s32, s32, s32);
extern void func_003FFAC8(void);
extern void func_004AD960(s32);

void func_00400DF8(s32 idx) {
    E_400DF8 *e = &D_002C50B0[idx];
    s32 w, h, x, y, ox, oy, x0, y0, x1, y1;
    f32 a, b;

    w = (s32)(D_001CFEC0[168] * e->f10);
    h = (s32)(D_001CFEC0[169] * e->f14);
    D_001D4BC0 = w;
    *(volatile s32 *)&D_001D4BC4 = h;
    func_005155F0(w, h);

    x = (s32)(D_001CFEC0[168] * (e->f18 + 0.5f));
    y = (s32)(D_001CFEC0[169] * (e->f1C + 0.5f));
    ox = x + 2048;
    oy = y + 2048;
    ox -= D_001CFEC0[168] >> 1;
    oy -= D_001CFEC0[169] >> 1;
    ox -= D_001D4BC0 >> 1;
    oy -= D_001D4BC4 >> 1;
    ox <<= 4;
    oy <<= 4;
    D_001D4BD8 = ox + (D_001D4BC0 << 4);
    D_001D4BDC = oy + (D_001D4BC4 << 4);
    D_001D4BC8 = x;
    D_001D4BCC = y;
    D_001D4BD0 = ox;
    D_001D4BD4 = oy;
    x0 = (s32)(D_001CFEC0[168] * e->f0);
    y0 = (s32)(D_001CFEC0[168] * e->f4) - 1;
    x1 = (s32)(D_001CFEC0[169] * e->f8);
    y1 = (s32)(D_001CFEC0[169] * e->fC) - 1;
    D_001E7600.f576 = x0;
    D_001E7600.f580 = y0;
    D_001E7600.f584 = x1;
    D_001E7600.f588 = y1;
    func_004C20A8(x0, y0, x1, y1);

    a = D_001CFEC0[168] * (e->f10 * 0.5f);
    b = D_001CFEC0[169] * (e->f14 * 0.5f);
    D_001E7600.f176 *= e->f24;
    D_001E7600.f528 = a;
    D_001E7600.f616 = e->f20;
    D_001E7600.f536 = a * 4.0f;
    D_001E7600.f416 = D_001CFEC0[168] * e->f18 + 2048.0f;
    D_001E7600.f532 = b;
    D_001E7600.f420 = D_001CFEC0[169] * e->f1C + 2048.0f;
    D_001E7600.f540 = b * 4.0f;
    func_003FFAC8();
    D_001D7B80 = D_001D7B88[D_001D52F0];
    func_004AD960(0);
}
/* localdecomp:end func_00400DF8 */
