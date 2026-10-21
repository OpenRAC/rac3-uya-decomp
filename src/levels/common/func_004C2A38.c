#include "common.h"

/* localdecomp:start func_004C2A38 */
typedef struct { u32 a, b, c, d; } S_3A4720;
extern S_3A4720 *D_001E10E8_003A4720;
void func_004C2A38(u32 x) {
    S_3A4720 *p = D_001E10E8_003A4720++;
    p->a = x + 0x90000000;
    p->b = 0; p->c = 0; p->d = 0;
}
/* localdecomp:end func_004C2A38 */
