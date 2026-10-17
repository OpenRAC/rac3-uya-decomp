#include "common.h"
typedef struct {
    u8 pad0[508];
    s16 h1FC;
    u8 pad1FE[9854];
    s16 h287C;
} G_4E8770;
extern G_4E8770 D_001A4BE0;
void func_004E8770(s32 a0) {
    switch (a0) {
    case 19:
    case 39:
    case 63:
    case 151:
        D_001A4BE0.h287C = 3;
        D_001A4BE0.h1FC = 70;
        break;
    }
}
