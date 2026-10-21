#include "common.h"

/* localdecomp:start func_004D13B0 */
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);

typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; } S_ACAA8;
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
void func_004D13B0(S_ACAA8 *p) {
    func_0011EE60(p->w40);
    p->w14 = (p->w14 + 0x7FF) / 0x800 * 0x800;
    func_0011EE40(p->w40);
}
/* localdecomp:end func_004D13B0 */
