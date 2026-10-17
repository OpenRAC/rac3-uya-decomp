#include "common.h"
extern char *D_001DF334;
void func_003E4780(void) {
    char *p = D_001DF334;
    while (p != 0) {
        char *q = *(char **)(p + 104);
        if (*(unsigned char *)(q + 96)) {
            *(int *)(p + 152) = 0;
        }
        p = *(char **)(q + 100);
    }
}
