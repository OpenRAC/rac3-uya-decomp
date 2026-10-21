#include "common.h"

/* localdecomp:start func_004CE230 */
extern s32 *func_004C8AE0();

extern u8 *D_001D67C8_003A9890;
extern s32 D_001D545C;
extern u8 D_001DB790[];
extern u8 D_001DB7A0[];
extern s32 func_004C9A70();
extern void func_004C90C8();
extern void func_004C99B0();
extern void func_004C9878();
extern void func_004C9880();
extern void func_004C9158();
extern void func_004C9170();
extern void func_004C99C8();
extern void func_004C99A8();
extern void func_004CBC80();
extern void func_004C9CE8();
extern void func_004C9410();
extern f32 *func_004C94B8();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
void func_004CE230(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_004C9A70(D_001D67C8_003A9890 + 0x7090, 0xC);
        sx->b[k] = func_004C9A70(D_001D67C8_003A9890 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_004C90C8(b, 0x16, 1, D_001DB790, a2);
                func_004C99B0(b, 5);
                func_004C9878(b, 0x64);
                func_004C9880(b, 0);
                func_004C9158(b, 0x706EC8FF, 0x706EC8FF);
                func_004C9170(b, 0x80808080, 0x80808080);
                func_004C99C8(b, 0x80000000);
                func_004C99A8(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_004CBC80(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_004C9CE8(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_004C9410(q, D_001DB7A0, a2);
    *(f32 *)func_004C8AE0(q) = 2155905024.0f;
    *func_004C94B8(q) = 60008.0f;
    ((s32 *)func_004C94B8(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_004C9CE8(s + 0x4ED0, a2);
}
/* localdecomp:end func_004CE230 */
