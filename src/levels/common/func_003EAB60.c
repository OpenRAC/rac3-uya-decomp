#include "common.h"

/* localdecomp:start func_003EAB60 */
extern char *D_001DF884;
int func_003EAB60(int i) {
    unsigned char *p = *(unsigned char **)(D_001DF884 + i * 32 + 28);
    int r = 0;
    if (p[68]) {
        r = p[57] != 0;
    }
    return r;
}
/* localdecomp:end func_003EAB60 */
