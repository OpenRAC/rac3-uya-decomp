#include "common.h"

/* localdecomp:start func_004C8C60 */
typedef struct {
    s32 *p0;
    s32 *p4;
    s32 *p8;
    s32 *pC;
    s32 *p10;
    u8 b14, b15, b16, b17, b18;
    u8 pad19[3];
    s32 i1C;
    s32 i20;
} S_4C8C60;
extern s32 func_004C9B50(s32);
extern s32 *func_0051DC40(s32, s32);
extern void func_004C8B28(S_4C8C60 *, s32);

void func_004C8C60(S_4C8C60 *o, s32 a, s32 c) {
    s32 *p;
    s32 t;
    o->i20 = c;
    if (c) {
        p = func_0051DC40(16, func_004C9B50(c));
        t = o->i20;
        o->p0 = p;
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
        p = func_0051DC40(16, func_004C9B50(t));
        t = o->i20;
        o->p8 = p;
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
        p = func_0051DC40(16, func_004C9B50(t));
        t = o->i20;
        o->p4 = p;
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
        p = func_0051DC40(16, func_004C9B50(t));
        t = o->i20;
        o->pC = p;
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
        p = func_0051DC40(16, func_004C9B50(t));
        o->p10 = p;
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
    }
    o->i1C = a;
    o->b17 = 0;
    o->b14 = 0;
    o->b16 = 0;
    o->b15 = 0;
    o->b18 = 0;
    func_004C8B28(o, 1);
}
/* localdecomp:end func_004C8C60 */
