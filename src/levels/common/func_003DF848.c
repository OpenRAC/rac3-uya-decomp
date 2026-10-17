#include "common.h"
extern void func_004C4AB8(int);
extern void func_00436220(void *);
void func_003DF848(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_004C4AB8(*(int *)(v + 40));
    }
    func_00436220(m);
}
