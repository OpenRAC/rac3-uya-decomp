#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef union {
    s128 q;
    f32 f[4];
} Vec_004E5300;

typedef struct {
    u8 pad0[516];
    s16 f516;
    u8 pad518[616];
    u8 f1134;
    u8 pad1135[545];
    s32 f1680;
    s32 f1684;
    f32 f1688;
    s32 f1692;
    u8 pad1696[12];
    s32 f1708;
    u8 pad1712[7964];
    s32 f9676;
} Game_004E5300;

extern Game_004E5300 D_001A4BE0;
extern s128 D_001A5250;
extern u8 *D_001D52FC;
extern void func_004E52C8(Vec_004E5300 *);
extern s32 func_004E4E00(Vec_004E5300 *, s32 *, Vec_004E5300 *, s32 *, f32 *, s32 *, s32, s32, s32);

void func_004E5300(void) {
    Vec_004E5300 a;
    Vec_004E5300 b;
    s32 i48;
    s32 i52;
    f32 f56;
    s32 i60;
    f32 k;
    f32 d;
    s32 m;
    Game_004E5300 *g;
    s128 *pv;

    D_001A4BE0.f1692 = 0;
    if (D_001A4BE0.f516 != 0) {
        return;
    }
    func_004E52C8(&a);
    m = D_001A4BE0.f9676;
    if ((m == 4 && D_001A4BE0.f1134 == 0) || m == 2 || m == 15) {
        if (func_004E4E00(&a, &i48, &b, &i52, &f56, &i60, 0, 0, 1) == 0) {
            return;
        }
        d = a.f[2] - b.f[2];
        k = -0.7f;
        if (*(s32 *)(D_001D52FC + 420) & 0x80) {
            k = -1.2f;
        }
        if (k < d && d < 0.4f) {
            pv = &D_001A5250;
            *pv = b.q;
            g = (Game_004E5300 *)((u8 *)pv - 1648);
            g->f1680 = i48;
            g->f1684 = i52;
            g->f1688 = f56;
            g->f1708 = i60;
            g->f1692 = 1;
        }
    }
}
