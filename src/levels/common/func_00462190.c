#include "common.h"

/* localdecomp:start func_00462190 */
typedef int Q_462190 __attribute__((mode(TI)));
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    Q_462190 q10;
    Q_462190 q20;
} P_462190;
extern u8 *D_00221154[];
extern P_462190 *func_0045E438(s32);
extern s32 func_13D3E0(void);

P_462190 *func_00462190(Q_462190 *a0, Q_462190 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f, s32 s) {
    P_462190 *p;
    u8 *b;
    if (a4 == 0) return 0;
    p = func_0045E438(15);
    if (p) {
        p->q10 = *a0;
        p->f4 = a2;
        *(f32 *)((u8 *)p + 0x1C) = (f32)s;
        p->f9 = 0xA4;
        if (a7 != -1) p->f3 = a7; else p->f3 = 0x48;
        p->f1 = 0;
        p->fC = f;
        p->f8 = func_13D3E0();
        if (a6 == -1) p->f2 = *D_00221154[0]; else p->f2 = a6;
        p->fA = a4;
        b = (u8 *)p + 0x20;
        *(s16 *)(b + 0x18) = a4;
        *(f32 *)(b + 0x1C) = f;
        *(s32 *)(b + 0x10) = a2;
        *(s32 *)(b + 0x14) = a3;
        *(s16 *)(b + 0x1A) = a5;
        p->q20 = *a1;
        *(f32 *)(b + 0xC) = 0.004055556f;
    }
    return p;
}
/* localdecomp:end func_00462190 */
