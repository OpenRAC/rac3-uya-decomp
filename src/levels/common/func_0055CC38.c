#include "common.h"

/* localdecomp:start func_0055CC38 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_0055CC38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0055CC38;
extern void func_005A8630(u8 *);
extern void func_0058F358(V_0055CC38 *, u8 *, f32);
extern void func_005891B8(void (*)(void), u8 *);
extern void func_00588FB0(void (*)(void), u8 *);
extern void func_0055CD18(void);
extern void func_0055CD78(void);

void func_0055CC38(u8 *o) {
    u8 **s = *(u8 ***)(o + 0x68);
    V_0055CC38 a;
    V_0055CC38 b;
    Q_0055CC38 x, y, r;
    if (*s != 0 && *(s32 *)(*s + 0x2558) == 0) {
        func_005A8630(o);
        return;
    }
    a = *(V_0055CC38 *)(*s + 0xA0);
    func_0058F358(&b, *s + 0x40, 0.8f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(r));
    if (o[0x20] == 0) {
        func_005891B8(func_0055CD18, o);
        o[0x20] = 1;
    }
    *(V_0055CC38 *)(o + 0x10) = *(V_0055CC38 *)(*s + 0xA0);
    *(f32 *)(o + 0x18) += 2.0f;
    func_00588FB0(func_0055CD78, o);
}
/* localdecomp:end func_0055CC38 */
