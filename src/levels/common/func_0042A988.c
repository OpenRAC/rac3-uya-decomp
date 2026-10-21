#include "common.h"

typedef struct {
    s32 count;
    s32 A[8];
    s32 D[8];
    s32 B[8];
    s32 C[8];
    s32 E[8];
} S_42A988;
extern S_42A988 D_0021F660;
extern u8 D_001FDC50[];
extern s16 D_001FDA70[];
extern s32 D_002006F0[];
extern s32 D_001FD200[];
extern s32 D_001E0080;
extern s32 D_001E008C;
extern s32 D_001D4BB4;

/* localdecomp:start func_0042A988 */
void func_0042A988(void) {
    s32 a, b, c, m;
    if (D_0021F660.count != 0) {
        D_0021F660.count--;
        c = D_0021F660.C[D_0021F660.count];
        b = D_0021F660.B[D_0021F660.count];
        a = D_0021F660.A[D_0021F660.count];
        D_0021F660.A[D_0021F660.count] = 0;
        m = D_001E0080 - 1;
        D_001E0080 = m;
        D_0021F660.D[D_0021F660.count] = 0;
        D_0021F660.B[D_0021F660.count] = 0;
        D_001FDA70[m] = -1;
        D_001FD200[m] = 0;
        D_001FDC50[a] = 255;
        D_002006F0[m] = 0;
        D_0021F660.C[D_0021F660.count] = 0;
        D_001E008C = b;
        D_001D4BB4 = c;
        D_0021F660.E[D_0021F660.count] = 0;
    }
}
/* localdecomp:end func_0042A988 */
