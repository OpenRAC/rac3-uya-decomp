#include "common.h"

extern char *D_001D67C8;
extern void func_004CE800(char *);

void func_00433568(void) {
    char *v = D_001D67C8;
    if (v != 0) {
        func_004CE800(v + 0x1FCA8);
    }
}
