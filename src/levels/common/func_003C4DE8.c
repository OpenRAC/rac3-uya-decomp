#include "common.h"

/* localdecomp:start func_003C4DE8 */
extern int D_001F3FC0[];
int func_003C4DE8(char *a) {
    a = *(char **)(a + 104);
    if (*(int *)(a + 204) == -1) {
        return 0;
    }
    return D_001F3FC0[0] == *(int *)(a + 224);
}
/* localdecomp:end func_003C4DE8 */
