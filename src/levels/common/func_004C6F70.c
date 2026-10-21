#include "common.h"

/* localdecomp:start func_004C6F70 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4C6F70;
typedef int Q_4C6F70 __attribute__((mode(TI)));
extern s32 D_001DB02C;
extern s32 D_001A71A0[];
extern void func_004495F8(s32, s32, s32, void *);
void func_004C6F70(V_4C6F70 *dst, V_4C6F70 *src, s32 a2) {
    V_4C6F70 t;
    if (D_001DB02C != 0) {
        func_004495F8(D_001A71A0[0], D_001DB02C, a2, &t);
        __asm__ __volatile__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %2" : : "m"(*src), "m"(t), "m"(*dst));
    } else {
        *(Q_4C6F70 *)dst = *(Q_4C6F70 *)src;
    }
}
/* localdecomp:end func_004C6F70 */
