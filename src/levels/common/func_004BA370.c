#include "common.h"

/* localdecomp:start func_004BA370 */
extern s32 D_00244790[];
extern void func_004B9A80(void);
extern void func_004BA008(void);

void func_004BA370(void) {
    s32 m = D_00244790[0];
    switch (m) {
    case 0:
    case 2:
        func_004B9A80();
        break;
    case 3:
        func_004B9A80();
        break;
    case 5:
        func_004BA008();
        break;
    }
}
/* localdecomp:end func_004BA370 */
