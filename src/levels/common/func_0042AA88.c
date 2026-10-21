#include "common.h"

/* localdecomp:start func_0042AA88 */
typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001DF9FC;
extern E_395EB8 D_001E7900[];
long func_0042AA88(u8 *p) {
    T_395EB8 t;
    s32 w, h, s, a, cbp, tbp;
    long r;
    E_395EB8 *e;
    w = *(s32 *)(p + 8);
    __asm__("plzcw %0, %1" : "=r"(w) : "r"(w));
    h = *(s32 *)(p + 0xC);
    __asm__("plzcw %0, %1" : "=r"(h) : "r"(h));
    t.tw = 0x1E - w;
    t.th = 0x1E - h;
    s = t.tw - 6;
    if (s < 0) s = 0;
    a = D_001D4BB0;
    cbp = a >> 8;
    a += 0x400;
    tbp = a >> 8;
    t.data = p + 0x20;
    t.clut = p + 0x420;
    t.f14 = 0x400;
    D_001D4BB0 = a + (1 << (t.tw + t.th));
    r = (long)tbp | ((long)(1 << s) << 14) | (0x13UL << 20) | ((long)t.tw << 26) | ((long)t.th << 30) | (1UL << 34) | ((long)cbp << 37) | (4UL << 61);
    if (D_001DF9FC < 0x40) {
        e = &D_001E7900[D_001DF9FC];
        e->data = t.data;
        e->f6 = cbp;
        e->f4 = 0;
        D_001E7900[D_001DF9FC].clut = t.clut;
        e->tw = t.tw;
        e->th = t.th;
        e->fE = tbp;
        D_001DF9FC++;
    }
    return r;
}
/* localdecomp:end func_0042AA88 */
