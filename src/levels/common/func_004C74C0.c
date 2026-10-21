#include "common.h"

typedef int Q_4C74C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4C74C0;
extern void func_00437698(u8 *a, s32 b, void *c);
extern u8 *func_00440728(u8 *a);
extern void func_0040BE90(void *a, void *b, f32 c);

/* localdecomp:start func_004C74C0 */
s32 func_004C74C0(V_4C74C0 *a0, u8 *a1, s32 a2) {
    Q_4C74C0 x, y;
    u8 *r;
    if (a1 != 0) {
        if (a2 != 0) {
            func_00437698(a1, a2, a0);
            return 1;
        } else {
            *(Q_4C74C0 *)a0 = *(Q_4C74C0 *)(a1 + 0x10);
            r = func_00440728(a1);
            if (r != 0) {
                func_0040BE90(a0, a1 + 0xE0, *(f32 *)(r + 0x10));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a0));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_4C74C0 *)(a1 + 0x10)));
                __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(x));
                if (*(s16 *)(a1 + 0xAA) == 0x1AB8) {
                    func_00437698(a1, 4, a0);
                }
                if (*(s16 *)(a1 + 0xAA) == 0x1C08) {
                    func_00437698(a1, 5, a0);
                }
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004C74C0 */
