#include "common.h"
extern void *D_001DAAE0;
extern void func_00660170(void *);
void func_00660140(u8 *a0) {
    func_00660170(a0);
    *(void **)(a0 + 88) = D_001DAAE0;
    D_001DAAE0 = a0;
}
