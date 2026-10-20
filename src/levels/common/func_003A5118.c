#include "common.h"
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
    u8 pad8[8];
    void (*f10)(u8 *);
} Tbl_003A5118;
typedef struct {
    u8 pad0[576];
    s32 f240;
    u8 pad244[284];
    s32 ids[10];
    u8 pad388[32];
    s32 f3A8;
} Vars_003A5118;
typedef struct {
    u8 pad0[104];
    Vars_003A5118 *vars;
} Obj_003A5118;
extern u8 *D_001E009C;
extern Tbl_003A5118 *func_00438468(s32, s32);
extern void func_003A5800(Obj_003A5118 *);
extern void func_00436220(Obj_003A5118 *);
void func_003A5118(Obj_003A5118 *o, s32 flag) {
    Vars_003A5118 *v;
    Tbl_003A5118 *t;
    s32 i;
    v = o->vars;
    if (v->f240 != 0) {
        t = func_00438468(6625, 108);
        for (i = 0; i < 10; i++) {
            if (v->ids[i] != -1) {
                t->f10(D_001E009C + v->ids[i] * 256);
                v->ids[i] = -1;
            }
        }
        t->f0(o);
        if (flag != 0) {
            t->f4(o);
        }
    } else if (v->f3A8 != 0) {
        func_003A5800(o);
    } else {
        func_00436220(o);
    }
}
