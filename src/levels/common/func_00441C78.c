#include "common.h"

/* localdecomp:start func_00441C78 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
extern void func_00436350();

typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_001FCBC0[];
extern void func_00456320_003BE4F0();
extern s32 func_00437470();
extern void func_0043AAF8();
void func_00441C78(S_3BE4F0 *p, s32 idx, s32 lim, s32 dur) {
    s32 v;
    s32 r;
    s32 n;
    n = p->f24->e[idx]->n;
    if (lim >= n) lim = n - 1;
    if (dur <= 0) {
        func_00441BA0(p, idx, lim);
        return;
    }
    if ((u32)(lim - 1) < 0xB) func_00456320_003BE4F0(p, idx, (u16)lim);
    if (0.025f < p->f44 || p->f50 != 0 || p->f54 != 0) {
        r = func_00437470(p);
        if (r >= 0) {
            func_0043AAF8(p, r | 0x300);
            D_001FCBC0[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_00436350(p);
    p->f60 &= 0xFD;
    p->f48 = 1.0f;
    p->f44 = 0;
    p->f4C = 1.0f / (f32)dur;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_00441C78 */
