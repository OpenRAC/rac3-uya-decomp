#include "common.h"

typedef struct {
    u8 p0[0x24];
    s32 id;
    u8 p28[0x698];
    s32 a1728[36];
    s32 a1872[4];
} O_3C41F8;

extern u16 *D_0021DEA0[];
extern s32 D_001E00D8;
typedef struct { u8 p0[0x34]; u16 h52; u8 p36[0xCA]; } M_3C41F8;
extern struct U_3C41F8 D_001E009C __attribute__((section(".sdata")));
extern s32 D_001F3FC0[];
extern void func_004282C0(s32 a, s32 b);
extern void func_003C3A10(void *a, O_3C41F8 *o);

void func_003C41F8(void *a, O_3C41F8 *o, s32 i) {
    u16 *p;
    M_3C41F8 *e;
    s32 s = o->a1872[i];

    if (s == -1) {
        s32 t = o->a1728[i];
        if (t != s && t != D_001F3FC0[0]) {
            func_004282C0(t, 0);
        }
    } else if (s != D_001F3FC0[0]) {
        func_004282C0(s, 0);
    }
    func_003C3A10(a, o);
    for (p = D_0021DEA0[o->id];
         (o->id & 0xFF) != 0xFF && o->id <= D_001E00D8 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_0021DEA0[o->id]);
         p++) {
        e = *(M_3C41F8 **)&D_001E009C + (p[0] & 0x7FFF);
        if (e == 0) {
            break;
        }
        e->h52 &= 0xFF7F;
    }
}
