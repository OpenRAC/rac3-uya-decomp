#include "common.h"

extern char *func_00445F18();
extern void func_003B49A0();

void func_00326F80(int a0) {
    int x = *(int *)(func_00445F18(a0) + 8);
    if (x) {
        func_003B49A0(x, a0);
    }
}
