#include "common.h"

/* localdecomp:start func_005EEAE8 */
/* PROVISIONAL, VU0 j-constraint form. */

typedef int Q_005EEAE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005EEAE8;
extern V_005EEAE8 D_0024DF00[];
extern void func_0058F358(V_005EEAE8 *, V_005EEAE8 *, f32);
extern void func_0058F648(V_005EEAE8 *, V_005EEAE8 *, f32);
extern f32 func_0058F4E0(u8 *, V_005EEAE8 *);
extern s32 func_0057F278(u8 *, V_005EEAE8 *, s32, s32, s32);

s32 func_005EEAE8(u8 *o, u8 *a, V_005EEAE8 *b) {
    V_005EEAE8 v;
    Q_005EEAE8 x, y, r;
    if (b == 0) {
        b = D_0024DF00;
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_005EEAE8 *)(o + 0x20)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    func_0058F358(&v, &v, 0.75f);
    func_0058F648(&v, &v, 64.0f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    if (func_0058F4E0(a, &v) > 900.0f) {
        return 0;
    }
    return func_0057F278(a, &v, 0x82, *(s32 *)(o + 0x1C), 0);
}
/* localdecomp:end func_005EEAE8 */
