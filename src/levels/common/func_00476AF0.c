#include "common.h"
typedef struct { s32 x0, x4, x8, xC; } S_476AF0;
extern S_476AF0 D_001E1660[];
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00511CE8();
extern s32 func_00510858();
extern void func_00511338(void **, s32, s32);
extern void *func_0051AA28();
extern s32 func_0051DC40();
extern void func_00512468(s32);
extern s32 func_00512470();
s32 func_00476AF0(s32 a) {
    S_476AF0 *p;
    S_476AF0 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001E1660;
    if (!q->x4) q = func_00511BF8();
    obj = func_00511E28(q);
    func_00512468(0x54);
    vv = func_00512470();
    if (obj != 0) {
        if (func_00510858(obj, a) == 0) {
            p = D_001E1660;
            if (p->x4) q = p;
            else q = func_00511BF8(p);
            t1 = func_00511CE8(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_0051AA28(func_0051DC40(0x54, e));
                r = ((s32 (*)())func_00511338)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001E1660;
                    if (p->x4) q = p;
                    else q = func_00511BF8(p);
                    w = func_00511CE8(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
