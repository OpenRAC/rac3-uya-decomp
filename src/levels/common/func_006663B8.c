#include "common.h"

/* localdecomp:start func_006663B8 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
} S_6663B8;

extern S_6663B8 D_0033AC08[];

void func_006663B8(s32 i, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    D_0033AC08[i].a = a;
    D_0033AC08[i].b = b;
    D_0033AC08[i].c = c;
    D_0033AC08[i].d = d;
    D_0033AC08[i].e = e;
    D_0033AC08[i].f = f;
    D_0033AC08[i].g = g;
}
/* localdecomp:end func_006663B8 */
