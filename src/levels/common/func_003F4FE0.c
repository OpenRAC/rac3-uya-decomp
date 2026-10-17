#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; } H_3F4FE0;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_3F4FE0 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_3F4FE0;
typedef struct { E_3F4FE0 e[14]; s32 n; } T_3F4FE0;
extern T_3F4FE0 D_001E5200;
extern s32 D_001E5580[];
extern s32 D_001A71A4[];
extern s32 D_001D6698;
extern s32 D_001D4BC0, D_001D4BC4, D_001D4BD0, D_001D4BD4;
extern void func_003F4700(void);
extern void func_003FE7B0(f32 *, void *);
extern void func_003F43E0(void *, f32, f32);
void func_003F4FE0(s32 a) {
    f32 v[2];
    s32 i;
    E_3F4FE0 *p;
    if (D_001A71A4[0] == 0x74) {
        D_001E5580[0] = 0;
        return;
    }
    func_003F4700();
    if (D_001E5200.n == 0) return;
    for (i = 0; i < D_001E5200.n; i++) {
        p = &D_001E5200.e[i];
        if (p->b25 != a || p->f20 == 0 || p->f20->b20 == 0xFE || p->f20->b20 == 0xFD) continue;
        if (p->b24 != 0) {
            func_003FE7B0(v, p);
            v[0] = (v[0] - (f32)D_001D4BD0) * 0.0625f;
            v[1] = (v[1] - (f32)D_001D4BD4) * 0.0625f;
        } else {
            v[0] = (f32)D_001D4BC0 * p->f30;
            v[1] = (f32)D_001D4BC4 * p->f34;
        }
        if (D_001D6698 != 0) p->f10 *= 0.75f;
        func_003F43E0(p, v[0], v[1]);
    }
    if (D_001D6698 == 0) D_001E5200.n = 0;
}
