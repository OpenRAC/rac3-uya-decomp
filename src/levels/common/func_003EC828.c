#include "common.h"

/* localdecomp:start func_003EC828 */
typedef int u128_3EC828 __attribute__((mode(TI)));
typedef struct { u8 p0[0x200]; u8 b200[0x30]; u128_3EC828 q230; u8 pad[0x460 - 0x240]; } E_3EC828;
typedef struct { u8 p0[0x30]; u128_3EC828 q30; u8 p40[0x54]; s32 w94; } M_3EC828;
extern E_3EC828 D_001E2AC0[];
extern void func_0040BCB8(M_3EC828 *, u8 *, s32);

void func_003EC828(M_3EC828 *m) {
    E_3EC828 *e = &D_001E2AC0[m->w94];
    m->q30 = e->q230;
    func_0040BCB8(m, e->b200, 48);
}
/* localdecomp:end func_003EC828 */
