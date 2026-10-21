#include "common.h"

/* localdecomp:start func_00460CB8 */
typedef int Q_00460CB8 __attribute__((mode(TI)));
typedef struct {
    Q_00460CB8 v;
    s32 a;
    s32 b;
    s32 c;
    f32 d;
} Sub_00460CB8;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    s32 fC;
    Q_00460CB8 v10;
    Sub_00460CB8 s20;
} Obj_00460CB8;
extern Obj_00460CB8 *func_0045E438(s32);
extern u8 *D_00221138[4];
void func_00460CB8(Q_00460CB8 *v0, Q_00460CB8 *v1, s32 a, s32 b, s32 n, f32 f) {
    Obj_00460CB8 *o;
    Sub_00460CB8 *p;
    if (n != 0) {
        o = func_0045E438(8);
        if (o != 0) {
            p = &o->s20;
            o->v10 = *v0;
            o->f9 = 0xA4;
            o->f3 = 0x48;
            o->f4 = a;
            o->f1 = 0;
            o->fC = 0;
            o->f8 = 0;
            o->f2 = *D_00221138[0];
            p->v = *v1;
            o->fA = n;
            p->d = f / (f32)n;
            p->a = a;
            p->c = n;
            p->b = b;
        }
    }
}
/* localdecomp:end func_00460CB8 */
