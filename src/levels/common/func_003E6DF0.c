#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *o;
    u8 rest[1036];
} S_1E2AC0;

typedef struct {
    u8 pad[112];
    u8 *o;
    u8 rest[60];
} S_1E5150;

extern S_1E2AC0 D_001E2AC0[];
extern S_1E5150 D_001E5150[];

void func_003E6DF0(s32 a0, s32 a1, f32 f12, f32 f13) {
    u8 *m;
    u8 *o = (&D_001E2AC0[a0])->o;
    if (*(s16 *)(o + 134) == 0) {
        m = *(u8 **)(o + 112) + 96;
        *(s16 *)(m + 250) = 1;
        *(f32 *)(m + 216) = f13;
        if (a1 != 0) {
            *(f32 *)(m + 212) = *(f32 *)((&D_001E5150[a0])->o + 304) + f12;
        } else {
            *(f32 *)(m + 212) = f12;
        }
    }
}
