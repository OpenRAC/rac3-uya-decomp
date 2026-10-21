#include "common.h"

/* localdecomp:start func_003CAD78 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CAD78;
typedef struct { u8 b0, b1, b2, b3; } P_3CAD78;
extern u8 *D_00221118[];
extern f32 func_00443140(void *, s32, s32, f32);
extern f32 func_00440978(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440848(s32);
extern P_3CAD78 *func_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_003CAD78(s32 a0, s32 a1, V4_3CAD78 *src, s32 count) {
    V4_3CAD78 q;
    V4_3CAD78 p;
    V4_3CAD78 c;
    f32 r, d, t;
    s32 n;
    P_3CAD78 *m;

    q = *src;
    p = *src;
    r = func_00443140(&q, 0, 0, 0.5f);
    p.z = r;
    d = q.z - r;
    if (d > 0.0f && d < 12.0f) {
        t = (d - 6.0f) / 6.0f;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        n = 127 - (s32)(t * 127.0f);
        if (n >= 15) {
            if (count > 0) do {
                c.x = func_0040C3C8(func_00440978()) * 0.033333335f;
                c.y = func_0040C3E0(func_00440978()) * 0.033333335f;
                c.z = 0.0050000004f;
                m = func_0046C468(&p, &c, 60, 0x303234, func_00440848(3), n, 7, 0, 63000.004f, 105000.0f, 0.0f);
                if (m != 0) {
                    m->b2 = D_00221118[23][0];
                    m->b3 = 72;
                }
            } while (--count != 0);
        }
    }
}
/* localdecomp:end func_003CAD78 */
