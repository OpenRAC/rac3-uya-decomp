#include "common.h"

/* localdecomp:start func_003265F0 */
typedef struct {
    u8 pad0[0x110];
    f32 f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    u8 pad120[0x2E0 - 0x120];
    s16 h2E0[16];
    u8 c300[16][3];
} T_3265F0;

typedef struct {
    u8 pad0[0x68];
    T_3265F0 *p68;
    u8 pad6C[0xB0 - 0x6C];
    u8 bB0;
} O_3265F0;

typedef struct {
    u8 pad0[0x46];
    u8 b46;
} Q_3265F0;

typedef struct {
    u8 pad0[0x24];
    Q_3265F0 *p24;
    u8 pad28[0xAA - 0x28];
    s16 hAA;
} A_3265F0;

typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x14 - 6];
    u8 c[3];
} B_3265F0;

extern O_3265F0 *func_003252E8();
extern s32 func_003255A0(T_3265F0 *a0, s32 a1);
extern s32 func_003FE4C0(s32 a0);

void func_003265F0(A_3265F0 *a0, B_3265F0 *a1) {
    O_3265F0 *o;
    T_3265F0 *t;
    s32 k;
    Q_3265F0 *q;
    s16 h;
    u8 c[3];
    s32 r;

    o = func_003252E8();
    t = o->p68;
    k = func_003255A0(t, a0->hAA);
    q = a0->p24;
    h = t->h2E0[k];
    c[0] = t->c300[k][0];
    c[1] = t->c300[k][1];
    c[2] = t->c300[k][2];
    if (q != 0 && q->b46 == 5) {
        r = func_003FE4C0(o->bB0);
        switch (r) {
        case 2:
            h = (f32)h * t->f110;
            c[0] = (f32)c[0] * t->f118;
            c[1] = (f32)c[1] * t->f118;
            c[2] = (f32)c[2] * t->f118;
            break;
        case 1:
            h = (f32)h * t->f114;
            c[0] = (f32)c[0] * t->f11C;
            c[1] = (f32)c[1] * t->f11C;
            c[2] = (f32)c[2] * t->f11C;
            break;
        }
    }
    if (t->h2E0[k] != 0 && h <= 0) {
        h = 1;
    }
    if (t->c300[k][0] != 0 && c[0] == 0) {
        c[0] = 1;
    }
    if (t->c300[k][1] != 0 && c[1] == 0) {
        c[1] = 1;
    }
    if (t->c300[k][2] != 0 && c[2] == 0) {
        c[2] = 1;
    }
    a1->h4 = h;
    a1->c[0] = c[0];
    a1->c[1] = c[1];
    a1->c[2] = c[2];
}
/* localdecomp:end func_003265F0 */
