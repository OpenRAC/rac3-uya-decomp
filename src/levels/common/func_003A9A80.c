#include "common.h"

/* localdecomp:start func_003A9A80 */
typedef int u128_003A9A80 __attribute__((mode(TI)));

typedef struct {
    u8 pad[0x64];
    u8 *w64;
} Moby_003A9A80;

extern void func_0040C638(void *, void *);

void func_003A9A80(u8 *src, Moby_003A9A80 *m) {
    *(u128_003A9A80 *)(m->w64 + 16) = *(u128_003A9A80 *)(src + 16);
    *(u128_003A9A80 *)(m->w64 + 240) = *(u128_003A9A80 *)(src + 240);
    func_0040C638(m->w64 + 192, src + 240);
}
/* localdecomp:end func_003A9A80 */
