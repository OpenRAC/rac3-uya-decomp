#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_001E2AC0_003804A0[];
extern s32 D_001D6694;
extern u128_t D_001EAAA0[];
extern s32 func_003F8448();
extern s32 func_003FC730(void);
extern f32 func_00443C08_003804A0(void *, s32);
void func_003F2FA8(s32 idx) {
    E_3804A0 *e = &D_001E2AC0_003804A0[idx];
    Q_3804A0 a, b;
    s32 i;
    if (*(s16 *)(e->f50 + 0x86) == 6 || D_001D6694 != 0) {
        e->f450 = 0;
        return;
    }
    a.q = e->q0.q;
    b.q = e->q0.q;
    b.v.z -= 0.75f;
    a.v.z += 0.75f;
    i = 0;
    while (i < 6 && func_003F8448(&a, &b, 0x12, 0, 0)) {
        if (func_003FC730() == 0) {
            f32 r = func_00443C08_003804A0(D_001EAAA0, 0);
            if (D_001E2AC0_003804A0[idx].q0.v.z < r + 0.04f) {
                D_001E2AC0_003804A0[idx].f450 = 1;
            } else {
                D_001E2AC0_003804A0[idx].f450 = 0;
            }
            return;
        }
        i++;
        a.q = D_001EAAA0[0];
        a.v.z -= 0.01f;
    }
}
