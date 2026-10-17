#include "common.h"

typedef int Q_00530798 __attribute__((mode(TI)));

extern void func_005A9850();

typedef struct {
    char pad[48];
    Q_00530798 q;
} S_00530798;

void func_00530798(int a0, Q_00530798 *a1) {
    S_00530798 s;
    func_005A9850(a0, 14, &s);
    *a1 = s.q;
}
