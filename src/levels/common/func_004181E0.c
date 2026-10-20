#include "common.h"

extern s32 func_00418130(s32);
extern u8 *D_001DFD40;
extern u8 *D_001D52FC;

s32 func_004181E0(s32 a) {
    s32 i = func_00418130(a);
    s16 h = *(s16 *)(D_001DFD40 + i * 16 + 12);
    if (h > 0 && D_001D52FC[1360] != 0) {
        return h;
    }
    return a;
}
