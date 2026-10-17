#include "common.h"

typedef struct {
    u8 pad0[60];
    s16 h60;
    s16 h62;
    u8 pad64[8];
    s16 h72;
    u8 pad74[4];
    s16 h78;
    u8 pad80[118];
    s16 h198;
} D_001CCFD0_t;

extern D_001CCFD0_t D_001CCFD0;

void func_0045BE58(s32 a0, s32 a1) {
    if (D_001CCFD0.h72 != a0 || D_001CCFD0.h60 != -1) {
        if (a0 != -1) {
            a0 &= 0xff;
        }
        if (a1 != -1) {
            a0 &= 0xff;
        }
        if (D_001CCFD0.h78 == 0 && D_001CCFD0.h198 == 0) {
            D_001CCFD0.h72 = a0;
        } else {
            D_001CCFD0.h60 = a0;
            D_001CCFD0.h62 = a1;
        }
    }
}
