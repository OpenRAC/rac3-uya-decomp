#include "common.h"

/* localdecomp:start func_003CF0C0 */
typedef int s128 __attribute__((mode(TI)));

typedef struct S_3CF0C0o {
    u8 pad0[0x10];
    s128 x10;
    u8 x20;
    u8 pad21[0xAA - 0x21];
    s16 xAA;
    u8 padac[0xF8 - 0xAC];
    f32 xF8;
    u8 padfc[4];
} S_3CF0C0o;
typedef struct S_3CF0C0f {
    u8 pad0[8];
    s32 (*x8)(S_3CF0C0o *);
    u8 padc[8];
    void (*x14)(S_3CF0C0o *, s32, s128 *, f32 *);
} S_3CF0C0f;
typedef struct S_3CF0C0p {
    u8 pad0[0x28];
    s32 x28;
    s32 x2C;
    u8 pad30[0x10];
    s32 x40;
    u8 pad44[0xE8 - 0x44];
    s32 xE8;
    s32 xEC;
} S_3CF0C0p;

extern S_3CF0C0o *D_001E009C;
extern s32 D_001E00D8;
extern u16 *D_0021DEA0[];
extern S_3CF0C0f *func_00438488(s32, s32, s32);

void func_003CF0C0(s32 a0, S_3CF0C0p *p) {
    S_3CF0C0o *src;
    S_3CF0C0o *o;
    S_3CF0C0f *h;
    S_3CF0C0f *f;
    u16 *list;
    s32 n;
    s128 buf;
    f32 val;

    if (p->x2C == -1 || p->x28 == -1) {
        return;
    }
    src = &D_001E009C[p->x28];
    h = func_00438488(6877, 0, 104);
    n = 0;
    for (list = D_0021DEA0[p->x2C];
         (p->x2C & 0xFF) != 255 && p->x2C <= D_001E00D8 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_0021DEA0[p->x2C]);
         list++) {
        o = &D_001E009C[*list & 0x7FFF];
        if (o == 0) {
            break;
        }
        if (o->x20 == 254) {
            continue;
        }
        if (o->x20 == 253) {
            continue;
        }
        if (p->x40 != -1) {
            f = func_00438488(o->xAA, 1, 28);
            if (f == 0) {
                continue;
            }
            if (f->x8(o) != 0) {
                continue;
            }
        }
        h->x14(src, n, &buf, &val);
        n++;
        o->x10 = buf;
        o->xF8 = val;
    }
    p->xEC = 0;
    p->xE8 = 5;
}
/* localdecomp:end func_003CF0C0 */
