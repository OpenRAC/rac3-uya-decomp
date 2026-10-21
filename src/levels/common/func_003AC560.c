#include "common.h"

/* localdecomp:start func_003AC560 */
extern char *func_00438488(int, int, int);
void func_003AC560(int a, int b, char *m)
{
    char *v = func_00438488(*(short *)(m + 170), 2, 12);
    (*(void (**)(char *))(v + 8))(m);
}
/* localdecomp:end func_003AC560 */
