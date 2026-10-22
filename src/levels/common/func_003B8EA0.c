#include "common.h"

/* localdecomp:start func_003B8EA0 */
typedef int Q_3B8EA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3B8EA0;
typedef struct { V_3B8EA0 pos; u8 pad10[0x18]; f32 f28; } O_3B8EA0;
extern void func_00418598(V_3B8EA0 *a, f32 x, f32 y);
extern f32 func_003E4660(V_3B8EA0 *a);

void func_003B8EA0(O_3B8EA0 *o, V_3B8EA0 *v, f32 *out, f32 x) {
    Q_3B8EA0 a, b;
    func_00418598(v, x * o->f28, o->f28);
    if (out != 0 && o->f28 > 0.0f) {
        *out = func_003E4660(v) / o->f28;
    }
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*v) : "j"(a));
}
/* localdecomp:end func_003B8EA0 */
