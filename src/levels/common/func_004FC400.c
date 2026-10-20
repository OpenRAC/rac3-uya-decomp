#include "common.h"
typedef struct {
    u8 pad[9676];
    s32 w9676;
    u8 pad2[640];
    s32 w10320;
} S_004FC400;
extern S_004FC400 D_001A4BE0;
extern s32 D_001D6694;
s32 func_004FC400(s32 a0, s32 a1) {
    S_004FC400 *g;
    s32 v;
    if (a1 == 3) {
        return 1;
    }
    if (D_001A4BE0.w9676 == 20) {
        if (a0 != 101 || a1 != 2) {
            return 0;
        }
    }
    v = D_001D6694;
    if ((v == 2 || v == 6) && a1 != 2) {
        return 0;
    }
    g = &D_001A4BE0;
    if (g->w10320 == 0) {
        v = g->w9676;
        if (v == 2 || v == 7) {
            if (!(a0 == 6 || a0 == 57 || a0 == 67 || a0 == 86 || a0 == 99 || a0 == 159 || a0 == 160 || a0 == 121 ||
                  a0 == 125 || a0 == 126 || a0 == 129 || a0 == 80 || a0 == 108 || a0 == 130 || a0 == 132)) {
                return 0;
            }
        }
    }
    return 1;
}
