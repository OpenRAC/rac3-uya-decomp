#include "common.h"

/* localdecomp:start func_003F09E0 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    u8 v20[16];
    s16 h30;
    u16 h32;
    s32 w34;
    s32 w38;
    s32 w3C;
} E_003F09E0;

extern E_003F09E0 D_001E5D10[][32];
extern s32 D_001DF980[2];
extern u8 *D_001D52FC;

extern void func_003F0980(s32, E_003F09E0 *);
extern void func_003F0FA0(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E6D50(s32, s32, f32, f32);
extern void func_003E6FF0(s32);
extern void func_003E6DA8(s32, f32, f32);
extern void func_003E6EC8(s32, f32);
extern void func_003E6DF0(s32, s32, f32, f32);
extern void func_003F1200(s32, f32);
extern void func_003E7110(s32, s32);
extern void func_003E9410(s32);
extern void func_003E6F00(s32, s32);
extern void func_003E7028(s32);
extern void func_003E6F90(s32, f32, f32);
extern void func_003E6F38(s32, f32, f32);
extern void func_003E73D0(s32, void *, f32, f32);
extern s32 func_0040BAC0(void *);

s32 func_003F09E0(s32 idx) {
    E_003F09E0 *e;
    s32 i;
    s32 best = -1;
    s32 besti = -1;
    s32 cur;
    u8 *p;

    for (i = 0; i < 32; i++) {
        if (D_001E5D10[idx][i].b1D != 0) {
            e = &D_001E5D10[idx][i];
            if (e->w38 != 0 && --e->w38 == 0) {
                func_003F0980(idx, e);
            } else if (best < e->b1C) {
                best = e->b1C;
                besti = i;
            }
        }
    }

    if (besti >= 0) {
        cur = D_001DF980[idx];
        if (cur >= 0 && besti != cur) {
            if (((E_003F09E0 *)((u8 *)D_001E5D10 + (idx << 11)))[cur].f10 >= 0.0f &&
                ((E_003F09E0 *)((u8 *)D_001E5D10 + (idx << 11)))[besti].f10 < 0.0f) {
                func_003F0FA0(idx, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            }
        }
    }
    D_001DF980[idx] = besti;
    if (besti >= 0) {
        e = &D_001E5D10[idx][besti];
        if (e->f0 >= 0.0f) {
            func_003E6D50(idx, 0, e->f0, 0.001f);
            if (e->f0 < 4.64f || 6.0f < e->f0) {
                func_003E6FF0(idx);
            }
        }
        if (e->f4 >= 0.0f) {
            func_003E6DA8(idx, e->f4, 0.001f);
        }
        if (__builtin_fabsf(e->fC + 1.0f) > 0.001f) {
            func_003E6EC8(idx, e->fC);
        }
        if (e->f8 >= 0.0f) {
            func_003E6DF0(idx, 0, e->f8, 0.005f);
        }
        if (e->f14 >= 0.0f) {
            func_003F1200(idx, e->f14);
        }
        if (e->h1A != 0) {
            if (e->h1A == 1) {
                func_003E7110(idx, -1);
            } else if (e->h1A == 2) {
                func_003E7110(idx, 1);
            } else if (e->h1A == 3) {
                func_003E7110(idx, 2);
            }
        }
        if (e->w3C != 0) {
            func_003E9410(idx);
        }
        if (e->b18 != 0) {
            func_003E6FF0(idx);
            func_003E6F00(idx, 0);
            func_003E7028(idx);
            func_003E6F90(idx, 0.01f, 0.2f);
            func_003E6F38(idx, 0.03f, 0.2f);
        }
        if (e->b19 != 0) {
            func_003E7028(idx);
            func_003E6F38(idx, 0.03f, 0.2f);
            func_003E6F90(idx, 0.0075f, 0.2f);
        }
        if (e->f10 >= 0.0f) {
            func_003F0FA0(idx, 0, 3, e->f10, 0.005f, 0.2f, 0.0f);
        }
        if ((f32)e->b1E > 0.0f) {
            func_003E73D0(idx, e->v20, (f32)e->w34 * 0.017453292f, 0.0f);
        }
        if ((f32)e->b1F > 0.0f) {
            if (func_0040BAC0(&e->h30)) {
                func_003E73D0(idx, e->v20, (f32)e->w34 * 0.017453292f, 0.0f);
            }
            p = D_001D52FC;
            if (__builtin_fabsf(*(f32 *)(p + 0x100)) > 0.01f ||
                __builtin_fabsf(*(f32 *)(p + 0x104)) > 0.01f) {
                e->h30 = e->h32;
            }
        }
        return besti;
    }
    return -1;
}
/* localdecomp:end func_003F09E0 */
