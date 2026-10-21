#include "common.h"

/* localdecomp:start func_00384CB0 */
extern void func_004C4AB8(int);
extern void func_00436220(void *);
void func_00384CB0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_004C4AB8(*(int *)(v + 48));
    }
    func_00436220(m);
}
/* localdecomp:end func_00384CB0 */
