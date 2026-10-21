#include "common.h"

/* localdecomp:start func_004BBAF0 */
typedef struct { u8 p0[72]; s32 f72; } A_4BBAF0;
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_4BBAF0;
typedef struct {
    u8 p0[320];
    E_4BBAF0 e[76];
    u8 p1[1856 - 320 - 76 * 20];
    s32 count;
    u8 p2[44];
    s32 f1904;
    u8 p3[4];
    s32 f1912;
} B_4BBAF0;

extern A_4BBAF0 D_00142660;
extern B_4BBAF0 D_00244740;
extern u8 D_00142CB5[];
extern u8 D_00142CB1[];
extern u8 D_00142CB3[];
extern u8 D_00142CB6[];
extern u8 D_00142CB0[];
extern s32 D_001DAE18;
extern void func_004BBA70(s32);

s32 func_004BBAF0(void) {
    s32 n, m, i, r, t;
    if (D_00142660.f72 & 2) func_004BBA70(21);
    if (D_00142660.f72 & 4) func_004BBA70(17);
    if (D_00142660.f72 & 8) func_004BBA70(19);
    if (D_00142660.f72 & 0x10) func_004BBA70(22);
    if (D_00142660.f72 & 0x20) func_004BBA70(16);
    m = 0;
    n = 0;
    D_00244740.f1912 = 0;
    for (i = 0; i < D_00244740.count; i++) {
        t = D_00244740.e[i].type;
        if (t == 16 || t == 17 || t == 19 || t == 21 || t == 22) {
            if (D_00244740.e[i].b4 == 0 && D_00244740.e[i].b16 != 0) D_00244740.f1912++;
        }
    }
    if ((D_00142660.f72 & 2) || D_00142CB5[0]) n = 1;
    if ((D_00142660.f72 & 4) || D_00142CB1[0]) n++;
    if ((D_00142660.f72 & 8) || D_00142CB3[0]) n++;
    if ((D_00142660.f72 & 0x10) || D_00142CB6[0]) n++;
    if ((D_00142660.f72 & 0x20) || D_00142CB0[0]) n++;
    for (i = 0; i < D_00244740.count; i++) {
        if (D_00244740.e[i].b19 == 0) m++;
    }
    r = n == m;
    D_00244740.f1904 = r;
    if (D_001DAE18 != r) {
        D_001DAE18 = r;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004BBAF0 */
