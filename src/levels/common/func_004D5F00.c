#include "common.h"

/* localdecomp:start func_004D5F00 */
extern s32 func_004D4840(void);
extern void func_004D5CE0(void *a);
void func_004D5F00(void *a) {
    if (func_004D4840() == 2) return;
    if (func_004D4840() == 3) return;
    func_004D5CE0(a);
}
/* localdecomp:end func_004D5F00 */
