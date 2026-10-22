#include "common.h"

/* localdecomp:start func_003B2F10 */
typedef int Q_3B2F10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B2F10;
typedef struct {
    u8 pad0[0x30];
    V4_3B2F10 v30;
    u8 pad40[0x30];
    V4_3B2F10 v70;
} N_3B2F10;
typedef struct {
    u8 pad0[0x80];
    V4_3B2F10 v80;
    u8 pad90[8];
    f32 f98;
} G_3B2F10;
typedef struct {
    u8 pad0[0x14];
    s32 a;
    s32 b;
} S_3B2F10;
extern G_3B2F10 D_001A4BE0;
extern N_3B2F10 *D_001DEB00;
extern f32 func_0040E380(void);
extern f32 func_003E5630(f32, f32);
extern f32 func_003E5678(f32, f32);
extern f32 func_003E4B30(f32);
extern f32 func_003E4B48(f32);
extern void func_003E4590(V4_3B2F10 *, V4_3B2F10 *, V4_3B2F10 *, f32);
extern void func_003C1740(s32, V4_3B2F10 *);
extern void func_003C17B0(s32, V4_3B2F10 *);
void func_003B2F10(u8 *o) {
    V4_3B2F10 pos;
    V4_3B2F10 rot;
    V4_3B2F10 p;
    V4_3B2F10 q;
    S_3B2F10 *s = *(S_3B2F10 **)(o + 0x68);
    f32 v;
    f32 t;
    f32 a;
    f32 z;
    Q_3B2F10 x, y, r;
    if (o[0x42] == 1) {
        v = func_0040E380();
    } else {
        v = 170.0f;
    }
    t = v / 170.0f;
    if (s->a == -1 || s->b == -1) {
        G_3B2F10 *g = &D_001A4BE0;
        a = func_003E5630(t * 0.6981317f - 0.34906584f, g->f98);
        pos.x = func_003E4B30(a) * 5.0f;
        pos.y = func_003E4B48(a) * 5.0f;
        pos.z = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(g->v80));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(r));
        z = pos.z;
        __asm__("sq $0, %0" : "=m"(rot));
        pos.z = z + 1.0f;
        rot.z = func_003E5630(a, 3.14159f);
        rot.y = t * -0.17f;
    } else {
        func_003E4590(&pos, &D_001DEB00[s->a].v30, &D_001DEB00[s->b].v30, t);
        p = D_001DEB00[s->a].v70;
        q = D_001DEB00[s->b].v70;
        rot.z = func_003E5630(func_003E5678(q.z, p.z) * t, p.z);
        rot.y = func_003E5630(func_003E5678(q.y, p.y) * t, p.y);
        rot.x = func_003E5630(func_003E5678(q.x, p.x) * t, p.x);
    }
    func_003C1740(0, &pos);
    func_003C17B0(0, &rot);
}
/* localdecomp:end func_003B2F10 */
