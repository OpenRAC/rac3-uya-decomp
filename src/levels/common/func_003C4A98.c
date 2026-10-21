#include "common.h"

typedef int Q_3C4A98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C4A98;
extern void func_0040C0F0(void *a, void *b, f32 x);

/* localdecomp:start func_003C4A98 */
void func_003C4A98(u8 *a, f32 *b) {
    Q_3C4A98 x, r;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_3C4A98 *)(a + 0xC0)));
    __asm__("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(*(V_3C4A98 *)b) : "j"(r));
    b[2] = 0.0f;
    func_0040C0F0(b, b, 1.0f);
}
/* localdecomp:end func_003C4A98 */
