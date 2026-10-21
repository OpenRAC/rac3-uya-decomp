#include "common.h"

/* localdecomp:start func_004E1A78 */
typedef struct {
    u8 pad0[0x80];
    f32 f80;
    f32 f84;
    u8 pad88[0x98 - 0x88];
    f32 f98;
    u8 pad9C[0x350 - 0x9C];
    f32 f350[4];
    u8 pad360[0x9C8 - 0x360];
    s16 h9C8;
} G_4E1A78;

extern G_4E1A78 D_001A4BE0;
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040CF10(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_004408C0(f32, f32);
extern s16 func_00440848(int);
extern void func_00467510(f32 *, f32 *, f32 *, f32, f32);

void func_004E1A78(int a0, int a1) {
    f32 v[4];
    f32 w[4];
    f32 ang;
    f32 r;
    f32 d;
    int i;

    D_001A4BE0.h9C8++;
    if (a1 < D_001A4BE0.h9C8) {
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                ang = func_0040CEC8(D_001A4BE0.f98, 0.785398006439209f);
            } else {
                ang = func_0040CF10(D_001A4BE0.f98, 0.785398006439209f);
            }
            v[0] = func_0040C3C8(ang) * 0.010000000707805157f;
            v[1] = func_0040C3E0(ang) * 0.010000000707805157f;
            v[2] = 0.0f;
            w[0] = D_001A4BE0.f80 + v[0] * 18.0f;
            w[1] = D_001A4BE0.f84 + v[1] * 18.0f;
            w[2] = D_001A4BE0.f350[0];
            v[0] -= func_0040C3C8(D_001A4BE0.f98) * 0.02500000223517418f;
            v[1] -= func_0040C3E0(D_001A4BE0.f98) * 0.02500000223517418f;
            r = func_004408C0(0.4f, 0.5f);
            d = -2.0f;
            if (i == 0) {
                d = 2.0f;
            }
            func_00467510(w, v, D_001A4BE0.f350, r, d);
            if (a0 != 0) {
                D_001A4BE0.h9C8 = func_00440848(a0);
            } else {
                D_001A4BE0.h9C8 = 0;
            }
        }
    }
}
/* localdecomp:end func_004E1A78 */
