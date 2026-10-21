#include "common.h"

/* localdecomp:start func_00424368 */
extern s32 D_002006F0[];
extern s32 D_001FD200[];
extern void func_00424048(s32, s32, void *, s32);
extern u8 D_001FDC50[];

typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_001FDC50[];
extern s16 D_001FDA70[];
extern s32 D_001FD200[];
extern s32 D_002006F0[];
extern s32 D_001E0080;
extern s32 D_001E0084;
extern void func_00424048(s32, s32, void *, s32);
extern void func_0045B030();
void func_00424368(S_4F78 *a, s32 b, void *c, s32 d) {
    if (a == 0) {
        func_0045B030(d, 1);
        D_001FDC50[d] = D_001E0084;
        D_001E0084 = D_001E0084 + 1;
    } else {
        D_001FDA70[D_001E0080] = d;
        D_001FDC50[d] = D_001E0080;
        D_001FD200[D_001E0080] = (s32)a;
        D_002006F0[D_001E0080] = a->b2D << 10;
        if (a->b2D == 0xFF) D_002006F0[D_001E0080] = 0x100000;
        func_00424048((s32)a, b, c, d);
        func_0045B030(d, 0);
        D_001E0080 = D_001E0080 + 1;
    }
}
/* localdecomp:end func_00424368 */
