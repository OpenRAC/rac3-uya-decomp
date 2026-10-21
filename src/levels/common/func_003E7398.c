#include "common.h"
typedef int Q_003E7398 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E7398;
typedef struct { u8 pad[0x70]; u8 *p; } O_003E7398;
extern void func_003E7168(void *, V4_003E7398 *);
/* localdecomp:start func_003E7398 */
void func_003E7398(O_003E7398 *o, V4_003E7398 *v) {
    V4_003E7398 t;
    Q_003E7398 a, b, r;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_003E7398 *)(o->p + 0x60)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
    func_003E7168(o, &t);
}
/* localdecomp:end func_003E7398 */
