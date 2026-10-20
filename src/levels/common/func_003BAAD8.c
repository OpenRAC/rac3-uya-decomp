#include "common.h"

typedef struct {
    u8 pad[0x1C];
    f32 f1C;
    u8 pad2[0x88 - 0x20];
    f32 f88;
    u8 pad3[0xA8 - 0x8C];
    int xA8;
    u8 pad4[0xB0 - 0xAC];
    u8 xB0[4];
} S_3BAAD8v;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x31 - 0x22];
    u8 b31;
    u8 pad3[0x34 - 0x32];
    u16 h34;
    u8 pad4[0x68 - 0x36];
    S_3BAAD8v *v;
    u8 pad5[0xAA - 0x6C];
    s16 hAA;
} S_3BAAD8m;

extern int func_00408B50(void);
extern void func_0040BEC0(f32 *, S_3BAAD8m *, f32);
extern int func_0040D0C0(f32 *, f32);
extern void func_00408090(S_3BAAD8m *, void *, int, int, int, int, f32, f32, f32);
extern u16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern int D_001E00D8;

void func_003BAAD8(S_3BAAD8m *o) {
    u16 *p;
    int k;
    S_3BAAD8m *m;
    S_3BAAD8v *v;
    f32 buf[4];

    if (o->b21 == 255) {
        return;
    }
    k = func_00408B50();
    p = D_0021DEA0[o->b21];
    while (o->b21 != 255 && o->b21 <= D_001E00D8 && p != 0
           && (((s16 *)p)[-1] >= 0 || p == D_0021DEA0[o->b21])) {
        m = (S_3BAAD8m *)(D_001E009C + (*p & 0x7FFF) * 256);
        if (m == 0) {
            return;
        }
        v = m->v;
        if (m->b31 != 0) {
            func_0040BEC0(buf, m, 0.0009765625f);
            buf[3] *= 1.1f;
            if (func_0040D0C0(buf, v->xA8) != -1 && !(m->h34 & 1) && m->hAA == 4928 && m->b20 == 1) {
                if (k != 0) {
                    v->f1C -= 0.1f;
                    if (v->f1C <= -8.0f) {
                        v->f1C += 8.0f;
                    }
                }
                func_00408090(m, v->xB0, 2, 0x605696FF, 192, 23, v->f88, v->f88 * 7.0f, v->f1C);
            }
        }
        p++;
    }
}
