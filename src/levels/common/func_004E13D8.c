#include "common.h"

/* localdecomp:start func_004E13D8 */
typedef int Q_4E13D8 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_4E13D8;
typedef struct {
    V4_4E13D8 r[4];
} M4_4E13D8;
extern M4_4E13D8 D_001A4C70;
extern void func_0040C658(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040C9B0(void *, void *, void *);
extern void func_00447748(void *, void *);
void func_004E13D8(void *a, f32 x, f32 y, f32 z) {
    V4_4E13D8 s0, s1, s2, t;
    M4_4E13D8 m1, m2;
    V4_4E13D8 vv;
    Q_4E13D8 p, q, r, w, r2, w2;
    *(Q_4E13D8 *)&s0 = *(Q_4E13D8 *)a;
    func_0040C658(&m1, &D_001A4C70);
    func_0040C2F8(&s1, &s0, &m1);
    vv.x = x;
    vv.y = y;
    vv.z = z;
    func_0040C658(&m2, &vv);
    func_0040C9B0(&m1, &m1, &m2);
    func_0040C2F8(&s2, &s0, &m1);
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(s2));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(s1));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
    __asm__("lqc2 %0, %1" : "=j"(w) : "m"(*(V4_4E13D8 *)((u8 *)&D_001A4C70 - 0x10)));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
    __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(w2) : "j"(w), "j"(r2));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_4E13D8 *)((u8 *)&D_001A4C70 - 0x10)) : "j"(w2));
    func_00447748(&m1, &D_001A4C70);
}
/* localdecomp:end func_004E13D8 */
