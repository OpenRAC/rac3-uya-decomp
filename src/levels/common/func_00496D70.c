#include "common.h"

/* localdecomp:start func_00496D70 */
extern u8 *D_001D52FC;
extern s32 func_0049D8C8(void);
extern void func_00513758(s32 a0);
extern void func_005120B8(s32 a0);
void func_00496D70(s32 a0) {
    if (*(s32 *)(D_001D52FC + 452) & 0x910) {
        func_00513758(func_0049D8C8());
        func_005120B8(a0);
    }
}
/* localdecomp:end func_00496D70 */
