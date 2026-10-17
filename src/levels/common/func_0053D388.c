#include "common.h"

typedef struct {
    u8 p0[0x40];
    s32 w40;
    u8 p44[0xAC - 0x44];
    s32 wAC;
    s32 wB0;
    s32 wB4;
    s32 wB8;
    s32 wBC;
} S_0053D388;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x68 - 0x21];
    S_0053D388 *w68;
} O_0053D388;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0xAA - 0x21];
    s16 hAA;
    u8 pAC[0x100 - 0xAC];
} M_0053D388;

typedef struct {
    u8 p0[0x180];
    s32 w180;
} G_0053D388;

extern s32 func_005B39C8(s32, s32, s32);
extern s32 func_0053D148(O_0053D388 *);
extern s32 func_0053D170(O_0053D388 *);
extern s32 func_0053D198(O_0053D388 *);
extern s32 func_0053D1C0(O_0053D388 *);
extern s32 func_0053D248(O_0053D388 *);
extern s32 func_0053D270(O_0053D388 *);
extern G_0053D388 *D_001D5F30;
extern M_0053D388 *D_001E07CC;

s32 func_0053D388(O_0053D388 *o, s32 b) {
    S_0053D388 *s;
    M_0053D388 *m;
    if (b == 0 && o->b20 == 2) {
        s = o->w68;
        if (s->w40 == 0) {
            if (func_005B39C8(s->wB0, 5, 0) == 0 && func_0053D148(o) == 0) {
                func_0053D170(o);
            }
        } else {
            if (D_001D5F30->w180 == 0 && s->wB4 >= 0) {
                m = (M_0053D388 *)((s->wB4 << 8) + (s32)D_001E07CC);
                if (m->hAA == 7255 && m->b20 == 2 && func_0053D198(o) == 0) {
                    func_0053D1C0(o);
                }
            }
            if (func_005B39C8(s->wAC, 7, 0) == 0
                && s->wBC >= (s32)((f32)(s->wB8 * 10 + 30) * 60.0f)
                && func_0053D248(o) == 0) {
                func_0053D270(o);
            }
        }
    }
    return 0;
}
