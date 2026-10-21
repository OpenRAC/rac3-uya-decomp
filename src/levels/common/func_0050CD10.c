#include "common.h"

/* localdecomp:start func_0050CD10 */
typedef int Q_50CD10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_50CD10;
typedef struct { u8 pad[0x40]; } __attribute__((aligned(16))) M_50CD10;
typedef struct {
    u8 pad0[0x2C0];
    V4_50CD10 v2C0;
} G_50CD10;

extern u8 D_001A4C70[];
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C658(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern f32 func_0040C490(f32, f32);

f32 func_0050CD10(void)
{
    M_50CD10 m;
    V4_50CD10 u, a, b, c;
    f32 z;
    f32 t;
    f32 fy;
    u8 *p;
    G_50CD10 *g;

    z = 0.0f;
    u.x = func_0040C3C8(z);
    u.y = func_0040C3E0(z);
    u.z = z;
    p = D_001A4C70;
    func_0040C658(&m, p);
    func_0040C2F8(&u, &u, &m);
    g = (G_50CD10 *)(p - 0x90);
    if (g->v2C0.x != z || g->v2C0.y != z) {
        fy = g->v2C0.y;
        __asm__("sq $0,%0" : "=m"(a) : "f"(fy));
        c = g->v2C0;
        __asm__("sq $0,%0" : "=m"(b));
        t = func_0040C490(g->v2C0.x, fy);
        a.z = -t;
        func_0040C658(&m, &a);
        func_0040C2F8(&u, &u, &m);
        func_0040C2F8(&c, &c, &m);
        t = func_0040C490(c.z, c.x);
        b.y = -t;
        func_0040C658(&m, &b);
        func_0040C2F8(&u, &u, &m);
        a.z = -a.z;
        func_0040C658(&m, &a);
        func_0040C2F8(&u, &u, &m);
    }
    return func_0040C490(u.x, u.y);
}
/* localdecomp:end func_0050CD10 */
