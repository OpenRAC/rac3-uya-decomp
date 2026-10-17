#include "common.h"
typedef struct { u8 p[0x24]; } T36_45B030;
typedef struct { s32 k; s32 f4; T36_45B030 *f8; } E12_45B030;
extern E12_45B030 D_002F6880[];
extern T36_45B030 D_002F73B4[];
extern s32 D_001E0080;
extern s32 D_001E0084;
extern s32 D_001FFC50[];
extern u8 D_001FFE50[];
extern s32 D_001FD5C0[];
extern u8 D_001FD980[];
void func_0045B030(s32 key, s32 flag) {
    s32 i = 0;
    while (D_002F6880[i].k != -1 && D_002F6880[i].k != key) i++;
    if (flag) {
        D_001FFC50[D_001E0084] = D_002F6880[i].f4;
        D_001FFE50[D_001E0084] = D_002F6880[i].f8 - D_002F73B4;
    } else {
        D_001FD5C0[D_001E0080] = D_002F6880[i].f4;
        D_001FD980[D_001E0080] = D_002F6880[i].f8 - D_002F73B4;
    }
}
