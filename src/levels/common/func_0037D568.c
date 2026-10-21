#include "common.h"

/* localdecomp:start func_0037D568 */
typedef struct {
    u8 pad0[111];
    u8 unk6F;
} S_001425C0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[238];
} S_002C5640;

typedef struct {
    u8 pad0[352];
    u8 *unk160;
    u8 pad164[8];
    u8 *unk16C;
} S_00221118;

extern S_001425C0 D_001425C0;
extern S_002C5640 D_002C5640[];
extern S_00221118 D_00221118;
extern f32 D_001E1DF0[2];
extern f32 D_001E1E00[2];
extern u8 D_001D66B0[8];
extern f32 func_004408C0(f32, f32);
extern void func_0040BE68(f32 *, f32 *, f32 *, f32);
extern s32 func_00440878(s32, s32);
extern u8 *func_0046DCB8(f32 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_0037D568(void) {
    f32 pos[4];
    s32 i;
    s32 col;
    s32 t;
    s32 a;
    s32 b;
    f32 s;
    u8 *e;

    t = (D_001425C0.unk6F)[D_002C5640].unk1;
    col = 0x40FF20;
    if (t == 1) {
        col = 0x404040;
    }
    if (t == 2) {
        col = 0x4080FF;
    }
    if (t == 3) {
        col = 0x404040;
    }
    if (t > 3U) {
        col = 0x808080;
    }
    for (i = 39; i >= 0; i--) {
        func_0040BE68(pos, D_001E1DF0, D_001E1E00, func_004408C0(0.0f, 0.75f));
        a = func_00440878(10, 15);
        b = func_00440878(-5, 5);
        s = func_004408C0(0.125f, 0.5f) * 210000.0f;
        e = func_0046DCB8(pos, D_001D66B0, a, col, b, 47, 0, s,
                          func_004408C0(0.35f, 0.75f) * 210000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = D_00221118.unk160[0];
            if ((D_001425C0.unk6F)[D_002C5640].unk1 == 1) {
                e[2] = D_00221118.unk16C[1];
            }
            if ((D_001425C0.unk6F)[D_002C5640].unk1 == 2) {
                e[2] = D_00221118.unk160[0];
            }
            if ((D_001425C0.unk6F)[D_002C5640].unk1 == 3) {
                e[2] = D_00221118.unk16C[3];
            }
            if ((D_001425C0.unk6F)[D_002C5640].unk1 > 3U) {
                e[2] = D_00221118.unk16C[3];
            }
        }
    }
}
/* localdecomp:end func_0037D568 */
