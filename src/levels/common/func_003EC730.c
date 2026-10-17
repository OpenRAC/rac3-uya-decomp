#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;

extern Ent003EC730 D_001E2AC0[];
extern void func_0040BCB8(u8 *, void *, s32);

void func_003EC730(u8 *obj)
{
    Ent003EC730 *ent = &D_001E2AC0[*(s32 *)(obj + 148)];

    *(u128_t *)(obj + 48) = ent->v230;
    func_0040BCB8(obj, ent->b200, 48);
    *(u16 *)(obj + 126) = 0;
    ent->b2A3 = 0;
    D_001E2AC0[*(s32 *)(obj + 148)].f2C8 = 0.075f;
    D_001E2AC0[*(s32 *)(obj + 148)].f2B8 = 0.075f;
}
