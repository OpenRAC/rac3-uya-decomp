#include "common.h"

/* localdecomp:start func_00418260 */
typedef struct {
    s32 w0;
    u8 pad4[0x34];
    s16 h38;
    s16 pad3A;
    s32 w3C;
} S_002E5F70;
extern S_002E5F70 D_002E5F70;
extern void func_00417ED8(void);
void func_00418260(void) {
    if (D_002E5F70.h38 == 0) {
        D_002E5F70.h38 = 1;
        D_002E5F70.w3C = 0x3C;
        func_00417ED8();
        if (D_002E5F70.w0 == 0) {
            D_002E5F70.w0 = 8;
        }
    }
}
/* localdecomp:end func_00418260 */
