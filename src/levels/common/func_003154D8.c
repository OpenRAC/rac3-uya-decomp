#include "common.h"

typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31[0x34 - 0x31]; u16 h34;
    u8 p36[0x44 - 0x36]; s32 w44; s32 w48; u8 p4C[0x98 - 0x4C]; s32 w98;
    u8 p9C[0xAA - 0x9C]; s16 hAA;
} M_003154D8;
typedef struct { M_003154D8 *obj; s32 color; s32 arg; f32 scale; void (*fn)(M_003154D8 *); s32 pad[3]; } E_003154D8;

extern M_003154D8 *D_001E17BC;
extern s32 D_001E17C0;
extern E_003154D8 D_00271BC0[];
extern M_003154D8 *func_00435E70(s32, s32);
extern void func_00436220(M_003154D8 *);
extern void func_00438938(M_003154D8 *, s32 *, s32 *, s32 *);

void func_003154D8(M_003154D8 *a0, s32 a1, void (*a2)(M_003154D8 *)) {
    M_003154D8 *m = D_001E17BC;
    s32 rgb[3];

    if (m == 0 || m->hAA != 3137 || m->b20 == 254 || m->b20 == 253) {
        M_003154D8 *n = func_00435E70(3137, 128);
        D_001E17BC = n;
        if (n != 0) {
            n->b30 = 255;
        } else {
            func_00436220(a0);
        }
    }
    a0->h34 |= 2;
    a0->w98 = 0;
    a0->w48 = 0;
    a0->w44 = 0;
    if (D_001E17C0 < 64) {
        s32 n;
        func_00438938(a0, &rgb[0], &rgb[1], &rgb[2]);
        n = D_001E17C0;
        D_00271BC0[n].obj = a0;
        D_00271BC0[n].color = (rgb[2] << 16) | (rgb[1] << 8) | rgb[0];
        D_00271BC0[n].arg = a1;
        D_00271BC0[n].scale = 1.0f;
        D_00271BC0[n].fn = a2;
        D_001E17C0 = n + 1;
    } else if (a2 != 0) {
        a2(a0);
    } else {
        func_00436220(a0);
    }
}
