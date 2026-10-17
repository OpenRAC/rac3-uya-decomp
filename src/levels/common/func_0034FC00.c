#include "common.h"
extern u8 D_001DD5B0[4];
extern u8 D_001DD5B8[8];
extern u8 D_001DD5D8[8];
u8 *func_0034FC00(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 0:
        *a2 = 4;
        return D_001DD5B0;
    case 1:
        *a2 = 28;
        return D_001DD5B8;
    case 2:
        *a2 = 12;
        return D_001DD5D8;
    }
    return 0;
}
