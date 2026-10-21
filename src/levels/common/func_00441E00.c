#include "common.h"

/* localdecomp:start func_00441E00 */
typedef struct { s32 a, b, c, d; } __attribute__((aligned(16))) Q_441E00;
extern Q_441E00 D_001FCBC0[];
extern void func_00441BA0(void *);
extern void func_00456320(void *, s32, u16);
extern s32 func_00437470(void *);
extern void func_0043AAF8(void *, s32);
extern void func_00436350(void *);

void func_00441E00(u8 *o, s32 a1, s32 a2, s32 a3, s32 flags) {
    f32 f;
    s32 i, m, v;
    u32 t;
    if (a3 <= 0) {
        func_00441BA0(o);
        return;
    }
    t = a2 - 1;
    if (t < 10 && !(flags & 8)) {
        func_00456320(o, a1, t);
    }
    f = *(f32 *)(o + 0x44);
    if (0.025f < f || *(s32 *)(o + 0x50) || *(s32 *)(o + 0x54) || (flags & 4)) {
        i = func_00437470(o);
        if (i >= 0) {
            m = i;
            if (flags & 1) m |= 0x100;
            if (flags & 2) m |= 0x200;
            func_0043AAF8(o, m);
            D_001FCBC0[i] = *(Q_441E00 *)(o + 0x80);
            v = o[0x42];
            if (v != 0xFF) o[0xA9] = v;
            o[0x42] = 0xFF;
            o[0x40] = i;
        }
    }
    o[0x41] = a2;
    o[0x43] = a1;
    func_00436350(o);
    {
        f32 one = 1.0f;
        f32 r = one / (f32)a3;
        o[0x60] &= 0xFD;
        *(f32 *)(o + 0x48) = one;
        *(s32 *)(o + 0x44) = 0;
        *(f32 *)(o + 0x4C) = r;
        { s32 off = a1 << 2; u8 *tb = *(u8 **)(o + 0x24); o[0x6C] = *(u8 *)(*(s32 *)(tb + off + 0x48) + 0x11); }
    }
    if (flags & 0x10) o[0x7E] |= 4; else o[0x7E] &= 0xFB;
}
/* localdecomp:end func_00441E00 */
