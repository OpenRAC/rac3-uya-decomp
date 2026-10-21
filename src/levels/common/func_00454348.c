#include "common.h"

/* localdecomp:start func_00454348 */
typedef int Q_454348 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_454348;
typedef struct { V_454348 m[4]; } M_454348;
typedef struct {
    u8 pad[0x10];
    V_454348 v10;
    u8 pad20[0xF0 - 0x20];
    M_454348 vF0;
} O_454348;
extern void func_0040C658(M_454348 *, void *);
extern void func_0040C2F8(V_454348 *, V_454348 *, M_454348 *);
extern void func_0040C9B0(M_454348 *, M_454348 *, M_454348 *);
extern void func_00447748(M_454348 *, M_454348 *);
void func_00454348(O_454348 *o, V_454348 *b, f32 x, f32 y, f32 z) {
    V_454348 a, t10, t20, t30;
    M_454348 t40;
    V_454348 t80;
    M_454348 t90;
    Q_454348 p, q, r, s, u, w;
    a = *b;
    func_0040C658(&t40, &o->vF0);
    func_0040C2F8(&t10, &a, &t40);
    t80.x = x;
    t80.y = y;
    t80.z = z;
    func_0040C658(&t90, &t80);
    func_0040C9B0(&t40, &t40, &t90);
    func_0040C2F8(&t20, &a, &t40);
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(t20));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(t10));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
    __asm__("lqc2 %0, %1" : "=j"(s) : "m"(o->v10));
    __asm__("sqc2 %1, %0" : "=m"(t30) : "j"(r));
    __asm__("lqc2 %0, %1" : "=j"(u) : "m"(t30));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(w) : "j"(s), "j"(u));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(w));
    func_00447748(&t40, &o->vF0);
}
/* localdecomp:end func_00454348 */
