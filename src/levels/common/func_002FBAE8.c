#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 a10[4];
    u8 *a20[4];
} S_2FBAE8;

extern u8 *D_001E009C[];
extern s32 D_001DC398;
extern s32 D_001DC39C;

extern s32 func_00444358(u8 *, s32, s32);
extern s32 func_0040BA90(s32 *);
extern void func_00436220(u8 *);

void func_002FBAE8(u8 *o) {
    S_2FBAE8 *s;
    u8 *base;
    s32 r;
    s32 i;

    s = *(S_2FBAE8 **)(o + 104);
    switch (o[32]) {
    case 0:
        o[32] = 1;
        base = D_001E009C[0];
        s->f4 = D_001DC398;
        s->f8 = 3;
        s->a20[0] = base + (s->a10[0] << 8);
        s->a20[1] = base + (s->a10[1] << 8);
        s->a20[2] = base + (s->a10[2] << 8);
        s->a20[3] = base + (s->a10[3] << 8);
        break;
    case 1:
        r = func_00444358(o, 0x10000, 0);
        func_0040BA90(&s->fC);
        if (r != 0 && s->fC == 0) {
            o[168] = 255;
            s->fC = D_001DC39C;
            if (--s->f8 <= 0) {
                func_00436220(o);
                return;
            }
        }
        if (s->a20[0][32] == 80 || s->a20[1][32] == 80 || s->a20[2][32] == 80 || s->a20[3][32] == 80) {
            if (func_0040BA90(&s->f4) != 0) {
                s->f4 = D_001DC398;
                for (i = 0; i < 4; i++) {
                    if (s->a20[i][32] == 80) {
                        s->a20[i][32] = 81;
                        *(s128 *)(s->a20[i] + 16) = *(s128 *)(o + 16);
                        s->a20[i][168] = 255;
                        break;
                    }
                }
            }
        }
        break;
    }
}
