#include "common.h"

/* localdecomp:start func_004CB768 */
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
void func_004CB768(V_7FC8 *s, s32 i, f32 x, f32 y) {
    s->a[i] = x; s->b[i] = y;
}
/* localdecomp:end func_004CB768 */
