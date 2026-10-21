#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003ADAC0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AECC8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF0D0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF408);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF490);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF578);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF630);

LINKER_REMNANT("asm/veldin/remnants", func_003AF740);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF748);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF778);

/* localdecomp:start func_003AF870 */
typedef int Q_3AF870 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AF870;
typedef struct { V4_3AF870 r[4]; } M4_3AF870;
typedef struct { f32 a, b; } P_3AF870;
extern P_3AF870 D_001DE610[1];
extern s32 D_001DE640[2];
extern f32 D_001DE600[2];
extern f32 D_001DE5F0[2];
extern void func_00437698(void *, s32, void *);
extern void func_00437600(void *, s32, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0044E620(void *, s32, f32, f32);
void func_003AF870(void *o) {
    V4_3AF870 v;
    M4_3AF870 m;
    V4_3AF870 w;
    s32 i;
    for (i = 0; i < 3; i++) {
        Q_3AF870 qa, qb, qr;
        func_00437698(o, 8, &v);
        func_00437600(o, 8, &m);
        func_0040C2F8(&w, &D_001DE610[i * 2], &m);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(w));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
        func_0044E620(&v, D_001DE640[i], D_001DE600[i], D_001DE5F0[i]);
    }
}
/* localdecomp:end func_003AF870 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AF958);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AFB80);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003AFB88);

