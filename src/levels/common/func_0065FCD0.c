#include "common.h"

/* localdecomp:start func_0065FCD0 */
typedef struct {
    u32 a : 4;
    u32 b : 6;
    u32 c : 3;
    u32 rest : 19;
    s32 f4;
    s32 f8;
    u8 pad[0x50 - 0xC];
    s32 f50;
    u8 f54;
    u8 f55;
} P_65FCD0;
extern s32 D_001A5E58[];
extern P_65FCD0 *func_00660120(void);
extern void func_00660290(P_65FCD0 *, s32, s32);

P_65FCD0 *func_0065FCD0(s32 *src, s32 kind, s32 x, s32 y) {
    P_65FCD0 *p = func_00660120();

    p->a = kind;
    p->f8 = *src;
    p->b = 0;
    p->c = D_001A5E58[0];
    p->f54 = 0;
    p->f50 = -1;
    p->f55 = 1;
    func_00660290(p, x, y);
    return p;
}
/* localdecomp:end func_0065FCD0 */
