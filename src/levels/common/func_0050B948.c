#include "common.h"

/* localdecomp:start func_0050B948 */
typedef struct {
    u8 pad0[3072];
    f32 f3072;
    u8 pad1[9664 - 3076];
    u8 *p9664;
    u8 pad2[10240 - 9668];
    u8 *p10240;
    s32 f10244;
} S_1A4BE0;

extern S_1A4BE0 D_001A4BE0;
extern s32 func_0050B850(s32, void *);

void func_0050B948(void) {
    u8 buf[16];
    S_1A4BE0 *s = &D_001A4BE0;
    if (s->p10240 != 0 && s->f10244 != 0) {
        if (func_0050B850(s->p9664[67], buf) != 0) {
            *(f32 *)(s->p10240 + 72) = s->f3072;
        }
    }
}
/* localdecomp:end func_0050B948 */
