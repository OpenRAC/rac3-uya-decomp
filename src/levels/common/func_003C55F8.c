#include "common.h"

/* localdecomp:start func_003C55F8 */
typedef struct {
    u8 pad[0xB0];
    s32 v;
} S_003C55F8;
void func_003C55F8(void *a, S_003C55F8 *p) {
    switch (p->v) {
    case 0:
    case 3:
        p->v = 1;
        break;
    case 1:
    case 2:
        break;
    }
}
/* localdecomp:end func_003C55F8 */
