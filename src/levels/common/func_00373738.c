#include "common.h"

/* localdecomp:start func_00373738 */
typedef int s128 __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern void func_004C41E8(u8 *, u8 *);
extern void func_0040C0F0(u8 *, u8 *, f32);
extern s32 func_004C4A18(u8 *, f32, f32, f32, s32);
extern void func_004A6DF8(u8 *, s32);
extern struct { u8 *p; s32 pad[8]; } D_001A71A0;

u8 *func_00373738(s32 a, s128 *pos, s128 *b, f32 c)
{
    u8 *m;
    u8 *q;
    s32 *v;
    u8 *w;
    u8 *g;
    s128 t;

    m = func_00435E70(6251, 1792);
    if (m != 0) {
        m[32] = 0;
        *(s16 *)(m + 50) = 255;
        m[48] = 255;
        v = *(s32 **)(m + 104);
        q = m + 16;
        *(s128 *)q = *pos;
        *(s128 *)v = *b;
        v[14] = a;
        *(f32 *)(v + 12) = func_00440978();
        v[13] = 0;
        w = (u8 *)(v + 4);
        func_004C41E8(q, w);
        func_0040C0F0(w, w, 0.1f);
        g = D_001A71A0.p;
        t = *(s128 *)(g + 208);
        *(f32 *)(v + 26) = c;
        v[19] = 0;
        v[21] = 0;
        v[23] = 0;
        v[30] = 0;
        v[31] = 0;
        v[32] = 0;
        v[25] = -1;
        *(f32 *)(v + 28) = 2.25f;
        *(f32 *)(v + 29) = 2.25f;
        v[27] = -1;
        *(s128 *)(v + 8) = t;
        v[35] = func_004C4A18(m, 1.0f, 1.0f, 1.0f, 0);
        *(f32 *)(v + 36) = func_004408C0(7.0f, 23.0f);
        v[37] = 0;
        *(s32 *)(m + 152) = 0;
        *(u16 *)(m + 52) = (*(u16 *)(m + 52) | 0x41) & 0xefff;
        func_004A6DF8(m, 1);
    }
    return m;
}
/* localdecomp:end func_00373738 */
