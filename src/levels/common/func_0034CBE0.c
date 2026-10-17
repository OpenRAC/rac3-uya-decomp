#include "common.h"

extern void func_003F4540(s32);

void func_0034CBE0(s32 *p) {
    if (*p != -1) {
        func_003F4540(*p);
        *p = -1;
    }
}
