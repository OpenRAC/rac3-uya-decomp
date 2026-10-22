#include "common.h"

/* localdecomp:start func_00435E70 */
extern u32 D_001E00A0;
extern s32 D_001DFBC0;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3BCFB0;

extern u32 D_001E00A4;

extern s32 D_001DFFC0;
extern volatile u8 D_001D7B98;
extern s32 func_00438CE8();
extern void func_00435F98();
extern void func_0040BBA8();
extern int func_004388A8();
O_3BCFB0 *func_00435E70(s32 a, s32 b) {
    O_3BCFB0 *p;
    O_3BCFB0 *end;
    s32 r;
    end = (O_3BCFB0 *)D_001E00A4;
    p = (O_3BCFB0 *)D_001E00A0;
    if (p < (O_3BCFB0 *)D_001E00A4) do {
        if (p->f20 < 0xFE) continue;
        if ((u32)D_001DFBC0 < p->fA0) continue;
        r = 0;
        if (b) r = func_00438CE8(b);
        if (r == 0 && b) break;
        if (p->f20 == 0xFF) *((u8 *)p + 0x120) = p->f20;
        func_00435F98(p, a);
        p->f68 = r;
        if (b) func_0040BBA8(r, 0, b);
        if (D_001DFFC0) D_001DFFC0 = D_001DFFC0 - 1;
        return p;
    } while (++p < (O_3BCFB0 *)D_001E00A4);
    if (D_001D7B98) func_004388A8();
    return 0;
}
/* localdecomp:end func_00435E70 */
