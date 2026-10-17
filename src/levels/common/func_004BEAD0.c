#include "common.h"

typedef int u128_4BEAD0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x10];
    u128_4BEAD0 v10;
    u8 p20[0x14];
    u16 h34;
    u8 p36[0xA];
    u8 b40, b41, b42, b43;
    u8 p44[0x14];
    s32 w58;
    s32 w5C;
    u8 p60[0x3C];
    s32 w9C;
} M_4BEAD0;
typedef struct {
    u8 p0[0x80];
    u128_4BEAD0 q80;
    u8 p90[0xB64];
    M_4BEAD0 *wBF4;
    M_4BEAD0 *wBF8;
    s32 wBFC;
    u8 pC00[4];
    f32 fC04;
    u8 pC08[0x19B8];
    M_4BEAD0 *w25C0;
    s32 w25C4;
    u8 p25C8[0x1C];
    u8 b25E4;
} G_4BEAD0;
extern G_4BEAD0 D_001A4BE0;
extern s32 D_001D6694;
extern u8 D_0024F940[];
extern u8 D_0024FF40[];
extern void func_003F3360();
extern void func_003F33B8();
extern void func_003F3D80();
extern void func_004B2890(void);
extern void func_003F2A08(s32, s32, void *, void *, void *, s32, s32);
extern void func_003F29B8(s32);
extern void func_0040E0A0(s32);
extern void func_004B32E8(void);
extern void func_004DC198(void);
extern s32 func_004B20C0(M_4BEAD0 *, s32, s32, void *);
extern void func_004CF3B8(s32, s32);
void func_004BEAD0(void) {
    G_4BEAD0 *g;
    M_4BEAD0 *m;
    func_004B2890();
    g = &D_001A4BE0;
    g->b25E4 = 0;
    func_003F2A08(35, 0, func_003F3360, func_003F33B8, func_003F3D80, 0, 0);
    func_003F29B8(3);
    if (g->wBF4 != 0) {
        g->wBF4->h34 &= ~6;
    }
    g->wBF4 = 0;
    if (g->wBFC != 0) {
        func_0040E0A0(g->wBFC);
        g->wBFC = 0;
    }
    func_004B32E8();
    g->w25C0 = g->wBF8;
    g->w25C0->v10 = g->q80;
    g->w25C0->w9C = 0;
    g->fC04 = 1.0f;
    func_004DC198();
    m = g->w25C0;
    if (m->b42 != 0xFF) {
        g->w25C0->w58 = func_004B20C0(m, m->b42, m->b40, D_0024F940);
    }
    m = g->w25C0;
    g->w25C0->w5C = func_004B20C0(m, m->b43, m->b41, D_0024FF40);
    if (g->w25C4 != 101 || (D_001D6694 != 2 && D_001D6694 != 6)) {
        func_004CF3B8(0, 1);
    }
}
