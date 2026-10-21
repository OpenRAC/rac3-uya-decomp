#include "common.h"

/* localdecomp:start func_004686D8 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[16];
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 pad1;
    s32 w24;
    f32 f28;
} S_004686D8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    u16 h10;
    f32 f12;
    s128 q16;
    S_004686D8 sub;
} P_004686D8;

extern u8 *D_00221200[];
extern P_004686D8 *func_0045E438(s32);
extern s32 func_0013D3E0(void);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern void func_00440CF8(S_004686D8 *, f32, f32, f32);

P_004686D8 *func_004686D8(s128 *pos, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, s32 a6, f32 f0, f32 f1) {
    P_004686D8 *p;
    S_004686D8 *s;
    f32 x;
    f32 y;
    s32 k;

    p = func_0045E438(58);
    if (p != 0) {
        p->q16 = *pos;
        p->b9 = 112;
        p->b3 = 68;
        p->b1 = 0;
        s = &p->sub;
        p->b2 = D_00221200[0][func_0013D3E0() & 7];
        p->f12 = 21000.0f;
        p->b8 = func_0013D3E0();
        s->b16 = a1;
        s->b18 = a3;
        s->b19 = a4;
        s->w24 = a6;
        s->f28 = f0;
        s->b17 = a2;
        s->b21 = a5;
        k = s->b16;
        switch (k) {
        case 0:
        case 1:
            p->h10 = a2;
            p->w4 = 0xFF808080;
            s->b20 = 0;
            break;
        case 2:
            x = func_004408C0(3.0f, 9.0f) * f1 * 0.016666668f;
            y = func_00440978();
            func_00440CF8(s, x, y, func_004408C0(1.3439035f, 1.7976891f));
            p->f12 = 42000.0f;
            s->b22 = (func_0013D3E0() & 0x1F) + 16;
            p->w4 = (s->b22 << 24) | 0x808080;
            p->h10 = a5;
            s->b20 = k;
            break;
        }
    }
    return p;
}
/* localdecomp:end func_004686D8 */
