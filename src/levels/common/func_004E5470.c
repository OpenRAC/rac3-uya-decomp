#include "common.h"

/* localdecomp:start func_004E5470 */
extern char D_001A4BE0[];

int func_004E5470(int a0) {
    char *p = D_001A4BE0 + a0 * 80;
    if (*(int *)(p + 4644) == 2) {
        return *(int *)(p + 4648);
    }
    return -1;
}
/* localdecomp:end func_004E5470 */
