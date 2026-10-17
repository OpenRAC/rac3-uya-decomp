#include "common.h"
int func_003C4DA8(char *m)
{
    char *p = *(char **)(m + 104);
    int a = *(int *)(p + 1724);
    int c;
    if (a == *(int *)(p + 1712)) {
        return 1;
    }
    c = *(int *)(p + 1720);
    if (c != -1 && a == c) {
        return 1;
    }
    return 0;
}
