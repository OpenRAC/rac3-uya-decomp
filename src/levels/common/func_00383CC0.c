#include "common.h"

/* localdecomp:start func_00383CC0 */
typedef unsigned int Q_00383CC0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; float f70; u8 pad2[0xF0 - 0x74]; } E_00383CC0;
extern u8 D_00142657[];
extern E_00383CC0 D_002C5640[];
extern u8 D_001EEB00[];
extern void func_0040BE90(void *, float);
extern s32 func_003FB1D0(void *, float, s32, void *, s32);
extern void func_004445E0(void *, void *, void *, s32, void *, s32, s32, s32, s32, float, float, float);
void func_00383CC0(Q_00383CC0 *p, s32 b, void *r) {
    Q_00383CC0 v10;
    Q_00383CC0 v20;
    float f;
    E_00383CC0 *t;
    s32 res;
    func_0040BE90(&v10, -3.0f);
    t = D_002C5640;
    f = t[D_00142657[0]].f70;
    res = func_003FB1D0(p + 1, 4.0f, 0x10, p, 0);
    v20 = p[1];
    func_004445E0(p, &v20, D_001EEB00, res, r, 0x1010000, 3, 1, -1, f, 4.0f, 6.0f);
}
/* localdecomp:end func_00383CC0 */
