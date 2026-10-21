#include "common.h"

/* localdecomp:start func_00433628 */
typedef struct {
    u8 pad[0x1FCA8];
    u8 sub[4];
} Unk00433628;

extern Unk00433628 *D_001D67C8;
extern void func_004CAA98(void *, s32, s32, s32);

void func_00433628(s32 a0, s32 a1, s32 a2) {
    if (D_001D67C8 != 0) {
        func_004CAA98(D_001D67C8->sub, a2, a0, a1);
    }
}
/* localdecomp:end func_00433628 */
