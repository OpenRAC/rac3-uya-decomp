#include "common.h"

/* localdecomp:start func_003B6A98 */
typedef int Q_3B6A98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B6A98;
typedef struct { Q_3B6A98 q[40]; } T_3B6A98;
extern s32 D_001DE5A0;
extern s32 D_001DE5A4;
extern f32 D_001DE5A8;
extern s32 D_001DE5AC;
extern s32 D_001DE5B0;
extern s32 D_001DE5C0;
extern T_3B6A98 D_002A3270[];
extern void func_003E79E0(V4_3B6A98 *, V4_3B6A98 *, f32);

static __inline__ void vadd_3B6A98(void *o, void *a, void *b) {
    Q_3B6A98 qa, qb, qc;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_3B6A98 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(V4_3B6A98 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qc) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3B6A98 *)o) : "j"(qc));
}

void func_003B6A98(u8 *a0) {
    V4_3B6A98 d;
    V4_3B6A98 step;
    Q_3B6A98 x, y, r;
    u8 *s;
    s32 i;

    s = *(u8 **)(a0 + 0x68);
    if (D_001DE5A4 != 0) {
        D_001DE5A4 = 0;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3B6A98 *)(s + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3B6A98 *)s));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__(".set noreorder\n\tsqc2 %1, %0\n\t.set reorder" : "=m"(d) : "j"(r));
        func_003E79E0(&step, &d, D_001DE5A8 / (f32)D_001DE5A0);
        __asm__("sq %1, %0" : "=m"(D_002A3270[*(s32 *)(s + 0x38)].q[0]) : "r"(*(Q_3B6A98 *)s) : "memory");
        for (i = 1; i < D_001DE5A0; i++) {
            vadd_3B6A98(&D_002A3270[*(s32 *)(s + 0x38)].q[i], &D_002A3270[*(s32 *)(s + 0x38)].q[i - 1], &step);
        }
        D_001DE5AC = 0;
        D_001DE5B0 = 0;
        D_001DE5C0 = 0;
    }
}
/* localdecomp:end func_003B6A98 */
