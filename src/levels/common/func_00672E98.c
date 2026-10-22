#include "common.h"

/* localdecomp:start func_00672E98 */
typedef struct {
    u8 pad0[0x48];
    s16 f48;
    s16 f4A;
    u8 pad4c[0xC];
    s32 f58;
    s32 f5C;
    u8 pad60[0x10];
    s32 f70;
    s32 f74;
    s32 f78;
    u8 pad7c[0x14];
} S_672E98;

extern S_672E98 D_00498BD0[];
extern u8 D_001DAE00[8];
extern u8 *func_006197C0(s32);
extern s32 func_005C2098(s32, s32);
extern void func_006725B8(u8 *, u8 *);

void func_00672E98(S_672E98 *p) {
    s32 i = (p - D_00498BD0) - 8;
    u8 *pl = func_006197C0(i);
    s32 m = func_005C2098(8, *(s32 *)(pl + 0x2544));
    u8 *q = *(u8 **)(pl + 0x2534);

    if (*(s32 *)(q + 0x1C0) & (m | 2)) {
        *(s32 *)(q + 0x1C4) = 0;
        D_001DAE00[i] = 5;
    } else {
        D_001DAE00[i] = 0;
    }
    func_006725B8(pl, q);
    p->f58 = 0xD2;
    p->f5C = 0xC8;
    p->f74 = -2;
    p->f78 = 0x1E;
    p->f48 = 0;
    p->f4A = 0;
    p->f70 = 0;
}
/* localdecomp:end func_00672E98 */
