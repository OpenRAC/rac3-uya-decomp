#include "common.h"

/* localdecomp:start func_00429AC0 */
extern s32 D_001D6DEC;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_00395958;
typedef struct { s32 f0; s32 f4; } S_00395958;

void func_00429AC0(S_00395958 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0->f4 >= 0) {
            D_0016C690_00395958.arr[arg0->f4] = arg0->f0;
            if (arg0->f4 == D_001D6DEC) {
                D_001D6DEC = arg0->f4 ^ 1;
            }
        }
    }
    arg0->f0 = -1;
}
/* localdecomp:end func_00429AC0 */
