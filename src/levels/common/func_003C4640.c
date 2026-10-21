#include "common.h"

/* localdecomp:start func_003C4640 */
extern s32 D_001DF9DC[];
extern void func_003E9730(s32 a0, s32 a1);
extern void func_003C4570(s32 a0, s32 a1, s32 a2);
void func_003C4640(s32 a0, s32 a1) {
    func_003E9730(0, 3);
    func_003C4570(a0, a1, 0);
    D_001DF9DC[0] = 0;
}
/* localdecomp:end func_003C4640 */
