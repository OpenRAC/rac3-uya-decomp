#include "common.h"

/* localdecomp:start func_003C3EA8 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003C3E90(u8 *, u128_t *, u128_t *);
extern void func_0040C638(u8 *, u8 *);
extern void func_0044C1D0(u8 *, u8 *);
extern void func_003C3890(u8 *, u8 *);

void func_003C3EA8(u8 *m, u8 *b, u128_t *pos, u128_t *dir) {
    func_003C3E90(b, pos, dir);
    *(u128_t *)(m + 16) = *pos;
    *(u128_t *)(m + 240) = *dir;
    func_0040C638(m + 192, m + 240);
    func_0044C1D0(m, b + 368);
    func_003C3890(m, b);
}
/* localdecomp:end func_003C3EA8 */
