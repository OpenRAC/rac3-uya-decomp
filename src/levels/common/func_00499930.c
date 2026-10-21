#include "common.h"

/* localdecomp:start func_00499930 */
extern u8 *D_001D52FC;
extern void func_00499748(void);
extern s32 func_00497CF0(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);
void func_00499930(s32 a0) {
    if (*(s32 *)(D_001D52FC + 452) & 0x40) {
        func_00499748();
    }
    if (*(s32 *)(D_001D52FC + 452) & 0x910) {
        func_00513758(func_00497CF0());
        func_005120B8(a0);
    }
}
/* localdecomp:end func_00499930 */
