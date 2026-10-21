#include "common.h"

/* localdecomp:start func_0049FD60 */
extern u8 D_00236C10[];
extern u8 D_00237880[];
extern s32 D_001E0DB0;
extern void func_0040BBA8(void *p, int v, int n);

void func_0049FD60(void)
{
    func_0040BBA8(D_00236C10, 0, 3184);
    func_0040BBA8(D_00237880, 0, 3184);
    func_0040BBA8(&D_001E0DB0, 0, 64);
}
/* localdecomp:end func_0049FD60 */
