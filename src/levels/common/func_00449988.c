#include "common.h"

/* localdecomp:start func_00449988 */
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0040C658();
extern void func_0040C8E0();
extern void func_0040C9B0();
extern void func_00447748();
void func_00449988(u8 *p, u128_3BF838 *a1, u128_3BF838 *a2, void *a3) {
    M_3BF838 m0, m1, m2, m3;
    func_0040C658(&m0, a2);
    func_0040C8E0(&m1, &m0);
    func_0040C658(&m2, a3);
    func_0040C9B0(&m3, &m1, &m2);
    func_00447748(&m3, p);
    if (*(s32 *)(p + 0x3C) & 2) {
        *(u128_3BF838 *)(p + 0x20) = *a2;
    }
    *(u128_3BF838 *)(p + 0x10) = *a1;
}
/* localdecomp:end func_00449988 */
