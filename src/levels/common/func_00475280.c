#include "common.h"

/* localdecomp:start func_00475280 */
extern void func_00475280(void);
extern void *func_00511BF8();

extern void *func_00511BF8();
extern void func_00511B18(void *);
extern u8 D_001E1660[];
 
void func_00475280(void) {
    void *x = D_001E1660;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_00511BF8();
    }
    func_00511B18(x);
}
/* localdecomp:end func_00475280 */
