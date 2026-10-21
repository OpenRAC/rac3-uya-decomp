#include "common.h"

/* localdecomp:start func_004DC870 */
typedef struct {
    u8 pad0[4448];
    s32 unk1160;
    s32 unk1164;
    s32 unk1168;
} D_001A4BE0_t;

extern D_001A4BE0_t D_001A4BE0;
extern s32 D_001DFBC0;
extern s32 func_00440848(s32);

void func_004DC870(void) {
    D_001A4BE0_t *p = &D_001A4BE0;
    s32 a;
    s32 b;

    if (p->unk1160 == 0) {
        if (p->unk1168 == 0) {
            p->unk1164 = D_001DFBC0 + 30;
        } else if (D_001DFBC0 > p->unk1164) {
            p->unk1160 = 1;
            p->unk1164 = D_001DFBC0 + 20 + func_00440848(p->unk1168) + func_00440848(p->unk1168);
        }
    }
}
/* localdecomp:end func_004DC870 */
