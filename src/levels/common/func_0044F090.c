#include "common.h"

/* localdecomp:start func_0044F090 */
typedef struct {
    u8 p0[0xE];
    u8 b14;
} T_44F090;

extern T_44F090 *func_00440728(void *m);
extern void func_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                          f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                          s32 h, s32 k);

void func_0044F090(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                   f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g) {
    T_44F090 *t = func_00440728(m);

    if (t != 0 && t->b14 == 2) {
        return;
    }
    func_0044ED60(m, a, b, x1, x2, x3, x4, e, x5, x6, f, g, c, d, x0, 1.0f, 0, 3);
}
/* localdecomp:end func_0044F090 */
