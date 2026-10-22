#include "common.h"

/* localdecomp:start func_003F1FE8 */
typedef struct {
    u8 pad0[0x1BC];
    u16 h1BC;
    u8 pad1BE[2];
    u32 w1C0;
    u32 w1C4;
} S_3F1FE8;

extern void func_003F06C8(s32 id, s32 b);
extern s32 func_004E0130(void);
extern S_3F1FE8 D_001A7C10;
extern u32 D_001D4C38;
extern s32 D_001D545C;

void func_003F1FE8(s32 id, u32 t) {
    u32 now;

    if (func_004E0130() != 0) {
        return;
    }
    if (D_001A7C10.h1BC != 0 && t >= D_001D4C38 - D_001A7C10.w1C0) {
        return;
    }
    if (id == 0xB76) {
        func_003F06C8(0xB76, 0x19);
    } else if (id == 0xCD6) {
        func_003F06C8(0xCD6, 0x7F);
    } else if (id == 0xCD7) {
        func_003F06C8(0xCD7, 0x80);
    } else if (id == 0xCD8) {
        func_003F06C8(0xCD8, 0x81);
    }
    if (D_001A7C10.h1BC <= 0xFFFE) {
        D_001A7C10.h1BC++;
    }
    now = D_001D4C38;
    if (D_001A7C10.w1C0 < now) {
        D_001A7C10.w1C0 = now;
    }
    D_001A7C10.w1C4 = D_001A7C10.w1C4 | (1 << D_001D545C) | 0x80000000;
}
/* localdecomp:end func_003F1FE8 */
