#include "common.h"

typedef int Q_3CB2C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CB2C0;
extern void func_003CB7B8(void);
extern void func_003CB628(u8 *a, void *b);
extern s32 func_0040BA90(u8 *a);
extern void func_00436220(u8 *a);
extern void func_004026A0(void (*f)(void), u8 *a);

/* localdecomp:start func_003CB2C0 */
void func_003CB2C0(u8 *a0) {
    V_3CB2C0 v;
    Q_3CB2C0 x, y;
    u8 *s = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        a0[0x20] = 1;
    case 1:
        *(Q_3CB2C0 *)&v = *(Q_3CB2C0 *)(a0 + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3CB2C0 *)(a0 + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_3CB2C0 *)s));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V_3CB2C0 *)(a0 + 0x10)) : "j"(x));
        func_003CB628(a0, &v);
        if (func_0040BA90(s + 0x10) != 0) {
            a0[0x20] = 2;
        }
        break;
    case 2:
        func_00436220(a0);
        return;
    }
    func_004026A0(func_003CB7B8, a0);
}
/* localdecomp:end func_003CB2C0 */
