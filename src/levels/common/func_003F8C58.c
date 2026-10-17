#include "common.h"
extern void func_003E5588(char *, char *);
extern void func_003E52E8(char *, void *);
void func_003F8C58(char *a, void *b)
{
    char buf[48];
    func_003E5588(*(char **)(a + 88) + 16, buf);
    func_003E52E8(buf, b);
}
