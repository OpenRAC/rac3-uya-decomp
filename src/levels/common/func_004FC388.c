#include "common.h"
typedef struct {
    u8 pad0[440];
    s32 start;
    u8 pad1[9172 - 444];
    s32 ids[32];
    s32 lens[16];
    s32 count;
} S_4FC388;
extern S_4FC388 D_001A4BE0;
s32 func_004FC388(s32 a0, s32 a1) {
    s32 i;
    s32 acc = D_001A4BE0.start;
    for (i = 0; i < D_001A4BE0.count; i++) {
        if (a1 < acc) return 0;
        if (D_001A4BE0.ids[i] == a0) return 1;
        acc += D_001A4BE0.lens[i];
    }
    return 0;
}
