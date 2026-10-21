#include "common.h"

/* localdecomp:start func_004498A0 */
typedef int Q_4498A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4498A0;
extern u8 *func_00449388(u8 *);
extern void func_0040C658(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040C9B0(void *, void *, void *);
extern void func_00447748(void *, void *);
s32 func_004498A0(s32 a0, u8 *obj, V4_4498A0 *p, void *a3, void *a4, void *a5) {
    V4_4498A0 m[4];
    V4_4498A0 d;
    V4_4498A0 t[4];
    u8 *info;
    Q_4498A0 x, y, r;
    info = func_00449388(obj);
    if (info == 0) {
        return 0;
    }
    if (*(u32 *)(info + 0x3C) & 0x40) {
        func_0040C658(m, obj + 0xF0);
        func_0040C8E0(m, m);
    } else {
        func_0040C8E0(m, obj + 0xC0);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_4498A0 *)(obj + 0x10)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    func_0040C2F8(a4, &d, m);
    func_0040C658(t, a3);
    func_0040C9B0(t, m, t);
    func_00447748(t, a5);
    return 1;
}
/* localdecomp:end func_004498A0 */
