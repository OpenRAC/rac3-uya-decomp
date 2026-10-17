#include "common.h"

typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G4C67B8;

extern G4C67B8 D_001CFEC0;
extern s16 D_001E1182;
extern f32 D_001E1184;
extern void func_004C1FE8(s32, s32);
extern void func_00403708(s32, s32, s32, s32, long);

void func_004C67B8(void)
{
    s32 c;

    func_004C1FE8(66, 68);
    c = (s32)((1.0f - (f32)D_001E1182 * D_001E1184) * 255.0f);
    func_00403708(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, c << 24);
}
