#include "common.h"

/* localdecomp:start func_003E8D18 */
typedef int u128_3E8D18 __attribute__((mode(TI)));
typedef struct { u8 pad[0x200]; u8 x200[0x30]; u128_3E8D18 x230; u8 pad240[0x2A0 - 0x240]; s16 x2A0; u8 pad2A2[0x2C0 - 0x2A2]; f32 x2C0; u8 pad2C4[1120 - 0x2C4]; } E_3E8D18;
typedef struct { u8 pad[0x25E5]; u8 x25E5; } G_3E8D18;
typedef struct { u8 pad[0x30]; u128_3E8D18 x30; u8 pad40[0x94 - 0x40]; s32 x94; } O_3E8D18;
extern E_3E8D18 D_001E2AC0[];
extern G_3E8D18 D_001A4BE0;
extern u8 D_001A71C5[];
extern void func_0040BCB8(O_3E8D18 *, void *, s32);
void func_003E8D18(O_3E8D18 *a0) {
    E_3E8D18 *e = &D_001E2AC0[a0->x94];
    a0->x30 = e->x230;
    func_0040BCB8(a0, e->x200, 48);
    if (e->x2A0 == 3 && e->x2C0 >= 0.5f) {
        if (D_001A4BE0.x25E5 == 0) {
            D_001A4BE0.x25E5 = 1;
        } else {
            e->x2C0 = 1.0f;
        }
    } else if (e->x2A0 == 0) {
        D_001A71C5[0] = 1;
    }
}
/* localdecomp:end func_003E8D18 */
