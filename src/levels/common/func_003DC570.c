#include "common.h"

/* localdecomp:start func_003DC570 */
extern u8 *func_00440728(void);

void func_003DC570(void) {
    u8 *p = func_00440728();
    if (p != 0 && (u8)(p[14] - 1) < 2) {
        p[14] = 2;
    }
}
/* localdecomp:end func_003DC570 */
