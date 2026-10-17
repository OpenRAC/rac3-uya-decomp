#include "common.h"
extern void func_004071B0(char *, char *, char *);
void func_003B5280(void *a, char *b, char *c) {
    if (*(int *)(b + 288) == 1) {
        func_004071B0(c, c + 16, c + 240);
    }
}
