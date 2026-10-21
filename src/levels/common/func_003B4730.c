#include "common.h"

/* localdecomp:start func_003B4730 */
int func_003B4730(char *a) {
    char *p = *(char **)(a + 104);
    int x = *(int *)(p + 192);
    if (x == 0) {
        return 0;
    }
    return *(int *)(p + 76) == x - *(int *)(p + 196);
}
/* localdecomp:end func_003B4730 */
