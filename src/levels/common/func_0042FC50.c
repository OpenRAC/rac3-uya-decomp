#include "common.h"

/* localdecomp:start func_0042FC50 */
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_00396C48[];
extern void (*D_001D7590)();
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
void func_0042FC50(void) {
    S_00396C48 *p = D_00142430_00396C48;
    s32 v = D_001D4CEC & ~2;
    D_001D4CEC = v;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC = v | 0x440;
                D_001D4CE8 = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8 = 1;
            }
            if (D_001D7590 != 0) {
                D_001D7590();
                D_001D7590 = 0;
            }
        }
    }
}
/* localdecomp:end func_0042FC50 */
