#include "common.h"

/* localdecomp:start func_0045B9C8 */
extern void func_0040BBA8(void *, s32, s32);
extern void func_0040BCB8(u8 *, u8 *, s32);
extern void func_0013CC40(s32);
typedef struct {
    u8 pad0[0x6C];
    s32 f6C;
    u8 pad1[0x76 - 0x70];
    s16 f76;
    u8 pad2[0x94 - 0x78];
    s32 f94;
    s16 f98;
    u8 pad3[0x9E - 0x9A];
    s16 f9E;
    u8 pad4[0xB4 - 0xA0];
    s32 fB4;
} S_001CCFD0_0039C710;
extern S_001CCFD0_0039C710 D_001CCFD0_0039C710[];
s32 func_0045B9C8(void) {
    S_001CCFD0_0039C710 *p = D_001CCFD0_0039C710;

    if (p->f76 == 0 && p->f9E == 3) {
        if (p->f94 != 0) {
            func_0040BCB8((u8 *)&p->f6C, (u8 *)&p->f94, 0x28);
            func_0040BBA8(&p->f94, 0, 0x28);
            p->f98 = -1;
            p->fB4 = -1;
            func_0013CC40(p->f6C);
            p->f76 = 4;
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0045B9C8 */
