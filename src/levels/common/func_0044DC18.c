#include "common.h"

/* localdecomp:start func_0044DC18 */
extern void func_0040C8E0();

typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0040C8E0(M_3BFAF8 *, void *);
void func_0040C2D0(void *, void *, M_3BFAF8 *);
void func_0044DC18(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_0040C8E0(&m, a + 0xC0); func_0040C2D0(b, c, &m); } else { func_0040C2D0(b, c, d); }
}
/* localdecomp:end func_0044DC18 */
