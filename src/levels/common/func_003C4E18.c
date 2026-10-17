#include "common.h"
extern int func_003C3E18(char *, char *);
int func_003C4E18(char *m)
{
    char *p = *(char **)(m + 104);
    int v = func_003C3E18(m, p);
    int r = -1;
    if (*(int *)(p + 1724) != v) {
        r = *(int *)(p + 1724);
    }
    return r;
}
