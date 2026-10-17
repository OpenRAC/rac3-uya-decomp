#include "common.h"
typedef int u128_361BA8 __attribute__((mode(TI)));
extern void func_00361BF8(u8 *a0, u128_361BA8 *a1);
extern void func_00361DD8(u8 *a0, u128_361BA8 *a1);
void func_00361BA8(u8 *a0) {
    u128_361BA8 tmp;
    u128_361BA8 *p = *(u128_361BA8 **)(a0 + 104);
    tmp = *p;
    func_00361BF8(a0, &tmp);
    tmp = *p;
    func_00361DD8(a0, &tmp);
}
