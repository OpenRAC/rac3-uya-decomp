#include "common.h"

/* localdecomp:start func_00513928 */
extern s32 func_00513928();
extern s32 func_00511E28(void *);
extern void *func_00511BF8();
extern s32 func_00511E28();

typedef struct { s32 a; s32 b; } S_3E3040;
extern S_3E3040 D_001E1660_003E3040[];
extern void *func_00511BF8();
extern s32 func_00511E28();
extern void func_00510D10(void *, s32);
s32 func_00513928(s32 a) {
    S_3E3040 *p = D_001E1660_003E3040;
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_00511BF8(); q = func_00511E28(t); }
    if (q) { func_00510D10(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_00513928 */
