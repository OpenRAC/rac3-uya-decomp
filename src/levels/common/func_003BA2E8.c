#include "common.h"

/* localdecomp:start func_003BA2E8 */
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA2E8;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA2E8 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA2E8;

typedef struct { u8 b[256]; } C_3BA2E8;

extern s16 *D_0021DEA0[];
extern int D_001E00D8;
extern int D_001E009C;
extern void func_0040BEC0(f32 *, M_3BA2E8 *, f32);
extern int func_00408B50(void);
extern int func_0040D0C0(f32 *, f32);
extern void func_00408090(M_3BA2E8 *, void *, int, int, int, int, f32, f32, f32);

void func_003BA2E8(M_3BA2E8 *a0) {
    s16 *p;
    M_3BA2E8 *m;
    V_3BA2E8 *v;
    f32 buf[4];
    int flag;

    if (a0->b21 == 255) {
        return;
    }
    flag = func_00408B50();
    for (p = D_0021DEA0[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_001E00D8 && p != 0 &&
         (p[-1] >= 0 || p == D_0021DEA0[a0->b21]); p++) {
        m = (M_3BA2E8 *)(D_001E009C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        func_0040BEC0(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0040D0C0(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 7238) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        if (flag) {
            v->f1C -= 0.1f;
            if (v->f1C <= -8.0f) {
                v->f1C += 8.0f;
            }
        }
        func_00408090(m, v->bB0, 2, 0x60804040, 0x204090, 23, v->f88 * 0.3f, v->f88 * 7.0f * 0.3f, v->f1C);
    }
}
/* localdecomp:end func_003BA2E8 */
