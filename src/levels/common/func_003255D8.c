#include "common.h"

typedef struct {
    u8 pad[24];
    s32 f24;
    u8 pad2[28];
} Unk002AEA90;

extern Unk002AEA90 D_002AEA90[];
extern s32 D_001D7BE0;
extern s32 D_001E0198;
extern s32 D_001D4C38;

void func_003255D8(s32 a0, u8 *a1) {
    s32 n = *(s32 *)(a1 + 92);
    if (n >= 0) {
        s32 v = (&D_002AEA90[n])->f24;
        if (v != 0) {
            D_001D7BE0 = v;
            D_001E0198 = D_001D4C38;
        }
    }
}
